#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FDialogueData.generated.h"

USTRUCT(BlueprintType)
struct FDialogueData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FDialogueData()
	{
		Character = TEXT("");
		Sprite = TEXT("");
		Dialogue = TEXT("");
		NextIndex = 0;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FString Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FString Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FString Dialogue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	int32 NextIndex;
	
};
