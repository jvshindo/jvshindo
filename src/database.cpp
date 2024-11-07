
// Arquivo original com métodos adicionais para encantamento
#include "database.h"

bool Database::saveItemEnchantment(int itemId, Enchantment* enchantment) {
    // Exemplo de query para salvar os dados de encantamento
    return executeQuery("UPDATE items SET defense_bonus=" + std::to_string(enchantment->getDefenseBonus()) +
                        ", skill_bonus=" + std::to_string(enchantment->getSkillBonus()) +
                        ", fire_resistance=" + std::to_string(enchantment->getFireResistance()) +
                        ", critical_chance=" + std::to_string(enchantment->getCriticalChance()) +
                        " WHERE item_id = " + std::to_string(itemId));
}
