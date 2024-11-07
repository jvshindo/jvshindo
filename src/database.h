
// Arquivo original com declaração de função adicional para salvar encantamento
#include "enchantment.h"

class Database {
public:
    static Database& getInstance();
    bool saveItemEnchantment(int itemId, Enchantment* enchantment); // Função para salvar encantamento
};
