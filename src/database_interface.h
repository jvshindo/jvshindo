#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <memory>
#include <string>
class DBResult;
using DBResult_ptr = std::shared_ptr<DBResult>;

// Forward declare methods that may be needed globally
DBResult_ptr storeQuery(const std::string& query);
std::string escapeString(const std::string& str);

#endif // DATABASE_INTERFACE_H
