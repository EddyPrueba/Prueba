// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveJugadorPlayerController.h"
#include "NaveJugadorPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "NaveJugador.h"

ANaveJugadorPlayerController::ANaveJugadorPlayerController()
{
}

void ANaveJugadorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);

	InputComponent->BindAxis("Move", this, &ANaveJugadorPlayerController::Move);
	InputComponent->BindAxis("MoveV", this, &ANaveJugadorPlayerController::MoveV);
}

void ANaveJugadorPlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void ANaveJugadorPlayerController::Move(float _AxisValue)
{
	auto MyPawn = Cast<ANaveJugador>(GetPawn());

	if (MyPawn) {
		MyPawn->Move(_AxisValue);
	}
}

void ANaveJugadorPlayerController::MoveV(float _ZAxisValue)
{
	auto MyPawn = Cast<ANaveJugador>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveV(_ZAxisValue);
	}
}
