// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEMECHANICS1_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UHealthComponent();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ResetHealth();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int m_MaxHealth;

	UFUNCTION(BlueprintCallable, Category = "Health")
	int GetHealthPercentage() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool IsDead() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void DoDamage(int amount);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeathSignature OnDeath;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageSignature, float, DamageAmount);
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDamageSignature OnDamage;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int m_CurrentHealth;
	bool m_IsDying;

private:

};
