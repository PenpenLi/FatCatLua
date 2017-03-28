#include "MsgLuaFilter.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

#include "cocos2d.h"
USING_NS_CC; 

static MsgLuaFilter* instance = nullptr;
//int loopCount = 0;
void iteratorVector( vector<MsgInfo>& msgInfo, const cocos2d::ValueVector& vec);
void iteratorVector1( vector<MsgInfo>& msgInfo, const cocos2d::ValueVector& vec, const char *parentLoopName);

void buffToLuaDic(vector<MsgInfo>& msgInfos,cocos2d::LuaValueDict& dic, WWBuffer* buffer,int lastLoopCount);

void iteratorVector(vector<MsgInfo>& msgInfos, const cocos2d::ValueVector& vec)
{
	for (auto v : vec)
	{
		//CCLOG("-->%d", v.getType());
		switch (v.getType())
		{
		case cocos2d::Value::Type::VECTOR:

			// v  {"int","type"}

			if (v.getType() == cocos2d::Value::Type::VECTOR)
			{
				auto keyv = v.asValueVector();
				auto type = keyv.at(0).asString();
				if (type.compare("loop") == 0 || type.compare("Loop") == 0)
				{
					//如果是循环

					iteratorVector1(msgInfos, keyv, nullptr);
				} else
				{
					auto value = keyv.at(1).asString();
					//CCLOG("%s=%s", type.c_str(), value.c_str());
					MsgInfo minfo;
					minfo.mType = TYPE_NORMAL;
					minfo.kType = type;
					minfo.kName = value;
					msgInfos.push_back(minfo);
				}


			}




			break;
		case cocos2d::Value::Type::MAP:
			for (auto v2 : v.asValueMap())
			{
				//CCLOG("MAP-->%d", v.getType());

			}

			break;
		default:
			break;
		}


	}
}
//从第三个位置开始
void iteratorVector1(vector<MsgInfo>& msgInfos, const cocos2d::ValueVector& keyv, const char *parentLoopName)
{
	int len = keyv.size();

	auto loopKeyv = keyv.at(1).asValueVector();
	auto looperKeyType = loopKeyv.at(0).asString();
	auto looperKeyName = loopKeyv.at(1).asString();
//	CCLOG("loop --->type:%s  name:%s", looperKeyType.c_str(), looperKeyName.c_str());
	if (parentLoopName)
	{
	//	CCLOG("parentLoopName:%s", parentLoopName);
	}

	//从第三个位置开始
	cocos2d::ValueVector tempvalue;
	MsgInfo minfo;
	minfo.mType = TYPE_LOOP;
	minfo.kName = looperKeyName;
	minfo.kType = looperKeyType;
	if (loopKeyv.size()>=3)
	{
		minfo.kCountName = loopKeyv.at(2).asString();
	}
	for (int i = 2; i < len; i++)
	{
		tempvalue = keyv.at(i).asValueVector();

		auto key = tempvalue.at(0).asString();

		if (key.compare("loop") == 0 || key.compare("Loop") == 0)
		{
			std::string pNamepName = looperKeyName.c_str();
			if (parentLoopName)
			{
				//几重循环
				pNamepName = StringUtils::format("%s.%s", parentLoopName, looperKeyName.c_str());
			}

			iteratorVector1(minfo.msgInfo, tempvalue, pNamepName.c_str());
		} else
		{
			auto value = tempvalue.at(1).asString();
			//CCLOG("loop %s %s=%s", looperKeyName.c_str(), key.c_str(), value.c_str());
			//把 key  value  加入到对应的数组中去
			MsgInfo minfo0;
			minfo0.kType = key;
			minfo0.kName = value;
			minfo0.mType = TYPE_NORMAL;
			minfo.msgInfo.push_back(minfo0);
		}
	}

	//minfo 是个循环 放入对应的 位置
	msgInfos.push_back(minfo);
}

