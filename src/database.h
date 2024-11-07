
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include "database_interface.h"

class Database {
public:
    static Database* getInstance();

    // Methods for handling enchantments and general queries
    std::shared_ptr<DBResult> storeQuery(const std::string& query);
    std::string escapeString(const std::string& str);

private:
    Database() = default;
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

#endif // DATABASE_H
