#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractionLibrary.generated.h"

UCLASS()
class EMERG_TECH_03242026_API UInteractionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Calls Interact on Target if it implements IInteractInterface. Search: "Emerg Try Interact" or "Try Interact". */
	UFUNCTION(BlueprintCallable, Category = "Emerg Tech|Interaction", meta = (DisplayName = "Try Interact Actor", Keywords = "emerg interact dialogue npc library"))
	static bool TryInteractActor(AActor* Target);
};
