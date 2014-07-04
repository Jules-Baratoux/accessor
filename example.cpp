#include <iostream>
#include "accessor.hh"

struct Obj
{
	accessor(char)
	{
		get {
			std::cout << "get: " << value << std::endl;			
		}
		
		set {
			std::cout << "set: " << value << std::endl;			
		}
	} character;

	accessor(int)
	{
		get {
			std::cout << "get: " << value << std::endl;			
		}
		
		set {
			std::cout << "set: " << value << std::endl;			
		}

		friend Obj;			// make Obj a frient of the accessor
	} integer;

	int update_integer_value()
	{
		return (integer.value = 42);	// bypass the integer's set accessor
	}
};

#define print(var) std::cout << #var": " << var << std::endl;

int main()
{
	Obj obj;

	obj.character = 'c';
	print(obj.character);

	print( obj.update_integer_value() );
}
