#include "sql_select_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() 
{
	from_ = "";
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) 
{
	columns_.push_back(column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) 
{
	columns_.insert(columns_.end(), columns.begin(), columns.end());
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) 
{
	from_ = table;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) 
{
	whereClauses_.emplace_back(column, value);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) 
{
	for (const auto& pair : kv) {
		whereClauses_.emplace_back(pair.first, pair.second);
	}
	return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() const 
{
	std::string query = "SELECT ";

	if (columns_.empty()) 
	{
		query += "*";
	}
	else {
		for (size_t i = 0; i < columns_.size(); ++i) 
		{
			if (i > 0) 
			{
				query += ", ";
			}
			query += columns_[i];
		}
	}

	query += " FROM " + from_;

	if (!whereClauses_.empty()) 
	{
		query += " WHERE ";
		for (size_t i = 0; i < whereClauses_.size(); ++i) 
		{
			if (i > 0) {
				query += " AND ";
			}
			query += whereClauses_[i].first + "=" + whereClauses_[i].second;
		}
	}

	query += ";";

	return query;
}
