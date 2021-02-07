#include "CollectHeal.h"

CollectHeal::CollectHeal(int xI, int yI, int cellWidth, int h):
Collectible(xI, yI, cellWidth){
    // weapon= (weapon_t) w;
    type=(heal_t) h;

    if(type == BLOOD)
        heal = HEAL_BLOOD;
    else if(type == FOOD)
        heal = HEAL_FOOD;
    else if(type==MEDICAL_EQUIPMENT)
        heal=HEAL_MEDICAL_EQUIPMENT;
    else 
        heal=0;
}

int CollectHeal::collide(ServerPlayer &p){
    std::cout<<"colision cura"<<std::endl;

    return (int)p.heal(heal)+HEAL_OFFSET;
}

CollectHeal::~CollectHeal(){}

