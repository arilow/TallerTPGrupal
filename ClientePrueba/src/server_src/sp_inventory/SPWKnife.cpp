#include "SPWKnife.h"



SPWKnife::SPWKnife(){
    type=KNIFE;
    damage=KNIFE_DAMAGE;
    before = std::chrono::high_resolution_clock::now();
}
SPWKnife::~SPWKnife(){}

float SPWKnife::shoot(float dist, shooting_state_t &shootingState){
    std::cout<<"disparo con cuchillo"<<std::endl;   

    if(shooting == false){
        shootingState = SHOOTING_STATE_QUIET;
        return 0;
    }

    now = std::chrono::high_resolution_clock::now();
    auto waited = std::chrono::duration_cast<std::chrono::milliseconds>(now - before);
    if(waited.count()<KNIFE_WAIT_TIME){
//        shootingState = SHOOTING_STATE_QUIET;
        return 0;
    }

    before=now;
    std::cout<<"disparo con pistola"<<std::endl;   
    shooting=false;
    return damage;
}