#ifndef SERVERPLAYER__T
#define SERVERPLAYER__T

#include "../common_src/Circle.h"
#include <cmath>
#include "../common_src/types.h"
#include "../common_src/Vector.h"
#include "sp_inventory/SPWeapon.h"
#include "sp_inventory/SPInventory.h"



//
//Clase que se ocupa de la logica del jugador
class ServerPlayer{
private:
    circle position;
    player_move_orientation_t moveOrientation;
    player_rotate_orientation_t rotateOrientation;
    SPInventory inventory;
	SPWeapon *currentWeapon;

    float ang;
    float dirx;
    float diry;
    float step;
    size_t ID;
    size_t lifes;
    size_t score;
    player_weapons_t currentWP;
    int health;

    size_t ammo;
    bool key;
    shooting_state_t shootingState;
    // bool shooting;
    bool updateAvailable;
    weapon_t getSecondaryWPtype();

public:
    void shoot();

    bool updateIsAvailable();
    void updated();

    ServerPlayer(float x, float y, float a, size_t ID);
    ~ServerPlayer();
    ServerPlayer(ServerPlayer&& other);
    void rotate();

    // bool enemyInShootRange(ServerPlayer &enemy, float wallDist);
    void getDamageCoefficient(ServerPlayer &enemy, float &coef, float wallDist);
    float getAngle();
	void shoot(ServerPlayer &enemy, float coef);
    void beDamaged(int damage);


    player_move_orientation_t getMoveOrientation();
    void getPlayerInfo(Player_t &p);
    void getPosition(float &x, float &y);
    void getPosition(circle &c);
    void getDirection(float &x, float &y);
    void setDirection(float x, float y);
    void setMoveOrientation(player_move_orientation_t o);
    void seteRotateOrientation(player_rotate_orientation_t o);
    float getDist(ServerPlayer &enemy);

    void move();
    void setCurrentWeapon(player_weapons_t aWeapon);
    void startShooting();
    void stopShooting();
    bool isShooting();
    bool startedShooting();
    weapon_t equip(weapon_t weapon);
    int heal(int h);
    int reload(int ammo);
    int grabKey(game_key_t k);
    int addPoints(int p);

    size_t getID();
    // void setID(size_t newID);
};

#endif