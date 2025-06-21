#include "UI/DialogueWidget.h"
#include "MemoryOfMoon.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UDialogueWidget::ShowDialogueWidget(const FString& InCharacterEmotion, const FString& InCharacterName, const FString& InDialogue)
{
	if (IsValid(Image_CharacterSprite))
	{
		// 캐릭터 이름의 공백을 제거한다.
		const FString TrimmedCharacterName = InCharacterName.Replace(TEXT(" "), TEXT(""));

		// 경로 생성: /Game/PaperAssets/Illust/캐릭터이름/T_캐릭터이름_감정
		const FString TexturePath = FString::Printf(TEXT("/Game/PaperAssets/Illust/%s/T_%s_%s"), 
											*TrimmedCharacterName, 
											*TrimmedCharacterName, 
											*InCharacterEmotion);

		// 경로로 텍스처를 로드한다.
		UTexture2D* CharacterSpriteImage = LoadObject<UTexture2D>(nullptr, *TexturePath);
		if (!IsValid(CharacterSpriteImage)) return;

		// 로드에 성공한 경우 UI에 출력한다.
		Image_CharacterSprite->SetBrushFromTexture(CharacterSpriteImage);
	}

	if (IsValid(Text_CharacterName))
	{
		Text_CharacterName->SetText(FText::FromString(InCharacterName));	
	}

	if (IsValid(Text_Dialogue))
	{
		Text_Dialogue->SetText(FText::FromString(InDialogue));
	}

	if (!IsInViewport())
	{
		AddToViewport();	
	}
}

void UDialogueWidget::HideDialogueWidget()
{
	if (IsInViewport())
	{
		RemoveFromParent();
	}
}
