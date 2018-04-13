// Copyright Brian Walsh (c) 2018

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"	// Put new includes above

// Forward declarations
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();


private:	
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")	//Change from EditAnywhere
	//UClass*
	TSubclassOf<AProjectile> ProjectileBlueprint;	//Alternative http://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// Local barrel reference to spawn projectile
	UTankBarrel* Barrel = nullptr;	// TODO remove

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 40000;

	double LastFireTime = 0;
};
