// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forwards/backwards input
	void MoveForward(float Value);

	// Called for side to side input
	void MoveRight(float Value);

	/* 
	 * Called via input to turn at a given rate
	 * @param Rate This is a normalized rate, i.e 1.0 = 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/* 
	 * Called via input to look up and down at a given rate
	 * @param Rate This is a normalized rate, i.e 1.0 = 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/* Called when the Fire Button is pressed */
	void FireWeapon();

<<<<<<< Updated upstream
=======
	bool GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation) const;

	// Set bAiming to true or false with a button press
	void AimingButtonPressed();
	void AimingButtonReleased();

	// Interpolate the camera field of view depending on aiming status
	void CameraInterpZoom(float DeltaTime);

	// Change look sensitivity based on aiming
	void SetLookRates();
	void CalcCrosshairVelocityFactor();
	void CalcCrosshairInAirFactor(float DeltaTime);
	void CalcCrosshairAimFactor(float DeltaTime);
	void CalcCrosshairShootingFactor(float DeltaTime);

	void CalculateCrosshairSpread(float DeltaTime);

	UFUNCTION()
	void FinishCrosshairBulletFire();

	void StartCrosshairBulletFire();

	void FireButtonPressed();
	void FireButtonReleased();

	void StartFireTimer();

	UFUNCTION()
	void AutoFireReset();

	bool TraceUnderCrosshairs(FHitResult& OutHitResult, FVector& OutHitLocation) const;
	void TraceForItems();

	/* Spawns a default weapon and equips it */
	class AWeapon* SpawnDefaultWeapon() const;

	/* Takes a weapon and attaches it to the mesh */
	void EquipWeapon(class AWeapon* WeaponToEquip);

	/* Detach weapon and let it fall to the ground */
	void DropWeapon() const;

	void SelectButtonPressed();
	void SelectButtonReleased();

	/* Drops equipped weapon and equips TraceHitItem */
	void SwapWeapon(AWeapon* WeaponToSwapTo);

	FVector CalculateItemInterpToLocation() const;

>>>>>>> Stashed changes
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Base turn rate in degrees/second. Other scaling may affect final turn rate.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	// Base look up/down rate in degrees/second. Other scaling may affect final turn rate.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	/* Montage animation for firing the weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* HipFireMontage;

	/* Randomized gunshot sound cue */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	/* Flash spawned at BarrelSocket */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	/* Particles spawned at Impact location of bullet */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactParticles;

	/* Smoke trail spawned for bullets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;

<<<<<<< Updated upstream
public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
=======
	/* True when aiming */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	/* Default camera field of view value */
	float CameraDefaultFOV;

	/* Camera field of view value when zoomed in */
	float CameraZoomedFOV;

	/* Current field of view value at any frame */
	float CurrentCameraFOV;

	/* Interp speed for zooming when aiming */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float ZoomInterpSpeed;

	/* Determines the spread of the crosshairs */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadMultiplier;

	/* Velocity component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairVelocityFactor;

	/* In air component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairInAirFactor;

	/* Aim component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairAimFactor;

	/* Shooting component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairShootingFactor;

	/* Bullet fire time for crosshair spreading */
	float ShootTimeDuration;

	/* Are we firing a bullet */
	bool bFiringBullet;

	/* Timer for resetting bFiringBullet status */
	FTimerHandle CrosshairShootTimer;

	bool bFireButtonPressed;

	/* True when the character is allowed to fire */
	bool bShouldFire;

	/* Rate of automatic gunfire */
	float AutomaticFireRate;

	/* Sets a timer between gunshots */
	FTimerHandle AutoFireTimer;

	/* True if we should trace for items */
	bool bShouldTraceForItems;

	/* Stores the number of overlapped AItems */
	int8 OverlappedItemCount;

	/* Last traced item */
	UPROPERTY()
	class AItem* LastTracedItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	AWeapon* EquippedWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeapon> DefaultWeaponClass;

	/* The item current hit by the trace in TraceForItems (could be null) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	AItem* TraceHitItem;

	/* Distance from the camera for the interp destination of item interpolation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items", meta = (AllowPrivateAccess = "true"))
	float ItemInterpDistanceFromCamera;

	/* Distance from the camera for the interp destination of item interpolation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items", meta = (AllowPrivateAccess = "true"))
	float ItemInterpDistanceAboveCamera;

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE bool GetAiming() const { return bAiming; }
	FORCEINLINE int8 GetOverlappedItemCount() const { return OverlappedItemCount; }

	/* Adds or subtracts OverLappedItemCount and updates bShouldTraceForItems */
	void IncrementOverlappedItemCount(int8 Amount);

	UFUNCTION(BlueprintCallable)
	float GetCrosshairSpreadMultiplier() const;

	void GetPickupItem(AItem* Item);
>>>>>>> Stashed changes
};
