
// Arquivo original com declaração de função adicional para Mestre do Encantamento
class NPC {
public:
    void onTalk(Player* player);  // Função chamada ao falar com o NPC
    bool isEnchantmentMaster() const;  // Função para verificar se o NPC é o Mestre do Encantamento
    void enchantInteraction(Player* player);  // Função de interação com encantamento
};
