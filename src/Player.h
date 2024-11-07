#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(); // Construtor padrão
    ~Player(); // Destrutor

    void setName(const std::string& name);
    std::string getName() const;

    void setHealth(int health);
    int getHealth() const;

    void setPosition(int x, int y);
    void getPosition(int& x, int& y) const;

private:
    std::string name;
    int health;
    int posX;
    int posY;
};

#endif // PLAYER_H
