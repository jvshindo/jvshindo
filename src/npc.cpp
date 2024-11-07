
// Arquivo original com função adicional para o NPC Mestre do Encantamento
#include "npc.h"
#include "enchantment.h"
#include "item.h"

void NPC::onTalk(Player* player) {
    if (this->isEnchantmentMaster()) { // Verifica se o NPC é o Mestre do Encantamento
        enchantInteraction(player);
    } else {
        // Resto do comportamento original dos NPCs
    }
}

void NPC::enchantInteraction(Player* player) {
    // Interação do NPC Mestre do Encantamento com o jogador
    player->sendTextMessage("Bem-vindo ao mestre de encantamentos. Escolha o atributo que deseja melhorar.");
    int escolha = player->getChoice();  // Placeholder para a escolha do jogador
    Item* item = player->getSelectedItem(); // Exemplo de item escolhido pelo jogador

    if (!item || !item->getEnchantment()) {
        player->sendTextMessage("Por favor, selecione um item que possa ser encantado.");
        return;
    }

    switch (escolha) {
        case 1:
            if (item->getEnchantment()->increaseDefense()) {
                player->sendTextMessage("Defesa aumentada com sucesso!");
            } else {
                player->sendTextMessage("Defesa já está no máximo.");
            }
            break;
        case 2:
            if (item->getEnchantment()->increaseSkill()) {
                player->sendTextMessage("Habilidade aumentada com sucesso!");
            } else {
                player->sendTextMessage("Habilidade já está no máximo.");
            }
            break;
        case 3:
            if (item->getEnchantment()->increaseResistance()) {
                player->sendTextMessage("Resistência aumentada com sucesso!");
            } else {
                player->sendTextMessage("Resistência já está no máximo.");
            }
            break;
        case 4:
            if (item->getEnchantment()->increaseCritical()) {
                player->sendTextMessage("Chance de crítico aumentada com sucesso!");
            } else {
                player->sendTextMessage("Chance de crítico já está no máximo!");
            }
            break;
        default:
            player->sendTextMessage("Escolha inválida.");
    }
}
