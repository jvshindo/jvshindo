#ifndef BEHAVIOUR_DATABASE_H
#define BEHAVIOUR_DATABASE_H

#include <string>
#include <vector>

// Inclua outros cabeçalhos que definem Player, NpcBehaviour, ScriptReader e outros tipos necessários.
#include "Player.h"
#include "NpcBehaviour.h"
#include "ScriptReader.h"

enum BehaviourSituation_t; // Forward declaration

class BehaviourDatabase {
public:
    BehaviourDatabase(NPC* _npc); // Construtor correto
    ~BehaviourDatabase(); // Destrutor

    bool loadDatabase(ScriptReader& script);
    bool loadBehaviour(ScriptReader& script);
    bool loadConditions(ScriptReader& script, NpcBehaviour* behaviour);
    bool loadActions(ScriptReader& script, NpcBehaviour* behaviour);
    NpcBehaviourNode* readValue(ScriptReader& script);
    NpcBehaviourNode* readFactor(ScriptReader& script, NpcBehaviourNode* nextNode);
    void react(BehaviourSituation_t situation, Player* player, const std::string& message);
    bool checkCondition(const NpcBehaviourCondition* condition, Player* player, const std::string& message);
    void checkAction(const NpcBehaviourAction* action, Player* player, const std::string& message);
    int32_t evaluate(NpcBehaviourNode* node, Player* player, const std::string& message);
    int32_t checkOperation(Player* player, NpcBehaviourNode* node, const std::string& message);
    std::string parseResponse(Player* player, const std::string& message);
    void attendCustomer(uint32_t playerId);
    void queueCustomer(uint32_t playerId, const std::string& message);
    void idle();
    void reset();

private:
    NPC* npc;
    std::vector<NpcBehaviour*> behaviourEntries;
    // Adicione outras variáveis conforme necessário
};

#endif // BEHAVIOUR_DATABASE_H
