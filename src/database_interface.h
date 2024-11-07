
#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <memory>
#include <string>
#include <cstdint>
#include <unordered_map>

class DBResult {
public:
    DBResult() = default;
    
    template <typename T>
    T getNumber(const std::string& column) const {
        // Placeholder for database retrieval logic
        if (numericData.find(column) != numericData.end()) {
            return static_cast<T>(numericData.at(column));
        }
        return T{}; // Return default if not found
    }

    std::string getString(const std::string& column) const {
        // Placeholder for database retrieval logic
        if (stringData.find(column) != stringData.end()) {
            return stringData.at(column);
        }
        return ""; // Return empty string if not found
    }

    // Method to simulate setting data in the DBResult (for testing)
    void setData(const std::string& column, int64_t value) {
        numericData[column] = value;
    }
    void setData(const std::string& column, const std::string& value) {
        stringData[column] = value;
    }

private:
    std::unordered_map<std::string, int64_t> numericData;
    std::unordered_map<std::string, std::string> stringData;
};

using DBResult_ptr = std::shared_ptr<DBResult>;

#endif // DATABASE_INTERFACE_H
