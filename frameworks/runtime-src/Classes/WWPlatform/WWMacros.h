#ifndef WWMACROS_H_
#define WWMACROS_H_
//静态单例方法 获取代理实例
#ifndef SINGLE_INSTANCE_FUNC
#define SINGLE_INSTANCE_FUNC(_CLASS_) \
	static _CLASS_* getInstance() \
{ \
	static _CLASS_* pRet = NULL; \
if (!pRet) pRet = new _CLASS_(); \
	return pRet; \
}
#endif //SINGLE_DELEGATE_INSTANCE_FUNC

#endif