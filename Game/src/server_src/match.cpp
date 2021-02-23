#include "match.h"
#include <algorithm>
#include <chrono>



std::vector<std::vector<int>> lvl2 = {
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,001,000,000,334,000,000,000,133,000,201,000,121,004,121,121,121,000,434},
	{434,000,000,000,000,111,000,000,000,133,000,000,000,121,121,121,121,121,000,434},
	{434,000,000,000,000,135,000,000,000,000,000,000,000,121,121,121,121,121,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,101,102,000,000,000,000,000,000,000,141,142,143,144,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,434,434,350,434,434,434,434,434,434,434,434,434,434,353,434,434,434,434,434},
	{434,000,000,000,000,000,000,000,434,434,000,000,000,000,000,000,000,000,000,434},
	{434,000,002,000,000,000,000,000,352,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,000,000,000,000,121,121,434,000,000,000,000,000,003,000,000,121,121,434},
	{434,000,113,113,000,000,134,121,434,000,000,113,113,000,000,000,000,135,121,434},
	{434,000,113,113,000,000,000,000,434,434,000,113,113,000,000,000,000,000,000,434},
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
};

std::vector<std::vector<int>> lvl3 = {
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,001,000,000,000,000,000,141,000,000,201,000,000,000,002,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,101,102,111,112,113,121,133,134,135,141,142,143,144,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,434,434,434,434,434,000,000,434,434,434,434,000,000,000,000,000,434,434,434},
	{434,000,000,000,000,000,004,000,434,434,000,000,000,000,000,003,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
};

std::vector<std::vector<int>> lvl4 = {
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
	{434,000,000,000,000,000,000,000,000,000,000,201,000,000,000,000,000,434},
	{434,000,000,001,000,000,000,000,000,000,000,201,000,000,002,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,201,000,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,000,101,102,111,112,113,121,133,134,135,141,142,143,144,000,000,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,434,434,434,434,434,000,004,434,434,434,434,000,000,003,434,434,434},
	{434,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,434},
	{434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434,434},
};
std::map<std::string, std::vector<std::vector<int>>> lvls = {
        {"map1",lvl2},
        {"map2",lvl3},
        {"map3",lvl4}
};
Match::Match(std::string &matchName, std::string &chosenMap,
                    int &numberOfPlayers, int &numberOfBots):
    is_running(true),
    name(matchName),
    lvl1(lvls.at(chosenMap)),
    connectionNumber(0),
    game(players, lvl1, uQ, missileUQ),
    bot(q, 110, 110, 0, 0, lvls.at(chosenMap)),
    matchEventReader(players, q)
{
    initializeInitPosition(lvls.at(chosenMap));
    initializeMaps();
    // lvl1 = availableMaps.at(chosenMap);

    if(numberOfBots != 0){
        initPos auxPos;
        auxPos = initPositions.at(connectionNumber % 4);
        ServerPlayer auxPlayer(auxPos.x, auxPos.y, 0, connectionNumber);
        players.emplace(connectionNumber, std::move(auxPlayer));
    } 
        connectionNumber++;

    matchEventReader();
}

void Match::initializeMaps(){
    availableMaps.emplace("map1", lvl2);
    availableMaps.emplace("map2", lvl3);
    availableMaps.emplace("map3", lvl4);
}

void Match::initializeInitPosition(std::vector<std::vector<int>> &map){
    int	rows=map.size();
	int cols=map[0].size();
    int playersCounter=0;;

	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if(map[i][j]>INITIAL_PLAYER_POS_OFFSET && map[i][j]<MAX_PLAYERS){
                initPos pos={j*64+32, i*64+32};

                std::cout<<"map: "<<map[i][j]<<std::endl;

                std::cout<<"pos: "<<std::endl;
                std::cout<<"x: "<<pos.x<<" y: "<<pos.y<<std::endl;

                initPositions.emplace(playersCounter, pos);
                playersCounter++;
                if(map[i][j]<300)
                    map[i][j]=0;

            }
        }
    }
}

Match::~Match(){
    q.close();
    for (auto user:users){
        if(user.second->hasStarted()){
            user.second->stop();
            user.second->join();    
        }
        delete(user.second);
    }
    if(!matchEventReader.isDead()){
        matchEventReader.stop();
    }
    matchEventReader.join();
}

void Match::operator()(){
    this->start();
}

void Match::run(){
    long timeStep = 1000/60;
    try{
        while(is_running){
            auto initial = std::chrono::high_resolution_clock::now();
            // readEvents();
            // bot.makeDecision();
            game.update();
            updateUsers();
            
            auto final = std::chrono::high_resolution_clock::now();
            auto loopDuration = std::chrono::duration_cast<std::chrono::milliseconds>(final - initial);
            long sleepTime = timeStep - loopDuration.count();
            if (sleepTime > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
            }
        }
    } catch (const std::exception &e){
        std::cerr << "Error encontrado en Match.run()" << std::endl;
        std::cerr << e.what() << std::endl;
        return;
    } catch (...) { // ellipsis: catch anything
        printf("Unknown error!");
    }
}

void Match::updateUsers(){
    while (uQ.empty()==false){
        for(auto user:users)
            user.second->update(uQ.front());
        // for(auto bot:bots)
        //     bot.second->update(uQ.front());
        // bot.update(uQ.front());
        uQ.pop();
    }
    while (missileUQ.empty()==false){
        for(auto user:users)
            user.second->updateMissile(missileUQ.front());
        missileUQ.pop();
    }
}

void Match::stop(){
    q.close();
    matchEventReader.stop();
    is_running = false;
}

// Le manda al usuario su información inicial
void Match::welcomeUser(User* user){
    update_tag_t aTag = TAG_PLAYER_INFO;
    user->sendGameUpdate(aTag);

    Player_t auxPlayer;
    players.at(connectionNumber).getPlayerInfo(auxPlayer);
    user->sendPlayerInfo(auxPlayer);

    aTag = TAG_MAP_INIT;    
    user->sendGameUpdate(aTag);
    user->sendMap(lvl1);
}

// Carga al usuario y sus atributos iniciales al contenedor
void Match::addUser(User* user){
    initPos auxPos;
    auxPos = initPositions.at(connectionNumber % 4);

    ServerPlayer auxPlayer(auxPos.x, auxPos.y, 0, connectionNumber);
    players.emplace(connectionNumber, std::move(auxPlayer));
    user->setProtectedMatchEventQueue(&q);
    // user->setProtectedMatchEventQueue(&q);
    user->setID(connectionNumber);
    users[connectionNumber] = user;

    user->start();

    welcomeUser(user);
    std::cout << "se guardo el ID: "  << connectionNumber << std::endl;
    connectionNumber++;

}

std::string Match::getName(){
    return name;
}

bool Match::started(){
    return gameStarted;
}

bool Match::isUserNameAvailable(std::string aName){
    for(auto user:users){
        if(user.second->getName() == aName)
            return false;
    }
    return true;
}
