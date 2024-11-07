#ifndef BEHAVIOURDATABASE_H
#define BEHAVIOURDATABASE_H

#include "npc.h"  // Including npc.h directly to ensure full access to Npc class
#include <string>
#include <memory>
#include <mutex>  // Include for std::recursive_mutex

class ScriptReader;  // Forward declaration
class NpcBehaviour;  // Forward declaration
class NpcBehaviourNode;  // Forward declaration
enum BehaviourSituation_t;  // Forward declaration

class BehaviourDatabase {
public:
    BehaviourDatabase(Npc* _npc);  // Added constructor declaration
    ~BehaviourDatabase();  // Destructor declaration

    void react(int situation, class Player* player, const std::string& message);
    void checkAction(const void* action, Player* player, const std::string& message);
    void attendCustomer(uint32_t playerId);
    void idle();

private:
    Npc* npc;  // Pointer to Npc
    std::recursive_mutex mutex;  // Mutex for thread safety

    // Add member variables and other methods here as needed
};

#endif // BEHAVIOURDATABASE_H
