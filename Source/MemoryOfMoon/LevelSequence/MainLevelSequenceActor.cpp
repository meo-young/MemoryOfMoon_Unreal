#include "LevelSequence/MainLevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MemoryOfMoon.h"

void AMainLevelSequenceActor::BeginPlay()
{
	Super::BeginPlay();

	// 등록된 레벨 시퀀스를 추출한다.
	LevelSequence = GetSequence();
	if (!IsValid(LevelSequence))
	{
		LOG(TEXT("LevelSequence Is Not Valid !"));
		return;
	}

	// 재생 전에 레벨 시퀀스 플레이어를 변수화 해야 종료 델리게이트에서 활용할 수 있다.
	ALevelSequenceActor* OutActor;
	LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), LevelSequence, FMovieSceneSequencePlaybackSettings(), OutActor);

	// 종료 델리게이트에 함수를 바인딩한다.
	LevelSequencePlayer->OnFinished.AddDynamic(this, &AMainLevelSequenceActor::OnSequenceEnded);
}

void AMainLevelSequenceActor::PlayLevelSequence()
{
	LOG(TEXT("%s Sequence Started !"), *LevelSequence->GetName());

	if (OnSequenceStartedDelegate.IsBound())
	{
		OnSequenceStartedDelegate.Broadcast();
	}

	LevelSequencePlayer->Play();
}

void AMainLevelSequenceActor::PauseLevelSequence()
{
	LOG(TEXT("%s Sequence Paused !"), *LevelSequence->GetName());

	if (OnSequencePausedDelegate.IsBound())
	{
		OnSequencePausedDelegate.Broadcast();
	}

	LevelSequencePlayer->Pause();
}

void AMainLevelSequenceActor::StopLevelSequence()
{
	LOG(TEXT("%s Sequence Stopped !"), *LevelSequence->GetName());

	if (OnSequenceStoppedDelegate.IsBound())
	{
		OnSequenceStoppedDelegate.Broadcast();
	}

	LevelSequencePlayer->Stop();
}

void AMainLevelSequenceActor::OnSequenceEnded()
{
	LOG(TEXT("%s Sequence Ended !"), *LevelSequence->GetName());

	if (OnSequenceEndedDelegate.IsBound())
	{
		OnSequenceEndedDelegate.Broadcast();
	}
}
