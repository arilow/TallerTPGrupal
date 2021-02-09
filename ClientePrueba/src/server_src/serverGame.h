#ifndef SERVERGAME__T
#define SERVERGAME__T

#include <map>
#include <vector>
#include <cmath>
#include "../common_src/types.h"
#include "serverPlayer.h"
#include "CollisionMap.h"
#include "updateHandler.h"


//
//Clase que se ocupa de la logica del juego
class ServerGame{
private:
    std::map<size_t, ServerPlayer> &players;
    std::vector<std::vector<int>> &lvl1;
    UpdateHandler updateHandler;
    CollisionMap colMap;
    std::queue<UpdateHandler> &uQ; 

public:
    ServerGame(std::map<size_t, ServerPlayer> &p,
                std::vector<std::vector<int>> &l,
                std::queue<UpdateHandler> &q);
    // ~ServerGame();
    float shootRaycaster(ServerPlayer &player);



    void update();
    void movePlayer(ServerPlayer &player);
    void handlePlayerShoot(ServerPlayer &player);

    void handleCollision(circle &playerPos, int c);
};

#endif 