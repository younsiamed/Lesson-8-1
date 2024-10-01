#include "sql_query_builder.h"
#include <iostream>

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");

    std::map<std::string, std::string> conditions = { {"id", "42"}, {"name", "John"} };
    query_builder.AddWhere(conditions);

    std::string query = query_builder.BuildQuery();

    if (query == "SELECT name, phone FROM students WHERE id=42 AND name=John;") {
        std::cout << "Построенный запрос соответствует ожидаемому." << std::endl;
    }
    else {
        std::cout << "Ошибка: построенный запрос не соответствует ожидаемому." << std::endl;
    }

    std::cout << query << std::endl;
    return 0;
}
