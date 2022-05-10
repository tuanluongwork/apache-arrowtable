#include "xml_to_arrowtable.h"
#include "arrow/json/api.h"

XmlToArrowTable::XmlToArrowTable()
{

}

XmlToArrowTable::~XmlToArrowTable()
{

}

int XmlToArrowTable::execute()
{
	/*arrow::Status st;
	arrow::MemoryPool* pool = default_memory_pool();
	std::shared_ptr<arrow::io::InputStream> input = ...;

	auto read_options = arrow::json::ReadOptions::Defaults();
	auto parse_options = arrow::json::ParseOptions::Defaults();

	// Instantiate TableReader from input stream and options
	std::shared_ptr<arrow::json::TableReader> reader;
	st = arrow::json::TableReader::Make(pool, input, read_options, parse_options, &reader);
	if (!st.ok()) {
		// Handle TableReader instantiation error...
	}

	std::shared_ptr<arrow::Table> table;
	// Read table from JSON file
	st = reader->Read(&table);
	if (!st.ok()) {
		// Handle JSON read error
		// (for example a JSON syntax error or failed type conversion)
	}*/

	return 0;
}
