
#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <memory>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <sstream>

class DBResult {
public:
    DBResult() = default;
    
    template <typename T>
    T getNumber(const std::string& column) const {
        if (numericData.find(column) != numericData.end()) {
            return static_cast<T>(numericData.at(column));
        }
        return T{}; // Default return if not found
    }

    std::string getString(const std::string& column) const {
        if (stringData.find(column) != stringData.end()) {
            return stringData.at(column);
        }
        return ""; // Default return if not found
    }

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

// Basic implementation of DBInsert for inserting data into the database
class DBInsert {
public:
    DBInsert() = default;

    // Method to prepare an insert statement with column and value
    void addRow(const std::string& column, const std::string& value) {
        columns += column + ", ";
        values += "'" + escapeString(value) + "', ";
    }

    // To finalize and get the complete query
    std::string getQuery() const {
        if (!columns.empty() && !values.empty()) {
            // Remove trailing ", " from columns and values
            return "INSERT INTO table_name (" + columns.substr(0, columns.size() - 2) + 
                   ") VALUES (" + values.substr(0, values.size() - 2) + ");";
        }
        return "";
    }

private:
    std::string columns;
    std::string values;

    // Placeholder method to escape potentially unsafe characters in a value
    std::string escapeString(const std::string& str) const {
        std::string escapedStr = str;  // Apply actual escaping in a real scenario
        return escapedStr;
    }
};

#endif // DATABASE_INTERFACE_H
