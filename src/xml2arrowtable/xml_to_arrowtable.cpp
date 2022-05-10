#include "xml_to_arrowtable.h"
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;

XmlToArrowTable::XmlToArrowTable()
{}

XmlToArrowTable::~XmlToArrowTable()
{}

int XmlToArrowTable::execute()
{
	try {
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Error during initialization! :\n"
				<< message << "\n";
		XMLString::release(&message);
		return 1;
	}

	XercesDOMParser* parser = new XercesDOMParser();
	parser->setValidationScheme(XercesDOMParser::Val_Always);
	parser->setDoNamespaces(true);    // optional

	ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
	parser->setErrorHandler(errHandler);

	char xmlFile[] = "/root/worldquant/sample.xml";

	try {
		parser->parse(xmlFile);
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n"
				<< message << "\n";
		XMLString::release(&message);
		return -1;
	}
	catch (const DOMException& toCatch) {
		char* message = XMLString::transcode(toCatch.msg);
		cout << "Exception message is: \n"
				<< message << "\n";
		XMLString::release(&message);
		return -1;
	}
	catch (...) {
		cout << "Unexpected Exception \n" ;
		return -1;
	}

	delete parser;
	delete errHandler;

	XMLPlatformUtils::Terminate();

	return 0;
}
