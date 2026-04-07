#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class EMERG_TECH_03242026_API IInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void Interact();
};
