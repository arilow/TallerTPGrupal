#include "PWChainCannon.h"

std::vector<std::string> PWChainCannonSprites={
    "Media/WeaponSprites/PWChainCanon0.png",
    "Media/WeaponSprites/PWChainCanon1.png",
    "Media/WeaponSprites/PWChainCanon2.png",
    "Media/WeaponSprites/PWChainCanon3.png",
    "Media/WeaponSprites/PWChainCanon4.png"
};


PWChainCannon::PWChainCannon(shooting_state_t &sS):
PlayerWeapon(sS, PWChainCannonSprites){
    type=CHAIN_CANNON;
}

void PWChainCannon::render(int posX, int posY){
    int delay = 10;
    int frame = 0;


    if (shootingState != SHOOTING_STATE_QUIET && shootingState != SHOOTING_STATE_STOPED){
        numAuxiliar++;
        frame = numAuxiliar/ delay;

         if (frame > 4){
             numAuxiliar = 0;
             frame = 0;
             shootingState=SHOOTING_STATE_QUIET;
        }
    }
    textureHandler.render(96, 72, GUNL, GUNA, frame);

    // std::cout<<"render CHAIN CANNON"<<std::endl;
}


PWChainCannon::~PWChainCannon(){}