#pragma once

#include "CoreMinimal.h"
#include "LevelSequenceActor.h"
#include "MainLevelSequenceActor.generated.h"

class ULevelSequence;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSequenceStartedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSequencePausedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSequenceStoppedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSequenceEndedDelegate);

UCLASS()
class MEMORYOFMOON_API AMainLevelSequenceActor : public ALevelSequenceActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
public:
	FOnSequenceStartedDelegate OnSequenceStartedDelegate;
	FOnSequencePausedDelegate OnSequencePausedDelegate;
	FOnSequenceStoppedDelegate OnSequenceStoppedDelegate;
	FOnSequenceEndedDelegate OnSequenceEndedDelegate;
	
public:
	/** 등록된 LevelSequence를 재생하는 함수 */
	UFUNCTION(BlueprintCallable)
	void PlayLevelSequence();

	/** 등록된 LevelSequence를 잠시 중단하는 함수 */
	UFUNCTION(BlueprintCallable)
	void PauseLevelSequence();

	/** 등록된 LevelSequence를 아예 끝내버리는 함수 */
	UFUNCTION(BlueprintCallable)
	void StopLevelSequence();
	
	/** LevelSequence의 종료 델리게이트에 바인딩할 함수 */
	UFUNCTION(BlueprintCallable)
	void OnSequenceEnded();

private:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	ULevelSequence* LevelSequence;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	ULevelSequencePlayer* LevelSequencePlayer;
	
};
