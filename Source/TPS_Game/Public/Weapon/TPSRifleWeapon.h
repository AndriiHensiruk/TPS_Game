// TPS Game

#pragma once

#include "CoreMinimal.h"
#include "Weapon/TPSBaseWeapon.h"
#include "TPSRifleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TPS_GAME_API ATPSRifleWeapon : public ATPSBaseWeapon
{
	GENERATED_BODY()

public:
 
    virtual void StartFire();
    virtual void StopFire();

protected:
    virtual void MakeShot() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float TimerBetweenShots = 0.1f;

private:
    FTimerHandle ShotTimerHandle;
};
