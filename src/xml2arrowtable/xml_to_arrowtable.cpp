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
	parser->setDoNamespaces(true);

	ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
	parser->setErrorHandler(errHandler);

	char xmlFile[] = "/root/worldquant/sample.xml";

	try {
		parser->parse(xmlFile);

		//create unicode strings to for later use
        XMLCh *book = XMLString::transcode("book");
        XMLCh *category = XMLString::transcode("category");
        XMLCh *title = XMLString::transcode("title");
        XMLCh *author = XMLString::transcode("author");
        XMLCh *editions = XMLString::transcode("editions");
        XMLCh *edition = XMLString::transcode("edition");
        XMLCh *isbn = XMLString::transcode("isbn");
        XMLCh *year = XMLString::transcode("year");
        XMLCh *price = XMLString::transcode("price");

		DOMDocument *doc = parser->getDocument();
		DOMNodeList *bookList = doc->getElementsByTagName(book);
		XMLSize_t bookLen = bookList->getLength();
		
		for (XMLSize_t i = 0; i < bookLen; i++) {
			DOMNode *bookNode = bookList->item(i);
			cout << "category: " << XMLString::transcode(bookNode->getAttributes()->getNamedItem(category)->getTextContent()) << endl;
			DOMElement *bookElm = dynamic_cast<DOMElement*>(bookNode);

			cout << "\ttitle: " << XMLString::transcode(bookElm->getElementsByTagName(title)->item(0)->getTextContent()) << endl;
			cout << "\tauthor: " << XMLString::transcode(bookElm->getElementsByTagName(author)->item(0)->getTextContent()) << endl;
			DOMNodeList *editionList = bookElm->getElementsByTagName(edition);
			XMLSize_t editionLen = editionList->getLength();
			for (XMLSize_t j = 0; j < editionLen; j++) {
				DOMNode *editionNode = editionList->item(j);
				DOMElement *editionElm = dynamic_cast<DOMElement*>(editionNode);

				if (editionElm->getElementsByTagName(isbn)->getLength() > 0) {
					cout << "\t\tisbn: " << XMLString::transcode(editionElm->getElementsByTagName(isbn)->item(0)->getTextContent()) << endl;
				}
				cout << "\t\tyear: " << XMLString::transcode(editionElm->getElementsByTagName(year)->item(0)->getTextContent()) << endl;
				cout << "\t\tprice: " << XMLString::transcode(editionElm->getElementsByTagName(price)->item(0)->getTextContent()) << endl;
			}
		}

		/*DOMElement* elementRoot = doc->getDocumentElement();

		// Extract floats
		DOMElement* floatRoot = (DOMElement *) 
			elementRoot->getElementsByTagName(XMLString::transcode("book"))->item(0);
		DOMElement* child = floatRoot->getFirstElementChild();
		do{
			cout << "2\n";
			cout << XMLString::transcode(child->getNodeName()) << endl
			<< XMLString::transcode(child->getTextContent()) << endl;
			child = child->getNextElementSibling();
		}while(child != NULL);
		
		//create unicode strings to for later use
        XMLCh *spdName = XMLString::transcode("speed_result");
        XMLCh *memName = XMLString::transcode("memory_result");
        XMLCh *sectName = XMLString::transcode("section_list");

        //go through the nodelist finding the top level child nodes and assign them to the right member variables
        for(XMLSize_t i=0; i<len; i++){
			cout << "1.1\n";

            DOMNode *curNode = nlist->item(i);
            DOMElement *curElm;
			cout << "1.2\n";

            //safely check for element node before casting
            if(curNode->getNodeType() == DOMNode::ELEMENT_NODE){
				cout << "1.3\n";
                curElm = dynamic_cast<DOMElement*>(curNode);
            }

            //check the tag name and assign accordingly
            if(XMLString::equals(spdName, curElm->getTagName())){
                spdResult = curElm;
            }
            else if(XMLString::equals(memName, curElm->getTagName())){
                memResult = curElm;
            }
            else if(XMLString::equals(sectName, curElm->getTagName())){
                sectList = curElm;
            }
			cout << curNode->getNodeName() << " " << curNode->getNodeValue() << endl;
        }
		cout << "2\n";

        //release the memory occupied by the encoded strings
        XMLString::release(&spdName);
        XMLString::release(&memName);
        XMLString::release(&sectName);*/
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
