#include "behaviourdatabase.h"
#include "npc.h"
#include "script_reader.h"  // Ensure this header exists for ScriptReader
#include <iostream>
#include <mutex>  // Include for std::recursive_mutex

BehaviourDatabase::BehaviourDatabase(Npc* _npc) : npc(_npc) {
    // Constructor implementation
}

BehaviourDatabase::~BehaviourDatabase() {
    // Destructor implementation
}

bool BehaviourDatabase::loadDatabase(ScriptReader& script) {
    // Method implementation goes here
}

bool BehaviourDatabase::loadBehaviour(ScriptReader& script) {
    // Method implementation goes here
}

// Additional methods implementations
// ...

// Ensure all methods are implemented correctly based on the required functionality.
