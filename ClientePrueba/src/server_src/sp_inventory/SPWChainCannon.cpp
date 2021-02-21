#include "SPWChainCannon.h"

SPWChainCannon::SPWChainCannon(){
    type=CHAIN_CANNON;
    before = std::chrono::high_resolution_clock::now();
    damage = CHAIN_CANNON_DAMAGE;

}

SPWChainCannon::~SPWChainCannon(){}


float SPWChainCannon::shoot(shooting_state_t &shootingState, bool &shootMissile){
    shootMissile = false;
    now = std::chrono::high_resolution_clock::now();
    auto waited = std::chrono::duration_cast<std::chrono::milliseconds>(now - before);
    shootingState = SHOOTING_STATE_SHOOTING;
    if(waited.count() < CHAIN_CANNON_WAIT_TIME)
        return 0;

    before = now;
    return damage;

}
