//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/common/types.hpp"
#include "duckdb/common/extra_type_info.hpp"
#include "duckdb/parser/common_table_expression_info.hpp"
#include "duckdb/parser/query_node.hpp"
#include "duckdb/parser/result_modifier.hpp"
#include "duckdb/planner/bound_result_modifier.hpp"
#include "duckdb/parser/expression/case_expression.hpp"
#include "duckdb/planner/expression/bound_case_expression.hpp"
#include "duckdb/parser/parsed_data/sample_options.hpp"
#include "duckdb/parser/tableref/pivotref.hpp"
#include "duckdb/planner/tableref/bound_pivotref.hpp"
#include "duckdb/parser/column_definition.hpp"
#include "duckdb/parser/column_list.hpp"
#include "duckdb/planner/column_binding.hpp"
#include "duckdb/planner/expression/bound_parameter_data.hpp"
#include "duckdb/planner/joinside.hpp"
#include "duckdb/parser/parsed_data/vacuum_info.hpp"
#include "duckdb/planner/table_filter.hpp"
#include "duckdb/common/multi_file_reader_options.hpp"
#include "duckdb/common/multi_file_reader.hpp"
#include "duckdb/execution/operator/persistent/csv_reader_options.hpp"
#include "duckdb/function/scalar/strftime_format.hpp"
#include "duckdb/function/table/read_csv.hpp"

namespace duckdb {

void BoundCaseCheck::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "when_expr", *when_expr);
	serializer.WriteProperty(101, "then_expr", *then_expr);
}

BoundCaseCheck BoundCaseCheck::FormatDeserialize(FormatDeserializer &deserializer) {
	BoundCaseCheck result;
	deserializer.ReadProperty(100, "when_expr", result.when_expr);
	deserializer.ReadProperty(101, "then_expr", result.then_expr);
	return result;
}

void BoundOrderByNode::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "type", type);
	serializer.WriteProperty(101, "null_order", null_order);
	serializer.WriteProperty(102, "expression", *expression);
}

BoundOrderByNode BoundOrderByNode::FormatDeserialize(FormatDeserializer &deserializer) {
	auto type = deserializer.ReadProperty<OrderType>(100, "type");
	auto null_order = deserializer.ReadProperty<OrderByNullType>(101, "null_order");
	auto expression = deserializer.ReadProperty<unique_ptr<Expression>>(102, "expression");
	BoundOrderByNode result(type, null_order, std::move(expression));
	return result;
}

void BoundParameterData::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "value", value);
	serializer.WriteProperty(101, "return_type", return_type);
}

shared_ptr<BoundParameterData> BoundParameterData::FormatDeserialize(FormatDeserializer &deserializer) {
	auto value = deserializer.ReadProperty<Value>(100, "value");
	auto result = duckdb::shared_ptr<BoundParameterData>(new BoundParameterData(value));
	deserializer.ReadProperty(101, "return_type", result->return_type);
	return result;
}

void BoundPivotInfo::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "group_count", group_count);
	serializer.WriteProperty(101, "types", types);
	serializer.WriteProperty(102, "pivot_values", pivot_values);
	serializer.WriteProperty(103, "aggregates", aggregates);
}

BoundPivotInfo BoundPivotInfo::FormatDeserialize(FormatDeserializer &deserializer) {
	BoundPivotInfo result;
	deserializer.ReadProperty(100, "group_count", result.group_count);
	deserializer.ReadProperty(101, "types", result.types);
	deserializer.ReadProperty(102, "pivot_values", result.pivot_values);
	deserializer.ReadProperty(103, "aggregates", result.aggregates);
	return result;
}

