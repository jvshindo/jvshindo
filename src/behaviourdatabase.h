
#ifndef BEHAVIOUR_DATABASE_H
#define BEHAVIOUR_DATABASE_H

#include <string>

class NPC; // Forward declaration of NPC
class NpcBehaviour; // Forward declaration of NpcBehaviour
enum BehaviourSituation_t; // Forward declaration of the enum

class BehaviourDatabase {
public:
    BehaviourDatabase(NPC* _npc); // Changed Npc to NPC
    ~BehaviourDatabase(); // Destructor declaration

    bool loadDatabase(ScriptReader& script); // Example function
    bool loadBehaviour(ScriptReader& script); // Example function
    bool loadConditions(ScriptReader& script, NpcBehaviour* behaviour); // Example function
    bool loadActions(ScriptReader& script, NpcBehaviour* behaviour); // Example function
    NpcBehaviourNode* readValue(ScriptReader& script); // Example function
    NpcBehaviourNode* readFactor(ScriptReader& script, NpcBehaviourNode* nextNode); // Example function
    void react(BehaviourSituation_t situation, Player* player, const std::string& message); // Example function
    bool checkCondition(const NpcBehaviourCondition* condition, Player* player, const std::string& message); // Example function
    void checkAction(const NpcBehaviourAction* action, Player* player, const std::string& message); // Example function
    int32_t evaluate(NpcBehaviourNode* node, Player* player, const std::string& message); // Example function
    int32_t checkOperation(Player* player, NpcBehaviourNode* node, const std::string& message); // Example function
    int32_t searchDigit(const std::string& message); // Example function
    bool searchWord(const std::string& pattern, const std::string& message); // Example function
    std::string parseResponse(Player* player, const std::string& message); // Example function
    void reset(); // Example function

private:
    NPC* npc; // Pointer to NPC
    // Additional private members and methods can be declared here
};

#endif // BEHAVIOUR_DATABASE_H
