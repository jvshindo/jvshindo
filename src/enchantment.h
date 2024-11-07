#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>

class Enchantment {
public:
    // Limites máximos para cada atributo
    static const int MAX_DEFENSE_BONUS = 5;
    static const int MAX_SKILL_BONUS = 5;
    static const int MAX_RESISTANCE_BONUS = 5;
    static const int MAX_CRITICAL_CHANCE = 5;

    Enchantment();
    
    int getDefenseBonus() const { return defenseBonus; }
    int getSkillBonus() const { return skillBonus; }
    int getFireResistance() const { return fireResistance; }
    int getCriticalChance() const { return criticalChance; }

    bool increaseDefense();
    bool increaseSkill();
    bool increaseResistance();
    bool increaseCritical();

    void save(); // Função para salvar no banco de dados

private:
    int defenseBonus;
    int skillBonus;
    int fireResistance;
    int criticalChance;
};

#endif // ENCHANTMENT_H
