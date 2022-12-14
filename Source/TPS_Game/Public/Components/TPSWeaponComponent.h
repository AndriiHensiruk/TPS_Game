// TPS Game

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPSWeaponComponent.generated.h"

class ATPSBaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPS_GAME_API UTPSWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UTPSWeaponComponent();

	void StartFire();
    void StopFire();

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ATPSBaseWeapon> WaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";

	virtual void BeginPlay() override;

private:

    UPROPERTY()
    ATPSBaseWeapon* CurrrentWeapon = nullptr;

    void SpawnWeapon();
};
