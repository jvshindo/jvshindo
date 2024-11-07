
// Arquivo original com métodos adicionais para encantamento
#include "item.h"
#include "enchantment.h"

Item::Item() : enchantment(new Enchantment()) {}

Enchantment* Item::getEnchantment() const {
    return enchantment;
}

// Função para salvar estado do encantamento no banco de dados
void Item::saveEnchantment() {
    // Exemplo de query para salvar os dados de encantamento
    Database::getInstance().executeQuery(
        "UPDATE items SET defense_bonus=" + std::to_string(enchantment->getDefenseBonus()) +
        ", skill_bonus=" + std::to_string(enchantment->getSkillBonus()) +
        ", fire_resistance=" + std::to_string(enchantment->getFireResistance()) +
        ", critical_chance=" + std::to_string(enchantment->getCriticalChance()) +
        " WHERE item_id = " + std::to_string(this->id));
}
