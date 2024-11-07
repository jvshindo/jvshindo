
#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
public:
    int focusCreature;
    int conversationStartTime;
    int conversationEndTime;
    int staticMovementTime;

    NPC() : focusCreature(0), conversationStartTime(0), conversationEndTime(0), staticMovementTime(0) {}

    // Example method to simulate NPC actions
    void doSay(const std::string& message) {
        // Placeholder for NPC saying action
    }

    // Placeholder method for getting position of NPC
    std::string getPosition() const {
        return "position"; // Simplified return for position
    }
};

#endif // NPC_H