void BufferedCSVReaderOptions::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "has_delimiter", has_delimiter);
	serializer.WriteProperty(101, "delimiter", delimiter);
	serializer.WriteProperty(102, "has_quote", has_quote);
	serializer.WriteProperty(103, "quote", quote);
	serializer.WriteProperty(104, "has_escape", has_escape);
	serializer.WriteProperty(105, "escape", escape);
	serializer.WriteProperty(106, "has_header", has_header);
	serializer.WriteProperty(107, "header", header);
	serializer.WriteProperty(108, "ignore_errors", ignore_errors);
	serializer.WriteProperty(109, "num_cols", num_cols);
	serializer.WriteProperty(110, "buffer_sample_size", buffer_sample_size);
	serializer.WriteProperty(111, "null_str", null_str);
	serializer.WriteProperty(112, "compression", compression);
	serializer.WriteProperty(113, "new_line", new_line);
	serializer.WriteProperty(114, "allow_quoted_nulls", allow_quoted_nulls);
	serializer.WriteProperty(115, "skip_rows", skip_rows);
	serializer.WriteProperty(116, "skip_rows_set", skip_rows_set);
	serializer.WriteProperty(117, "maximum_line_size", maximum_line_size);
	serializer.WriteProperty(118, "normalize_names", normalize_names);
	serializer.WriteProperty(119, "force_not_null", force_not_null);
	serializer.WriteProperty(120, "all_varchar", all_varchar);
	serializer.WriteProperty(121, "sample_chunk_size", sample_chunk_size);
	serializer.WriteProperty(122, "sample_chunks", sample_chunks);
	serializer.WriteProperty(123, "auto_detect", auto_detect);
	serializer.WriteProperty(124, "file_path", file_path);
	serializer.WriteProperty(125, "decimal_separator", decimal_separator);
	serializer.WriteProperty(126, "null_padding", null_padding);
	serializer.WriteProperty(127, "buffer_size", buffer_size);
	serializer.WriteProperty(128, "file_options", file_options);
	serializer.WriteProperty(129, "force_quote", force_quote);
	serializer.WriteProperty(130, "date_format", date_format);
	serializer.WriteProperty(131, "has_format", has_format);
	serializer.WriteProperty(132, "rejects_table_name", rejects_table_name);
	serializer.WriteProperty(133, "rejects_limit", rejects_limit);
	serializer.WriteProperty(134, "rejects_recovery_columns", rejects_recovery_columns);
	serializer.WriteProperty(135, "rejects_recovery_column_ids", rejects_recovery_column_ids);
}

BufferedCSVReaderOptions BufferedCSVReaderOptions::FormatDeserialize(FormatDeserializer &deserializer) {
	BufferedCSVReaderOptions result;
	deserializer.ReadProperty(100, "has_delimiter", result.has_delimiter);
	deserializer.ReadProperty(101, "delimiter", result.delimiter);
	deserializer.ReadProperty(102, "has_quote", result.has_quote);
	deserializer.ReadProperty(103, "quote", result.quote);
	deserializer.ReadProperty(104, "has_escape", result.has_escape);
	deserializer.ReadProperty(105, "escape", result.escape);
	deserializer.ReadProperty(106, "has_header", result.has_header);
	deserializer.ReadProperty(107, "header", result.header);
	deserializer.ReadProperty(108, "ignore_errors", result.ignore_errors);
	deserializer.ReadProperty(109, "num_cols", result.num_cols);
	deserializer.ReadProperty(110, "buffer_sample_size", result.buffer_sample_size);
	deserializer.ReadProperty(111, "null_str", result.null_str);
	deserializer.ReadProperty(112, "compression", result.compression);
	deserializer.ReadProperty(113, "new_line", result.new_line);
	deserializer.ReadProperty(114, "allow_quoted_nulls", result.allow_quoted_nulls);
	deserializer.ReadProperty(115, "skip_rows", result.skip_rows);
	deserializer.ReadProperty(116, "skip_rows_set", result.skip_rows_set);
	deserializer.ReadProperty(117, "maximum_line_size", result.maximum_line_size);
	deserializer.ReadProperty(118, "normalize_names", result.normalize_names);
	deserializer.ReadProperty(119, "force_not_null", result.force_not_null);
	deserializer.ReadProperty(120, "all_varchar", result.all_varchar);
	deserializer.ReadProperty(121, "sample_chunk_size", result.sample_chunk_size);
	deserializer.ReadProperty(122, "sample_chunks", result.sample_chunks);
	deserializer.ReadProperty(123, "auto_detect", result.auto_detect);
	deserializer.ReadProperty(124, "file_path", result.file_path);
	deserializer.ReadProperty(125, "decimal_separator", result.decimal_separator);
	deserializer.ReadProperty(126, "null_padding", result.null_padding);
	deserializer.ReadProperty(127, "buffer_size", result.buffer_size);
	deserializer.ReadProperty(128, "file_options", result.file_options);
	deserializer.ReadProperty(129, "force_quote", result.force_quote);
	deserializer.ReadProperty(130, "date_format", result.date_format);
	deserializer.ReadProperty(131, "has_format", result.has_format);
	deserializer.ReadProperty(132, "rejects_table_name", result.rejects_table_name);
	deserializer.ReadProperty(133, "rejects_limit", result.rejects_limit);
	deserializer.ReadProperty(134, "rejects_recovery_columns", result.rejects_recovery_columns);
	deserializer.ReadProperty(135, "rejects_recovery_column_ids", result.rejects_recovery_column_ids);
	return result;
}

