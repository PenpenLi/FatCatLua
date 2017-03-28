#ifndef _WWMAPFORVALUEFINDER_
#define _WWMAPFORVALUEFINDER_
#include <string>
#include <map>
#include <algorithm>


class WWMapForValueFinderInt
{
public:
	
	WWMapForValueFinderInt(const int &cmp_value) :m_s_cmp_value(cmp_value){};
	
	
	bool operator ()(std::map<const int,int>::value_type &pair)
	{
		return pair.second == m_s_cmp_value;
	};

private:
	const int &m_s_cmp_value;
};

#endif