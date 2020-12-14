// Fill out your copyright notice in the Description page of Project Settings.


#include "Sandbox/PawnClass/BasePawn.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Containers/StringView.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Capsule->SetupAttachment(RootComponent);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->bAllowCullDistanceVolume = false;
}
PRAGMA_DISABLE_OPTIMIZATION
// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();

	FStringView TestView(TEXT("TestView"));
	auto Char = TestView.Left(4).Data();
	UE_LOG(LogTemp, Log, TEXT("LeftView: %s - Length: %d"),Char,TestView.Len());
	Char = TestView.Right(4).Data();
	UE_LOG(LogTemp, Log, TEXT("RightView: %s - Length: %d"), Char, TestView.Len());
	
}
PRAGMA_ENABLE_OPTIMIZATION
// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

