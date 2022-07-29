// TPS Game


#include "Components/TPSHealthComponent.h"
#include "GameFramework/Actor.h"


DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

UTPSHealthComponent::UTPSHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

}


void UTPSHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UTPSHealthComponent::OnTakeAnyDamage);
    }
}

void UTPSHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead()) return;
    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

    if (IsDead())
    { 
        OnDeath.Broadcast();
    }

   // UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);

    
}


