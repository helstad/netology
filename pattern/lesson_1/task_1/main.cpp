#include <iostream>

#include "sql_select_query_builder.h"

int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	query_builder.AddFrom("students");
	query_builder.AddColumn("name").AddColumn("phone");

	std::string expected_query = "SELECT name, phone FROM students WHERE id=42 AND name=John;";
	
	std::string generated_query = query_builder.BuildQuery();

	if (generated_query == expected_query) {
		std::cout << "Generated query matches the expected query." << std::endl;
	}
	else {
		std::cout << "Generated query does not match the expected query." << std::endl;
		std::cout << "Expected:\t" << expected_query << "\n";
		std::cout << "Generated:\t" << generated_query;
	}

	return 0;
}