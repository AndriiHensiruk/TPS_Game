// TPS Game


#include "Pickups/TPSBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, All, All);


// Sets default values
ATPSBasePickup::ATPSBasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);

}

// Called when the game starts or when spawned
void ATPSBasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPSBasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATPSBasePickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    UE_LOG(LogBasePickup, Display, TEXT("Pickup was taken"));
   
    Destroy();
}