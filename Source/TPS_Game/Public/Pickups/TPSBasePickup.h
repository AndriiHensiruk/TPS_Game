// TPS Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSBasePickup.generated.h"

class USphereComponent;  

UCLASS()
class TPS_GAME_API ATPSBasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATPSBasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
