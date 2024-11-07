#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "database_interface.h"
#include <string>

class Enchantment {
public:
    bool loadEnchantmentData(int itemId);
    bool saveEnchantmentData(int itemId, const std::string& enchantmentData);
private:
    int itemId;
    std::string enchantmentData;
};

#endif // ENCHANTMENT_H
