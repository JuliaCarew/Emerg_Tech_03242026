#include "InteractionLibrary.h"
#include "InteractInterface.h"

bool UInteractionLibrary::TryInteractActor(AActor* Target)
{
	if (!IsValid(Target))
	{
		return false;
	}

	auto TryExecute = [](AActor* Candidate) -> bool
	{
		if (!IsValid(Candidate))
		{
			return false;
		}

		if (!Candidate->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
		{
			return false;
		}

		IInteractInterface::Execute_Interact(Candidate);
		return true;
	};

	// interact with the directly hit actor.
	if (TryExecute(Target))
	{
		return true;
	}

	// if the hit actor is attached under an NPC actor, interact with the parent
	for (AActor* Parent = Target->GetAttachParentActor(); IsValid(Parent); Parent = Parent->GetAttachParentActor())
	{
		if (TryExecute(Parent))
		{
			return true;
		}
	}

	// try ownership chain 
	for (AActor* Owner = Target->GetOwner(); IsValid(Owner); Owner = Owner->GetOwner())
	{
		if (TryExecute(Owner))
		{
			return true;
		}
	}

	{
		return false;
	}
}
