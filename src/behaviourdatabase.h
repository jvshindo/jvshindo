
#ifndef BEHAVIOURDATABASE_H
#define BEHAVIOURDATABASE_H

#include "npc.h"  // Including npc.h directly to ensure full access to Npc class
#include <string>
#include <memory>

class BehaviourDatabase {
public:
    void react(int situation, class Player* player, const std::string& message);
    void checkAction(const void* action, Player* player, const std::string& message);
    void attendCustomer(uint32_t playerId);
    void idle();

private:
    // Add member variables and other methods here as needed
};

#endif // BEHAVIOURDATABASE_H
