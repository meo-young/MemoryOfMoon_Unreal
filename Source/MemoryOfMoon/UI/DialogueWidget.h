#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

class UImage;
class UTextBlock;

UCLASS()
class MEMORYOFMOON_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ShowDialogueWidget(const FString& InCharacterEmotion, const FString& InCharacterName, const FString& InDialogue);
	void HideDialogueWidget();
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_CharacterSprite;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Arrow;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_CharacterName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Dialogue;
	
};