void buffToLuaDic(vector<MsgInfo>& msgInfos, cocos2d::LuaValueDict& dic, WWBuffer* buffer, int lasLoopCount)
{
	auto loopCount = lasLoopCount;
	int curInfoIndex = 0;
	for (auto& msginfo:msgInfos)
	{
		curInfoIndex++;
		cocos2d::LuaValue value;
		switch (msginfo.mType)
		{
		case TYPE_NORMAL:
		{
			if (msginfo.kType.compare("char") == 0)
			{
				auto data = buffer->readChar();
				value = LuaValue::intValue(data);
				//CCLOG("%s get data %d", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("string") == 0)
			{
				auto data = buffer->readLengthAndString();
				value = LuaValue::stringValue(data.c_str());
				//CCLOG("%s get data %s |%s", msginfo.kName.c_str(), data.c_str(), value.stringValue().c_str());
			}
			else if (msginfo.kType.compare("short") == 0)
			{
				auto data = buffer->readShort();
				value = LuaValue::intValue(data);
				//CCLOG("%s get data %d", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("int") == 0)
			{
				auto data = buffer->readInt();
				value = LuaValue::intValue(data);
				//CCLOG("%s get data %d", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("long long") == 0)
			{
				auto data = buffer->readLongLong();
				value = LuaValue::floatValue(data);
				//CCLOG("%s get data %ld", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("float") == 0)
			{
				auto data = buffer->readFloat();
				value = LuaValue::floatValue(data);
				//CCLOG("%s get data %d", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("double") == 0)
			{
				auto data = buffer->readDouble();
				value = LuaValue::floatValue(data);
				//CCLOG("%s get data %.2f", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("bool") == 0)
			{
				auto data = buffer->readBoolean();
				value = LuaValue::booleanValue(data);
				//CCLOG("%s get data %d", msginfo.kName.c_str(), data);
			}
			else if (msginfo.kType.compare("icondata") == 0)
			{
				//CCLOG("unsupport conversion from wwbuffer to lua object");
				value = LuaValue::ccobjectValue(buffer->readLengthAndData(), "ww.WWBuffer");
			}
			else if (msginfo.kType.compare("byteArray")==0)
			{
				auto wwbufer = buffer->readLengthAndData();
				char *data = wwbufer->data();
				auto len = wwbufer->length();
				std::string str;
				for (int i = 0; i < len;i++) 
				{
					char c = *(data + i);
					str.append(1, c + 48);
				}
				CC_SAFE_DELETE(wwbufer);
				value = LuaValue::stringValue(str);
			}
			dic.emplace(std::make_pair(msginfo.kName,value));
		}
			break;
		case TYPE_LOOP:
		{
			
			cocos2d::LuaValueArray arr;
			if (msginfo.kType.compare("char")==0)
			{
				loopCount = buffer->readChar();
			} 
			else if (msginfo.kType.compare("short") == 0)
			{
				loopCount = buffer->readShort();
			}
			else if (msginfo.kType.compare("int") == 0)
			{
				loopCount = buffer->readInt();
			}
			else if (msginfo.kType.compare("none") == 0 || msginfo.kType.compare("null") == 0)
			{
				//none null 表示这个循环的次数是前一个循环的次数
				//loopCount = lasLoopCount;
				//这个地方找上一个loop的count
				if (curInfoIndex>0) 
				{
					for (int i = curInfoIndex - 1; i--; i >= 0)
					{
						if (msgInfos.at(i).mType == TYPE_LOOP && dic.find(msgInfos.at(i).kName) != dic.end())
						{
							loopCount = dic.at(msgInfos.at(i).kName).arrayValue().size();
							break;
						}

					}
				}
				

			}
			//CCLOG("%s get loop count %d", msginfo.kName.c_str(), loopCount);
			for (int i = 0; i < loopCount;i++) 
			{
				cocos2d::LuaValue value2;
				cocos2d::LuaValueDict dic2;
				buffToLuaDic(msginfo.msgInfo, dic2, buffer, loopCount);
				value2 = LuaValue::dictValue(dic2);
				arr.push_back(value2);
			}
			value = LuaValue::arrayValue(arr);
			if (msginfo.kCountName.length()>0)
			{
				dic.emplace(std::make_pair(msginfo.kCountName, LuaValue::intValue(loopCount)));
			}
			
			dic.emplace(std::make_pair(msginfo.kName, value));

		}
			break;
		default:
			break;
		}
	}
	
}

MsgLuaFilter* MsgLuaFilter::getInstance()
{
	if (!instance)
	{
		instance = new MsgLuaFilter();
	}
	return instance;
}

void MsgLuaFilter::deleteInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

bool MsgLuaFilter::onMessageReceived0(int msgType, WWBuffer* oBuffer)
{
	//是否有配置，有就在子线程，否则主线程调回lua

	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
	lua_State* L = stack->getLuaState();

	for (int i = 0; i < m_arrMsgId.size(); i++)
	{
		int msg = m_arrMsgId.at(i);
		if (msg == msgType)
		{
			cocos2d::log("send message to lua message id: %x", msg);

			lua_getglobal(L, "wawaOnMessage");
			stack->pushObject(oBuffer, "ww.WWBuffer");
			stack->executeFunction(1);


			if (msg == 0x010108 || msg == 0x40401)
			{

			}

			return true;
		}
	}

	return false;
}

bool MsgLuaFilter::onMessageReceived1(int msgType, WWBuffer* oBuffer)
{
	cocos2d::LuaValueDict dic;
	auto msfinfos = m_arrMsgInfo.at(msgType);
	auto msgId = oBuffer->readChar3ToInt();//先把消息头读出来
	buffToLuaDic(msfinfos,dic, oBuffer,0);

	//oBuffer->resetReaderIndex();
	//int len = oBuffer->getReadableSize();
	//WWPlayBack::getInstance()->pushNetData(oBuffer->readWholeData(), len);
	oBuffer->toRelease();

	//接下来在主线程里边调用
	Director::getInstance()->getScheduler()->performFunctionInCocosThread([this, msgType, dic]()
	{

		LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
		lua_State* L = stack->getLuaState();
		for (int i = 0; i < m_arrMsgId.size(); i++)
		{
			int msg = m_arrMsgId.at(i);
			if (msg == msgType)
			{
				cocos2d::log("send bind message to lua message id: %x", msg);

				lua_getglobal(L, "wawaOnInfoMessage");
				stack->pushInt(msgType);
				stack->pushLuaValueDict(dic);
				stack->executeFunction(2);
				
			}
		}

	});
	return true;
}


bool MsgLuaFilter::onMessageReceived(int msgType, WWBuffer* oBuffer)
{
	//是否有配置，有就在子线程，否则主线程调回lua
	if (m_arrMsgInfo.find(msgType) == m_arrMsgInfo.end())
	{
		//不存在
		Director::getInstance()->getScheduler()->performFunctionInCocosThread([this,msgType, oBuffer]()
		{
			this->onMessageReceived0(msgType, oBuffer);
			oBuffer->toRelease();
		});
	} 
	else
	{
		this->onMessageReceived1(msgType, oBuffer);
	}
	return true;
}

bool MsgLuaFilter::onRootMessageReceived(int msgType, WWBuffer* oBuffer)
{
	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
	lua_State* L = stack->getLuaState();

	for (int i = 0; i < m_arrRootMsgId.size(); i++)
	{
		int msg = m_arrRootMsgId.at(i);
		if (msg == msgType)
		{
			cocos2d::log("send root message to lua message id: %x", msg);

			lua_getglobal(L, "wawaOnRootMessage");
			stack->pushObject(oBuffer, "ww.WWBuffer");
			stack->executeFunction(1);
	
			return true;
		}
	}

	return false;
}

void MsgLuaFilter::onNetEvent(const NetEvent& netEvent, const cocos2d::LuaValue& value)
{
	for (int msgid : m_arrEventId)
	{
		if (msgid == netEvent)
		{
			Director::getInstance()->getScheduler()->performFunctionInCocosThread([netEvent, value]()
			{
				LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
				lua_State* L = stack->getLuaState();
				lua_getglobal(L, "wawaOnNetEvent");
				//stack->pushObject(oBuffer, "ww.WWBuffer");
				stack->pushInt(netEvent);
				stack->pushLuaValue(value);
				stack->executeFunction(2);
			});
			break;
		}
	}
}
void MsgLuaFilter::onUpdateEvent(UpgradeEvent upevent, cocos2d::LuaValue& value)
{
	for (int msgid:m_arrUpgradeId)
	{

		if (msgid==upevent) 
		{
			Director::getInstance()->getScheduler()->performFunctionInCocosThread([upevent, value]()
			{
				LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
				lua_State* L = stack->getLuaState();
				lua_getglobal(L, "wawaOnUpgradeEvent");
				//stack->pushObject(oBuffer, "ww.WWBuffer");
				stack->pushInt(upevent);
				stack->pushLuaValue(value);
				stack->executeFunction(2);
			});
		}
	}
	
}

void MsgLuaFilter::registerMsgId(int msg)
{
	auto iter = std::find(m_arrMsgId.begin(), m_arrMsgId.end(), msg);
	if (iter == m_arrMsgId.end())
	{
		m_arrMsgId.push_back(msg);
	}
	
}

void MsgLuaFilter::bindMsgId(int msg, cocos2d::ValueVector& vec /* = nullptr */)
{
	if (m_arrMsgInfo.find(msg) == m_arrMsgInfo.end())
	{
		vector<MsgInfo> msgInfo;
		iteratorVector(msgInfo,vec);
		m_arrMsgInfo.emplace(std::make_pair(msg, msgInfo));
	}
	
	
	
}

void MsgLuaFilter::unRegisterMsgId(int msg)
{
	auto iter = std::find(m_arrMsgId.begin(), m_arrMsgId.end(), msg);
	if (iter != m_arrMsgId.end())
	{
		m_arrMsgId.erase(iter);
	}
	if (m_arrMsgInfo.find(msg) != m_arrMsgInfo.end()) 
	{
		m_arrMsgInfo.erase(m_arrMsgInfo.find(msg));
	}
	
}

void MsgLuaFilter::clearMsgId()
{
	m_arrMsgId.clear();
	m_arrMsgInfo.clear();
}

void MsgLuaFilter::registerRootMsgId(int msg)
{
	auto iter = std::find(m_arrRootMsgId.begin(), m_arrRootMsgId.end(), msg);
	if (iter == m_arrRootMsgId.end())
	{
		m_arrRootMsgId.push_back(msg);
	}
}

void MsgLuaFilter::unRegisterRootMsgId(int msg)
{
	auto iter = std::find(m_arrRootMsgId.begin(), m_arrRootMsgId.end(), msg);
	if (iter != m_arrRootMsgId.end())
	{
		m_arrRootMsgId.erase(iter);
	}
}

void MsgLuaFilter::clearRootMsgId()
{
	m_arrRootMsgId.clear();
}

void MsgLuaFilter::registerGlobalMsgId(int msg)
{
	auto iter = std::find(m_arrGlobalMsgId.begin(), m_arrGlobalMsgId.end(), msg);
	if (iter == m_arrGlobalMsgId.end())
	{
		m_arrGlobalMsgId.push_back(msg);
	}
}

void MsgLuaFilter::unRegisterGlobalMsgId(int msg)
{
	auto iter = std::find(m_arrGlobalMsgId.begin(), m_arrGlobalMsgId.end(), msg);
	if (iter != m_arrGlobalMsgId.end())
	{
		m_arrGlobalMsgId.erase(iter);
	}
}

void MsgLuaFilter::clearGlobalMsgId()
{
	m_arrGlobalMsgId.clear();
}

void MsgLuaFilter::registerNetEventId(int msg)
{
	auto iter = std::find(m_arrEventId.begin(), m_arrEventId.end(), msg);
	if (iter == m_arrEventId.end())
	{
		m_arrEventId.push_back(msg);
	}	
}
void MsgLuaFilter::unRegisterNetEventId(int msgId)
{
	auto iter = std::find(m_arrEventId.begin(), m_arrEventId.end(), msgId);
	if (iter != m_arrEventId.end())
	{
		m_arrEventId.erase(iter);
	}	
}

void MsgLuaFilter::clearNetEventId()
{
	m_arrEventId.clear();
}
void MsgLuaFilter::registerUpgradeEventId(int msg)
{
	if (std::find(m_arrUpgradeId.begin(), m_arrUpgradeId.end(), msg) == m_arrUpgradeId.end())
	{
		m_arrUpgradeId.push_back(msg);
	}
}

void MsgLuaFilter::unRegisterUpgradeEvent(int msg)
{
	auto iter = std::find(m_arrUpgradeId.begin(), m_arrUpgradeId.end(), msg);
	if (iter != m_arrUpgradeId.end())
	{
		m_arrUpgradeId.erase(iter);
	}
}
void MsgLuaFilter::clearUpgradeEvent()
{
	m_arrUpgradeId.clear();
}