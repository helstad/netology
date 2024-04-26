#pragma once

#include "sql_select_query_builder.h"

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
    AdvancedSqlSelectQueryBuilder();

    AdvancedSqlSelectQueryBuilder& AddGreaterThan(const std::string& column, const std::string& value);
    AdvancedSqlSelectQueryBuilder& AddLessThan(const std::string& column, const std::string& value);

    std::string BuildQuery() const override;
};

