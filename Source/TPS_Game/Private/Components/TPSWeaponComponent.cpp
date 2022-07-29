// TPS Game


#include "Components/TPSWeaponComponent.h"
#include "Weapon/TPSBaseWeapon.h"
#include "GameFramework/Character.h"

UTPSWeaponComponent::UTPSWeaponComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UTPSWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UTPSWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    CurrrentWeapon = GetWorld()->SpawnActor<ATPSBaseWeapon>(WaponClass);
    if (!CurrrentWeapon) return;
   
     FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
     CurrrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
    
}

void UTPSWeaponComponent::StartFire()
{
    if (!CurrrentWeapon) return;
    CurrrentWeapon->StartFire();

}void UTPSWeaponComponent::StopFire()
{
    if (!CurrrentWeapon) return;
    CurrrentWeapon->StopFire();
}