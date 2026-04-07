#include "NPCCharacter.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"

ANPCCharacter::ANPCCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANPCCharacter::TriggerInteraction()
{
	IInteractInterface::Execute_Interact(this);
}

void ANPCCharacter::RunDialogue()
{
	TriggerInteraction();
}

void ANPCCharacter::Interact_Implementation()
{
	const FString Message = DialogueText.IsEmpty() ? TEXT("...") : DialogueText;

	UE_LOG(LogTemp, Log, TEXT("NPC Interact: %s"), *Message);

	UKismetSystemLibrary::PrintString(this, Message, true, true, FLinearColor::Green, 5.0f);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Green,
			Message);
	}
}