void CaseCheck::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "when_expr", *when_expr);
	serializer.WriteProperty(101, "then_expr", *then_expr);
}

CaseCheck CaseCheck::FormatDeserialize(FormatDeserializer &deserializer) {
	CaseCheck result;
	deserializer.ReadProperty(100, "when_expr", result.when_expr);
	deserializer.ReadProperty(101, "then_expr", result.then_expr);
	return result;
}

void ColumnBinding::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "table_index", table_index);
	serializer.WriteProperty(101, "column_index", column_index);
}

ColumnBinding ColumnBinding::FormatDeserialize(FormatDeserializer &deserializer) {
	ColumnBinding result;
	deserializer.ReadProperty(100, "table_index", result.table_index);
	deserializer.ReadProperty(101, "column_index", result.column_index);
	return result;
}

void ColumnDefinition::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "name", name);
	serializer.WriteProperty(101, "type", type);
	serializer.WriteOptionalProperty(102, "expression", expression);
	serializer.WriteProperty(103, "category", category);
	serializer.WriteProperty(104, "compression_type", compression_type);
}

ColumnDefinition ColumnDefinition::FormatDeserialize(FormatDeserializer &deserializer) {
	auto name = deserializer.ReadProperty<string>(100, "name");
	auto type = deserializer.ReadProperty<LogicalType>(101, "type");
	auto expression = deserializer.ReadOptionalProperty<unique_ptr<ParsedExpression>>(102, "expression");
	auto category = deserializer.ReadProperty<TableColumnType>(103, "category");
	ColumnDefinition result(std::move(name), std::move(type), std::move(expression), category);
	deserializer.ReadProperty(104, "compression_type", result.compression_type);
	return result;
}

void ColumnInfo::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "names", names);
	serializer.WriteProperty(101, "types", types);
}

ColumnInfo ColumnInfo::FormatDeserialize(FormatDeserializer &deserializer) {
	ColumnInfo result;
	deserializer.ReadProperty(100, "names", result.names);
	deserializer.ReadProperty(101, "types", result.types);
	return result;
}

void ColumnList::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "columns", columns);
}

ColumnList ColumnList::FormatDeserialize(FormatDeserializer &deserializer) {
	auto columns = deserializer.ReadProperty<vector<ColumnDefinition>>(100, "columns");
	ColumnList result(std::move(columns));
	return result;
}

void CommonTableExpressionInfo::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "aliases", aliases);
	serializer.WriteProperty(101, "query", *query);
	serializer.WriteProperty(102, "materialized", materialized);
}

unique_ptr<CommonTableExpressionInfo> CommonTableExpressionInfo::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CommonTableExpressionInfo>(new CommonTableExpressionInfo());
	deserializer.ReadProperty(100, "aliases", result->aliases);
	deserializer.ReadProperty(101, "query", result->query);
	deserializer.ReadProperty(102, "materialized", result->materialized);
	return result;
}

