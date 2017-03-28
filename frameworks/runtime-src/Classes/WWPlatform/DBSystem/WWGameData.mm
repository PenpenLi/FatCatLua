
#include "platform/CCPlatformConfig.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

#import <Foundation/Foundation.h>

#include <string>
#import "WWGameData.h"
#import "external/tinyxml2/tinyxml2.h"
#import "platform/CCPlatformConfig.h"
#import "platform/CCPlatformMacros.h"
#import "base/base64.h"
#import "platform/CCFileUtils.h"

#define XML_FILE_NAME "WWGameData.xml"

// root name of xml
#define USERDEFAULT_ROOT_NAME    "GameDataRoot"

#define KEEP_COMPATABILITY

using namespace std;



/**
 * implements of WWGameData
 */

WWGameData* WWGameData::instance = nullptr;
string WWGameData::_filePath = string("");
bool WWGameData::_isFilePathInitialized = false;

#ifdef KEEP_COMPATABILITY
static tinyxml2::XMLElement* getXMLNodeForKey(const char* pKey, tinyxml2::XMLDocument **doc)
{
    tinyxml2::XMLElement* curNode = nullptr;
    tinyxml2::XMLElement* rootNode = nullptr;

    if (! WWGameData::isXMLFileExist())
    {
        return nullptr;
    }

    // check the key value
    if (! pKey)
    {
        return nullptr;
    }

    do
    {
 		tinyxml2::XMLDocument* xmlDoc = new (std::nothrow) tinyxml2::XMLDocument();
		*doc = xmlDoc;

        std::string xmlBuffer = FileUtils::getInstance()->getStringFromFile(WWGameData::getInstance()->getXMLFilePath());

		if (xmlBuffer.empty())
		{
            NSLog(@"can not read xml file");
			break;
		}
		xmlDoc->Parse(xmlBuffer.c_str(), xmlBuffer.size());

		// get root node
		rootNode = xmlDoc->RootElement();
		if (nullptr == rootNode)
		{
            NSLog(@"read root node error");
			break;
		}
		// find the node
		curNode = rootNode->FirstChildElement();
        if (!curNode)
        {
            // There is not xml node, delete xml file.
            remove(WWGameData::getInstance()->getXMLFilePath().c_str());

            return nullptr;
        }

		while (nullptr != curNode)
		{
			const char* nodeName = curNode->Value();
			if (!strcmp(nodeName, pKey))
			{
                // delete the node
				break;
			}

			curNode = curNode->NextSiblingElement();
		}
	} while (0);

	return curNode;
}

static void deleteNode(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* node)
{
    if (node)
    {
        doc->DeleteNode(node);
        doc->SaveFile(WWGameData::getInstance()->getXMLFilePath().c_str());
        delete doc;
    }
}

static void deleteNodeByKey(const char *pKey)
{
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    deleteNode(doc, node);
}
#endif

WWGameData::~WWGameData()
{
}

WWGameData::WWGameData()
{
}

bool WWGameData::getBoolForKey(const char* pKey)
{
    return getBoolForKey(pKey, false);
}

bool WWGameData::getBoolForKey(const char* pKey, bool defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            const char* value = (const char*)node->FirstChild()->Value();
            bool ret = (! strcmp(value, "true"));

            // set value in NSUserDefaults
            setBoolForKey(pKey, ret);
            flush();

            // delete xmle node
            deleteNode(doc, node);

            return ret;
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

    bool ret = defaultValue;

    NSNumber *value = [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithUTF8String:pKey]];
    if (value)
    {
        ret = [value boolValue];
    }

    return ret;
}

int WWGameData::getIntegerForKey(const char* pKey)
{
    return getIntegerForKey(pKey, 0);
}

int WWGameData::getIntegerForKey(const char* pKey, int defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            int ret = atoi((const char*)node->FirstChild()->Value());

            // set value in NSUserDefaults
            setIntegerForKey(pKey, ret);
            flush();

            // delete xmle node
            deleteNode(doc, node);

            return ret;
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

    int ret = defaultValue;

    NSNumber *value = [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithUTF8String:pKey]];
    if (value)
    {
        ret = [value intValue];
    }

    return ret;
}

float WWGameData::getFloatForKey(const char* pKey)
{
    return getFloatForKey(pKey, 0);
}

float WWGameData::getFloatForKey(const char* pKey, float defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            float ret = atof((const char*)node->FirstChild()->Value());

            // set value in NSUserDefaults
            setFloatForKey(pKey, ret);
            flush();

            // delete xmle node
            deleteNode(doc, node);

            return ret;
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

    float ret = defaultValue;

    NSNumber *value = [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithUTF8String:pKey]];
    if (value)
    {
        ret = [value floatValue];
    }

    return ret;
}

double  WWGameData::getDoubleForKey(const char* pKey)
{
    return getDoubleForKey(pKey, 0);
}

