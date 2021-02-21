#include "SPWGun.h"

SPWGun::SPWGun(){
    type=GUN;
    before = std::chrono::high_resolution_clock::now();
    damage = GUN_DAMAGE;
}
SPWGun::~SPWGun(){}

float SPWGun::shoot(shooting_state_t &shootingState, bool &shootMissile){
    shootMissile = false;
    if(shooting == false){
        shootingState = SHOOTING_STATE_QUIET;
        return 0;
    }

    now = std::chrono::high_resolution_clock::now();
    auto waited = std::chrono::duration_cast<std::chrono::milliseconds>(now - before);
    if(waited.count()<GUN_WAIT_TIME){
//        shootingState = SHOOTING_STATE_QUIET;
        return 0;
    }

    before=now;
    shooting=false;
    return damage;
}