void CommonTableExpressionMap::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "map", map);
}

CommonTableExpressionMap CommonTableExpressionMap::FormatDeserialize(FormatDeserializer &deserializer) {
	CommonTableExpressionMap result;
	deserializer.ReadProperty(100, "map", result.map);
	return result;
}

void HivePartitioningIndex::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "value", value);
	serializer.WriteProperty(101, "index", index);
}

HivePartitioningIndex HivePartitioningIndex::FormatDeserialize(FormatDeserializer &deserializer) {
	auto value = deserializer.ReadProperty<string>(100, "value");
	auto index = deserializer.ReadProperty<idx_t>(101, "index");
	HivePartitioningIndex result(std::move(value), index);
	return result;
}

void JoinCondition::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "left", *left);
	serializer.WriteProperty(101, "right", *right);
	serializer.WriteProperty(102, "comparison", comparison);
}

JoinCondition JoinCondition::FormatDeserialize(FormatDeserializer &deserializer) {
	JoinCondition result;
	deserializer.ReadProperty(100, "left", result.left);
	deserializer.ReadProperty(101, "right", result.right);
	deserializer.ReadProperty(102, "comparison", result.comparison);
	return result;
}

void LogicalType::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "id", id_);
	serializer.WriteOptionalProperty(101, "type_info", type_info_);
}

LogicalType LogicalType::FormatDeserialize(FormatDeserializer &deserializer) {
	auto id = deserializer.ReadProperty<LogicalTypeId>(100, "id");
	auto type_info = deserializer.ReadOptionalProperty<shared_ptr<ExtraTypeInfo>>(101, "type_info");
	LogicalType result(id, std::move(type_info));
	return result;
}

void MultiFileReaderBindData::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "filename_idx", filename_idx);
	serializer.WriteProperty(101, "hive_partitioning_indexes", hive_partitioning_indexes);
}

MultiFileReaderBindData MultiFileReaderBindData::FormatDeserialize(FormatDeserializer &deserializer) {
	MultiFileReaderBindData result;
	deserializer.ReadProperty(100, "filename_idx", result.filename_idx);
	deserializer.ReadProperty(101, "hive_partitioning_indexes", result.hive_partitioning_indexes);
	return result;
}

void MultiFileReaderOptions::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "filename", filename);
	serializer.WriteProperty(101, "hive_partitioning", hive_partitioning);
	serializer.WriteProperty(102, "auto_detect_hive_partitioning", auto_detect_hive_partitioning);
	serializer.WriteProperty(103, "union_by_name", union_by_name);
	serializer.WriteProperty(104, "hive_types_autocast", hive_types_autocast);
	serializer.WriteProperty(105, "hive_types_schema", hive_types_schema);
}

MultiFileReaderOptions MultiFileReaderOptions::FormatDeserialize(FormatDeserializer &deserializer) {
	MultiFileReaderOptions result;
	deserializer.ReadProperty(100, "filename", result.filename);
	deserializer.ReadProperty(101, "hive_partitioning", result.hive_partitioning);
	deserializer.ReadProperty(102, "auto_detect_hive_partitioning", result.auto_detect_hive_partitioning);
	deserializer.ReadProperty(103, "union_by_name", result.union_by_name);
	deserializer.ReadProperty(104, "hive_types_autocast", result.hive_types_autocast);
	deserializer.ReadProperty(105, "hive_types_schema", result.hive_types_schema);
	return result;
}

void OrderByNode::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "type", type);
	serializer.WriteProperty(101, "null_order", null_order);
	serializer.WriteProperty(102, "expression", *expression);
}

OrderByNode OrderByNode::FormatDeserialize(FormatDeserializer &deserializer) {
	auto type = deserializer.ReadProperty<OrderType>(100, "type");
	auto null_order = deserializer.ReadProperty<OrderByNullType>(101, "null_order");
	auto expression = deserializer.ReadProperty<unique_ptr<ParsedExpression>>(102, "expression");
	OrderByNode result(type, null_order, std::move(expression));
	return result;
}

