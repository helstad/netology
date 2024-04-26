#include "advanced_sql_select_query_builder.h"

AdvancedSqlSelectQueryBuilder::AdvancedSqlSelectQueryBuilder() : SqlSelectQueryBuilder() {}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddGreaterThan(const std::string& column, const std::string& value)
{
	AddWhere(column + ">", value);
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddLessThan(const std::string& column, const std::string& value)
{
	AddWhere(column + "<", value);
	return *this;
}

std::string AdvancedSqlSelectQueryBuilder::BuildQuery() const 
{
	std::string query = SqlSelectQueryBuilder::BuildQuery();

	size_t pos = query.find('>');
	while (pos != std::string::npos) 
	{
		query.replace(pos, 1, ">");
		pos = query.find('>', pos + 1);
	}

	pos = query.find('<');
	while (pos != std::string::npos) 
	{
		query.replace(pos, 1, "<");
		pos = query.find('<', pos + 1);
	}

	return query;
}
