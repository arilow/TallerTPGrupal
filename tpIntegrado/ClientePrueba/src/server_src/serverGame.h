#ifndef SERVERGAME__T
#define SERVERGAME__T

#include <map>
#include <vector>
#include <cmath>
#include "../common_src/types.h"
#include "serverPlayer.h"
#include "CollisionMap.h"
#include "updateHandler.h"

class ServerGame{
private:
    std::map<size_t, ServerPlayer> &players;
    std::vector<std::vector<int>> &lvl1;
    UpdateHandler &updateHandler;
    CollisionMap colMap;

public:
    ServerGame(std::map<size_t, ServerPlayer> &p,
                std::vector<std::vector<int>> &l,
                UpdateHandler &uH);
    // ~ServerGame();
    void movePlayer(ServerPlayer &player);
    void handleCollision(circle &playerPos, int c);
};

#endif 