void PivotColumn::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "pivot_expressions", pivot_expressions);
	serializer.WriteProperty(101, "unpivot_names", unpivot_names);
	serializer.WriteProperty(102, "entries", entries);
	serializer.WriteProperty(103, "pivot_enum", pivot_enum);
}

PivotColumn PivotColumn::FormatDeserialize(FormatDeserializer &deserializer) {
	PivotColumn result;
	deserializer.ReadProperty(100, "pivot_expressions", result.pivot_expressions);
	deserializer.ReadProperty(101, "unpivot_names", result.unpivot_names);
	deserializer.ReadProperty(102, "entries", result.entries);
	deserializer.ReadProperty(103, "pivot_enum", result.pivot_enum);
	return result;
}

void ReadCSVData::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "files", files);
	serializer.WriteProperty(101, "csv_types", csv_types);
	serializer.WriteProperty(102, "csv_names", csv_names);
	serializer.WriteProperty(103, "return_types", return_types);
	serializer.WriteProperty(104, "return_names", return_names);
	serializer.WriteProperty(105, "filename_col_idx", filename_col_idx);
	serializer.WriteProperty(106, "options", options);
	serializer.WriteProperty(107, "single_threaded", single_threaded);
	serializer.WriteProperty(108, "reader_bind", reader_bind);
	serializer.WriteProperty(109, "column_info", column_info);
}

unique_ptr<ReadCSVData> ReadCSVData::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ReadCSVData>(new ReadCSVData());
	deserializer.ReadProperty(100, "files", result->files);
	deserializer.ReadProperty(101, "csv_types", result->csv_types);
	deserializer.ReadProperty(102, "csv_names", result->csv_names);
	deserializer.ReadProperty(103, "return_types", result->return_types);
	deserializer.ReadProperty(104, "return_names", result->return_names);
	deserializer.ReadProperty(105, "filename_col_idx", result->filename_col_idx);
	deserializer.ReadProperty(106, "options", result->options);
	deserializer.ReadProperty(107, "single_threaded", result->single_threaded);
	deserializer.ReadProperty(108, "reader_bind", result->reader_bind);
	deserializer.ReadProperty(109, "column_info", result->column_info);
	return result;
}

void SampleOptions::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "sample_size", sample_size);
	serializer.WriteProperty(101, "is_percentage", is_percentage);
	serializer.WriteProperty(102, "method", method);
	serializer.WriteProperty(103, "seed", seed);
}

unique_ptr<SampleOptions> SampleOptions::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<SampleOptions>(new SampleOptions());
	deserializer.ReadProperty(100, "sample_size", result->sample_size);
	deserializer.ReadProperty(101, "is_percentage", result->is_percentage);
	deserializer.ReadProperty(102, "method", result->method);
	deserializer.ReadProperty(103, "seed", result->seed);
	return result;
}

void StrpTimeFormat::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "format_specifier", format_specifier);
}

StrpTimeFormat StrpTimeFormat::FormatDeserialize(FormatDeserializer &deserializer) {
	auto format_specifier = deserializer.ReadProperty<string>(100, "format_specifier");
	StrpTimeFormat result(format_specifier);
	return result;
}

void TableFilterSet::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "filters", filters);
}

TableFilterSet TableFilterSet::FormatDeserialize(FormatDeserializer &deserializer) {
	TableFilterSet result;
	deserializer.ReadProperty(100, "filters", result.filters);
	return result;
}

void VacuumOptions::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "vacuum", vacuum);
	serializer.WriteProperty(101, "analyze", analyze);
}

VacuumOptions VacuumOptions::FormatDeserialize(FormatDeserializer &deserializer) {
	VacuumOptions result;
	deserializer.ReadProperty(100, "vacuum", result.vacuum);
	deserializer.ReadProperty(101, "analyze", result.analyze);
	return result;
}

} // namespace duckdb
