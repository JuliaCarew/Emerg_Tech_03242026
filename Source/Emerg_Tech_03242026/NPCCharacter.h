#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractInterface.h"
#include "NPCCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class EMERG_TECH_03242026_API ANPCCharacter : public ACharacter, public IInteractInterface
{
	GENERATED_BODY()

public:
	ANPCCharacter();

	UFUNCTION(BlueprintCallable, Category = "Emerg Tech|Interaction", meta = (DisplayName = "Trigger Interaction", Keywords = "emerg interact dialogue npc"))
	void TriggerInteraction();

	UFUNCTION(BlueprintCallable, Category = "Emerg Tech|Dialogue", meta = (DisplayName = "Run Dialogue", Keywords = "emerg interact dialogue npc"))
	void RunDialogue();

	virtual void Interact_Implementation() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FString DialogueText = TEXT("Hello traveler!");
};
