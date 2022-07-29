// TPS Game


#include "TPSGameModeBase.h"
#include "Player/TPSBaseCharacter.h"
#include "Player/TPSPlayerController.h"

ATPSGameModeBase::ATPSGameModeBase() 
{
    DefaultPawnClass = ATPSBaseCharacter::StaticClass();
    PlayerControllerClass = ATPSPlayerController::StaticClass();
}
