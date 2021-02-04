#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <unistd.h>
#include "Enemies.h"
#include "Install.h"

Enemies::Enemies(): EnemiesHandler(EnemiesSprites){
}

void Enemies::setRenderer(SDL_Renderer* renderer){
    EnemiesHandler.setRenderer(renderer);
}

void Enemies::setAngle(int angle){
    angleEnemy = angle;
}

void Enemies::defineSprite(Player_t enemy, Vector &posPlayer, int &sprite){
    std::cout<<"----------------------------------------------------------------- "<<std::endl;

    Vector enemyPos(enemy.x, enemy.y);
    // float auxAngle=enemyPos.getAngle(posPlayer)*180/3.1415;

    float auxAngle=enemyPos.getAngle(posPlayer);

    if(auxAngle>=2*PI)
        auxAngle-=2*PI;
    if(auxAngle<0)
        auxAngle+=2*PI;

    float angleDif = (enemy.ang-auxAngle);

    if(angleDif>=2*PI)
        angleDif-=2*PI;
    if(angleDif<0)
        angleDif+=2*PI;

    angleDif=angleDif*180/PI;

    if (angleDif <= 22.5 && angleDif >= 0||angleDif <=360 && angleDif >337.5){
        sprite = 0;
    } else if (angleDif > 22.5 && angleDif <= 67.5){
        sprite = 1;
    } else if (angleDif > 67.5 && angleDif <= 112.5){
        sprite = 2;
    } else if (angleDif > 112.5 && angleDif <= 157.5){
        sprite = 3;
    } else if (angleDif > 157.5 && angleDif <= 202.5){
        sprite = 4;
    } else if (angleDif > 202.5 && angleDif <= 247.5){
        sprite = 5;
    } else if (angleDif > 247.5 && angleDif <= 292.5){
        sprite = 6;
    } else if (angleDif > 292.5  && angleDif <= 337.5){
        sprite = 7;
    }
    std::cout<<"angleDif: "<<angleDif<<std::endl;
    std::cout<<"sprite: "<<sprite+1<<std::endl;

    sprite+=100;
}

void Enemies::setEnemy(int e){
    pos=e;
}

void Enemies::recortar(int x, int y, int largo, int alto){
    EnemiesHandler.setSrc(x, y, largo,alto);
}

void Enemies::render(int x, int y, int largo, int alto){
    EnemiesHandler.render(x, y, largo, alto, pos-100);
}

Enemies::~Enemies(){}