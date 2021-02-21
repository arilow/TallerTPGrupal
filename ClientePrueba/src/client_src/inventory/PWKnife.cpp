#include "PWKnife.h"

std::vector<std::string> PWKnifeSprites={
    "Media/WeaponSprites/PWKnife0.png",
    "Media/WeaponSprites/PWKnife1.png",
    "Media/WeaponSprites/PWKnife2.png",
    "Media/WeaponSprites/PWKnife3.png",
    "Media/WeaponSprites/PWKnife4.png"
};


PWKnife::PWKnife(shooting_state_t &sS):
PlayerWeapon(sS, PWKnifeSprites){
    type = KNIFE;
    frameTime = KNIFE_FRAME_TIME;
}

void PWKnife::render(int largoWin, int altoWin){
    int frame = 0;
    now = std::chrono::high_resolution_clock::now();
    auto waited = std::chrono::duration_cast<std::chrono::milliseconds>(now - before);

    if(shootingState == SHOOTING_STATE_WAIT && numAuxiliar==0)
        frame = 0;
    else if (shootingState!=SHOOTING_STATE_QUIET || numAuxiliar!=0){
        if(waited.count()>=frameTime){
            numAuxiliar++;
            before=now;
        }
        frame = numAuxiliar;

        if (!soundOn){
            gunSounds.playEffect(KNIFE_STAB, 20);
            soundOn = true;
        }

        if (frame > 4){
             numAuxiliar = 0;
             frame = 0;
             soundOn = false;
             shootingState=SHOOTING_STATE_WAIT;
        }
    }
    textureHandler.render(posXWeapon, posYWeapon, GUNL, GUNA, frame);
}


PWKnife::~PWKnife(){}
