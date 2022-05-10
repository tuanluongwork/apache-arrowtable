project(XmlToArrowTable)

add_executable(xml_to_arrowtable
	main.cpp
	xml_to_arrowtable.cpp)

target_link_libraries(xml_to_arrowtable
	PRIVATE arrow_shared
	${XercesC_LIBRARIES})