double WWGameData::getDoubleForKey(const char* pKey, double defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            double ret = atof((const char*)node->FirstChild()->Value());

            // set value in NSUserDefaults
            setDoubleForKey(pKey, ret);
            flush();

            // delete xmle node
            deleteNode(doc, node);

            return ret;
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

	double ret = defaultValue;

    NSNumber *value = [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithUTF8String:pKey]];
    if (value)
    {
        ret = [value doubleValue];
    }

    return ret;
}

std::string WWGameData::getStringForKey(const char* pKey)
{
    return getStringForKey(pKey, "");
}

string WWGameData::getStringForKey(const char* pKey, const std::string & defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            string ret = (const char*)node->FirstChild()->Value();

            // set value in NSUserDefaults
            setStringForKey(pKey, ret);
            flush();

            // delete xmle node
            deleteNode(doc, node);

            return ret;
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

    NSString *str = [[NSUserDefaults standardUserDefaults] stringForKey:[NSString stringWithUTF8String:pKey]];
    if (! str)
    {
        return defaultValue;
    }
    else
    {
        return [str UTF8String];
    }
}

Data WWGameData::getDataForKey(const char* pKey)
{
    return getDataForKey(pKey, Data::Null);
}

Data WWGameData::getDataForKey(const char* pKey, const Data& defaultValue)
{
#ifdef KEEP_COMPATABILITY
    tinyxml2::XMLDocument* doc = nullptr;
    tinyxml2::XMLElement* node = getXMLNodeForKey(pKey, &doc);
    if (node)
    {
        if (node->FirstChild())
        {
            const char * encodedData = node->FirstChild()->Value();
            unsigned char * decodedData;
            int decodedDataLen = base64Decode((unsigned char*)encodedData, (unsigned int)strlen(encodedData), &decodedData);

            if (decodedData) {
                Data ret;
                ret.fastSet(decodedData, decodedDataLen);

                // set value in NSUserDefaults
                setDataForKey(pKey, ret);

                flush();

                // delete xmle node
                deleteNode(doc, node);

                return ret;
            }
        }
        else
        {
            // delete xmle node
            deleteNode(doc, node);
        }
    }
#endif

    NSData *data = [[NSUserDefaults standardUserDefaults] dataForKey:[NSString stringWithUTF8String:pKey]];
    if (! data)
    {
        return defaultValue;
    }
    else
    {
        Data ret;
        ret.copy((unsigned char*)data.bytes, data.length);
        return ret;
    }
}

void WWGameData::setBoolForKey(const char* pKey, bool value)
{
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithBool:value] forKey:[NSString stringWithUTF8String:pKey]];
}

void WWGameData::setIntegerForKey(const char* pKey, int value)
{
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithInt:value] forKey:[NSString stringWithUTF8String:pKey]];
}

void WWGameData::setFloatForKey(const char* pKey, float value)
{
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithFloat:value] forKey:[NSString stringWithUTF8String:pKey]];
}

void WWGameData::setDoubleForKey(const char* pKey, double value)
{
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithDouble:value] forKey:[NSString stringWithUTF8String:pKey]];
}

void WWGameData::setStringForKey(const char* pKey, const std::string & value)
{
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSString stringWithUTF8String:value.c_str()] forKey:[NSString stringWithUTF8String:pKey]];
}

void WWGameData::setDataForKey(const char* pKey, const Data& value) {
#ifdef KEEP_COMPATABILITY
    deleteNodeByKey(pKey);
#endif

    [[NSUserDefaults standardUserDefaults] setObject:[NSData dataWithBytes: value.getBytes() length: value.getSize()] forKey:[NSString stringWithUTF8String:pKey]];
}

WWGameData* WWGameData::getInstance()
{
    if (! instance)
    {
#ifdef KEEP_COMPATABILITY
        initXMLFilePath();
#endif
        instance = new (std::nothrow) WWGameData();
    }

    return instance;
}

void WWGameData::destroyInstance()
{
    CC_SAFE_DELETE(instance);
}


bool WWGameData::isXMLFileExist()
{
    return FileUtils::getInstance()->isFileExist(_filePath);
}

void WWGameData::initXMLFilePath()
{
#ifdef KEEP_COMPATABILITY
    if (! _isFilePathInitialized)
    {
        // xml file is stored in cache directory before 2.1.2
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
        NSString *documentsDirectory = [paths objectAtIndex:0];
        _filePath = [documentsDirectory UTF8String];
        _filePath.append("/");

        _filePath +=  XML_FILE_NAME;
        _isFilePathInitialized = true;
    }
#endif
}

// create new xml file
bool WWGameData::createXMLFile()
{
    return false;
}

const string& WWGameData::getXMLFilePath()
{
    return _filePath;
}

void WWGameData::flush()
{
    [[NSUserDefaults standardUserDefaults] synchronize];
}





#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)