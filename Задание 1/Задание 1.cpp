#include "sql_query_builder.h"
#include <iostream>

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

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
