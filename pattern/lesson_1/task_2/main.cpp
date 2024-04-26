#include <iostream>

#include "sql_select_query_builder.h"

int main()
{
	SqlSelectQueryBuilder query_builder;

	std::vector<std::string> columns = { "name", "phone", "email" };
	query_builder.AddColumns(columns);
	query_builder.AddFrom("students");

	std::map<std::string, std::string> where_conditions = {
		{"id", "42"},
		{"name", "John"}
	};

	query_builder.AddWhere(where_conditions);

	std::string sql_query = query_builder.BuildQuery();

	std::cout << "Generated SQL Query: " << sql_query << std::endl;

	return 0;
}