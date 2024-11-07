
// Arquivo original com declaração de função adicional para salvar encantamento
#include "enchantment.h"

class Database {
public:
    static Database& getInstance();
    bool saveItemEnchantment(int itemId, Enchantment* enchantment); // Função para salvar encantamento
};

// Definition for DBResult
class DBResult {
public:
    // Add necessary methods and properties here
};

// Definition for DBResult_ptr
using DBResult_ptr = std::shared_ptr<DBResult>;
