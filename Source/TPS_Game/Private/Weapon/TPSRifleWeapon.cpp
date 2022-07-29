// TPS Game


#include "Weapon/TPSRifleWeapon.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All);

void ATPSRifleWeapon::StartFire()
{
    UE_LOG(LogBaseWeapon, Display, TEXT("Fire !!!!"));

    MakeShot();
    GetWorldTimerManager().SetTimer(ShotTimerHandle, this, &ATPSRifleWeapon::MakeShot, TimerBetweenShots, true);
}
void ATPSRifleWeapon::StopFire()
{
    UE_LOG(LogBaseWeapon, Display, TEXT("Stop !!!!"));
    GetWorldTimerManager().ClearTimer(ShotTimerHandle);
    MakeShot();
}

void ATPSRifleWeapon::MakeShot()
{
    if (!GetWorld() || IsAmmoEmty())
    {
        StopFire();
        return;
    }

    const FTransform SocketTransform = WeaponMesh->GetSocketTransform(MuzzleSocketName);
    const FVector TraceStart = SocketTransform.GetLocation();
    const FVector ShootDirection = SocketTransform.GetRotation().GetForwardVector();
    const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistancr;
    DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

    if (HitResult.bBlockingHit)
    {
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
    }

    DecreaseAmmo();
}