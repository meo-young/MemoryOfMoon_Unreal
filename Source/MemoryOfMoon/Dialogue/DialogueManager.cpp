#include "Dialogue/DialogueManager.h"
#include "Dialogue/FDialogueData.h"

UDialogueManager::UDialogueManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_Prologue(TEXT("/Game/CSV/Prologue/Prologue"));
	if (DT_Prologue.Succeeded())
	{
		PrologueDialogue = DT_Prologue.Object;
	}
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
