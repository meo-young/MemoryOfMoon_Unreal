#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueManager.generated.h"

struct FDialogueData;

UCLASS()
class MEMORYOFMOON_API UDialogueManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UDialogueManager();

private:
	UPROPERTY()
	UDataTable* PrologueDialogue;

	UPROPERTY()
	UDataTable* ChapterOneDialogue;

	UPROPERTY()
	UDataTable* ChapterTwoDialogue;

public:
	FDialogueData* GetDialogueData(const uint8& ID) const;
	
};
