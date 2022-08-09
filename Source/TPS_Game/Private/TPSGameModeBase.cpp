// TPS Game


#include "TPSGameModeBase.h"
#include "Player/TPSBaseCharacter.h"
#include "Player/TPSPlayerController.h"
#include "AIController.h"
#include "Weapon/Projectile.h"
#include "Kismet/GameplayStatics.h"

ATPSGameModeBase::ATPSGameModeBase() 
{
    DefaultPawnClass = ATPSBaseCharacter::StaticClass();
    PlayerControllerClass = ATPSPlayerController::StaticClass();
}

void ATPSGameModeBase::StartPlay() 
{
    Super::StartPlay();

    SpawnBots();

    SpawnBalls();
}

UClass* ATPSGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController) 
{
    if (InController && InController->IsA<AAIController>())
    {
        return AIPawnClass;
    }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
} 

 void ATPSGameModeBase::SpawnBots() 
 {
     if (!GetWorld()) return;

     for (int32 i = 0; i < GameDate.PlayersNum - 1; ++i)
     {
         FActorSpawnParameters SpawnInfo;
         SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        const auto TPSAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);
        RestartPlayer(TPSAIController);
     }
 }

 void ATPSGameModeBase::SpawnBalls() 
 {
     float XCoordinate = FMath::FRandRange(-1000.f, 1000.f);
     float YCoordinate = FMath::FRandRange(-1000.f, 1000.f);

     float Yaw = FMath::FRandRange(0.f, 360.f);
     FVector Location(XCoordinate, YCoordinate, 300.f);
     FRotator Rotatoin(0.f, Yaw, 0.f);
     FActorSpawnParameters p;
     p.Owner = this;

     const FTransform SpawnTransform(Rotatoin, Location);
     auto Projectile = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), ProjectileCllas, SpawnTransform);

     UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);

 }
