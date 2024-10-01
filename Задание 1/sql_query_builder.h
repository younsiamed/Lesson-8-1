#include <string>
#include <vector>
#include <sstream>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string table;
    std::vector<std::string> conditions;

public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& fromTable) {
        table = fromTable;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        conditions.push_back(column + "=" + value);
        return *this;
    }

    std::string BuildQuery() const {
        std::ostringstream query;
        query << "SELECT ";

        if (columns.empty()) {
            query << "*";
        }
        else {
            query << join(columns, ", ");
        }

        query << " FROM " << table;

        if (!conditions.empty()) {
            query << " WHERE " << join(conditions, " AND ");
        }

        query << ";";
        return query.str();
    }

private:
    std::string join(const std::vector<std::string>& parts, const std::string& delimiter) const {
        std::ostringstream result;
        for (size_t i = 0; i < parts.size(); ++i) {
            result << parts[i];
            if (i < parts.size() - 1) {
                result << delimiter;
            }
        }
        return result.str();
    }
};
