// TPS Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPSCoreTypes.h"
#include "TPSGameModeBase.generated.h"

class AAIController;
class AProjectile;
/**
 * 
 */
UCLASS()
class TPS_GAME_API ATPSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
    ATPSGameModeBase();

    virtual void StartPlay() override;
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override; 

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameDate;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ball")
    TSubclassOf<AProjectile> ProjectileCllas;

private:
    void SpawnBots();
    void SpawnBalls();
};
