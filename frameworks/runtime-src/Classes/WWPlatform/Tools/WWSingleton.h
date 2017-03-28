#ifndef _WWSINGLETON_H_
#define _WWSINGLETON_H_

template<typename T>
class WWSingleton
{
public:
	static T* getInstance();
	void drop();

protected:
	static T* _instance;
public:
	WWSingleton();
};
template <typename T>
T* WWSingleton<T>::getInstance()
{
	if (!_instance)
		_instance = new T;
	return _instance;
}
template<typename T>
void WWSingleton<T>::drop()
{
	if (_instance)
		delete _instance;
}
template<typename T>
WWSingleton<T>::WWSingleton()
{

}
template<typename T> T* WWSingleton<T>::_instance = 0;
#endif