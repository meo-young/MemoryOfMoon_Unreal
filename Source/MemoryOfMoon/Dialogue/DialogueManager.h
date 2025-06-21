#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueManager.generated.h"

class UDialogueWidget;
struct FDialogueData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogueEvent);

UCLASS(Blueprintable, BlueprintType)
class MEMORYOFMOON_API UDialogueManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UDialogueManager();

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDialogueEvent OnDialogueEventDelegate;

public:
	UFUNCTION(BlueprintCallable)
	void ShowDialogue();

private:
	void CreateDialogueWidgetInstance();

private:
	UPROPERTY()
	TObjectPtr<UDialogueWidget> DialogueWidgetInstance;
	
	UPROPERTY()
	TSubclassOf<UDialogueWidget> DialogueWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UDataTable> PrologueDialogue;

	UPROPERTY()
	TObjectPtr<UDataTable> ChapterOneDialogue;

	UPROPERTY()
	TObjectPtr<UDataTable> ChapterTwoDialogue;

	UPROPERTY()
	uint8 CurrentDialogueCounter = 0;

public:
	FDialogueData* GetDialogueData(const uint8& ID) const;
	
};
