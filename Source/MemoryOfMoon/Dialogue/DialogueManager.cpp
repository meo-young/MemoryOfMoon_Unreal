#include "Dialogue/DialogueManager.h"

#include "MemoryOfMoon.h"
#include "Dialogue/FDialogueData.h"
#include "UI/DialogueWidget.h"

UDialogueManager::UDialogueManager()
{
	static ConstructorHelpers::FClassFinder<UDialogueWidget> WBP_DialogueWidget(TEXT("/Game/HUD/WBP_Dialogue"));
	if (WBP_DialogueWidget.Succeeded())
	{
		DialogueWidgetClass = WBP_DialogueWidget.Class;
	}
	
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_Prologue(TEXT("/Game/CSV/Prologue/Prologue"));
	if (DT_Prologue.Succeeded())
	{
		PrologueDialogue = DT_Prologue.Object;
	}
}

void UDialogueManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UDialogueManager::ShowDialogue()
{
	if (!IsValid(DialogueWidgetInstance))
	{
		CreateDialogueWidgetInstance();
	}
	
	if (OnDialogueEventDelegate.IsBound())
	{
		OnDialogueEventDelegate.Broadcast();
	}

	// 현재 대화 카운트에 해당하는 대사 데이터를 가져온다.
	const FDialogueData* DialogueData = GetDialogueData(CurrentDialogueCounter);
	if (!DialogueData) return;
	
	// 대사 데이터를 DialogueWidgetInstance에 전달하여 UI로 출력한다.
	if (!IsValid(DialogueWidgetInstance)) return;

	DialogueWidgetInstance->ShowDialogueWidget(DialogueData->Sprite, DialogueData->Character, DialogueData->Dialogue);

	// 대사 카운트를 1만큼 증가시킨다.
	++CurrentDialogueCounter;
}

void UDialogueManager::CreateDialogueWidgetInstance()
{
	// 플레이어 컨트롤러, DialogueWidgetClass가 유효하지 않으면 함수를 종료한다.
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(DialogueWidgetClass) || !IsValid(PlayerController)) return;
	
	// DialogueWidgetInstance가 유효하지 않으면 새로 생성한다.
	DialogueWidgetInstance = CreateWidget<UDialogueWidget>(PlayerController, DialogueWidgetClass);
}

FDialogueData* UDialogueManager::GetDialogueData(const uint8& ID) const
{
	// 현재 레벨의 이름을 토대로 DialogueData를 반환한다.
	// 이름이 잘못되어있는 경우 문제가 발생하지만, 해당 상황은 배제한다.
	
	const FString CurrentLevelName = GetWorld()->GetMapName();
	
	if (CurrentLevelName.Contains(TEXT("Prologue")))
	{
		if (IsValid(PrologueDialogue))
		{
			return PrologueDialogue->FindRow<FDialogueData>(*FString::FromInt(ID), TEXT(""));	
		}
	}

	if (CurrentLevelName.Contains(TEXT("Chapter1")))
	{
		if (IsValid(ChapterOneDialogue))
		{
			return ChapterOneDialogue->FindRow<FDialogueData>(*FString::FromInt(ID), TEXT(""));	
		}
	}
	
	if (CurrentLevelName.Contains(TEXT("Chapter2")))
	{
		if (IsValid(ChapterTwoDialogue))
		{
			return ChapterTwoDialogue->FindRow<FDialogueData>(*FString::FromInt(ID), TEXT(""));	
		}
	}

	return nullptr;
}
