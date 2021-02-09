#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <unistd.h>
#include "PlayerWeapon.h"
#include "../Install.h"

PlayerWeapon::PlayerWeapon(shooting_state_t &sS, std::vector<std::string> &imgs):
shootingState(sS),
textureHandler(imgs){}

void PlayerWeapon::setRenderer(SDL_Renderer* renderer){
    textureHandler.setRenderer(renderer);
}

bool PlayerWeapon::estaEnAccion(){
    if(shootingState!=SHOOTING_STATE_QUIET)
        return true;

    return false;
}

void PlayerWeapon::shoot(){
    shootingState = SHOOTING_STATE_STARTED;
}


weapon_t PlayerWeapon::getType(){
    return type;
}

PlayerWeapon::~PlayerWeapon(){}