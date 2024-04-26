#include <iostream>
#include "advanced_sql_select_query_builder.h"

int main()
{
    AdvancedSqlSelectQueryBuilder query_builder;

    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");
    query_builder.AddGreaterThan("id", "42");

    std::string sql_query = query_builder.BuildQuery();

    std::cout << "Generated SQL Query: " << sql_query << std::endl;

    return 0;
}
