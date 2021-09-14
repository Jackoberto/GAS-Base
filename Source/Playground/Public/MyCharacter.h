// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

//----------------------------------------------------------------------------------------------------------------------
// FORWARD DECLARATIONS
//----------------------------------------------------------------------------------------------------------------------

class UAbilitySystemComponent;
class UGameplayAbility;

//----------------------------------------------------------------------------------------------------------------------
// CLASS START
//----------------------------------------------------------------------------------------------------------------------
UCLASS(Blueprintable)
class PLAYGROUND_API AMyCharacter : public ACharacter, public IAbilitySystemInterface {

	GENERATED_BODY()

	AMyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

public:

//----------------------------------------------------------------------------------------------------------------------
// PROPERTIES
//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
	
//----------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category="Abilities")
	void GrantAbility(TSubclassOf<UGameplayAbility> GameplayAbility, int Level);
};
