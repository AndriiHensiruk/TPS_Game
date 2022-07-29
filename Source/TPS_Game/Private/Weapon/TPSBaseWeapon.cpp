// TPS Game


#include "Weapon/TPSBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All);

ATPSBaseWeapon::ATPSBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ATPSBaseWeapon::BeginPlay()
{
	Super::BeginPlay();

    check(WeaponMesh);
    CurrentAmmo = DefaultAmmo;
}

void ATPSBaseWeapon::StartFire()
{
   
}
void ATPSBaseWeapon::StopFire()
{
  
}

void ATPSBaseWeapon::MakeShot() 
{
   
}

void ATPSBaseWeapon::DecreaseAmmo()
{
    CurrentAmmo.Bullets--;
    LogAmmo();

    if (IsClipEmpty() && !IsAmmoEmty())
    {
        ChangeClip();
    }
}
bool ATPSBaseWeapon::IsAmmoEmty() const 
{
    return !CurrentAmmo.Infinite && CurrentAmmo.Clips == 0 && IsClipEmpty();
}

bool ATPSBaseWeapon::IsClipEmpty() const
{
    return CurrentAmmo.Bullets == 0;
}
void ATPSBaseWeapon::ChangeClip()
{
    CurrentAmmo.Bullets = DefaultAmmo.Bullets;
    if (!CurrentAmmo.Infinite)
    {
        CurrentAmmo.Clips--;
    }
    UE_LOG(LogBaseWeapon, Display, TEXT("--------Change Clip--------"));
}

void ATPSBaseWeapon::LogAmmo()
{
    FString AmmoInfo = "Ammo: " + FString::FromInt(CurrentAmmo.Bullets) + " / ";
    AmmoInfo += CurrentAmmo.Infinite ? "Infinite" : FString::FromInt(CurrentAmmo.Clips);
    UE_LOG(LogBaseWeapon, Display, TEXT("%s"), *AmmoInfo);
}