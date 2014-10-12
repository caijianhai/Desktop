
#ifndef __DYNFACTORY_H__
#define __DYNFACTORY_H__

#include <map>
#include <string>
using namespace std;

typedef void* (*FUNC)();

class DynFactory
{
public:
	static void* CreateObject(const string& name)
	{
		map< string, FUNC>::const_iterator it;
		
		it = mapcls_.find(name);

		if(it == mapcls_.end())
			return 0;
		else
			return it->second();
	}

	static void Register( const string& name, FUNC func)
	{
		mapcls_[name] = func;
	}
private:
	static map< string, FUNC> mapcls_;
};

// g++ 
// __attribute ((weak))
__declspec(selectany)map< string, FUNC> DynFactory::mapcls_;

class Register
{
public:
	Register( const string& name, FUNC func)
	{
		DynFactory::Register(name, func);
	}
};

#define FACTORY_REGISTER(class_name) \
class class_name##Register \
{\
public:\
	static void* newShareInce()\
	{\
		return new class_name;\
	}\
	static Register reg_;\
};\
Register class_name##Register::reg_(#class_name, class_name##Register::newShareInce)

#endif //__DYNFACTORY_H__