Accessor
========

A C++ equivalent to the C# property [accessors](http://msdn.microsoft.com/en-us/library/aa287786(v=vs.71).aspx)

The accessor of an attribute contains the executable statements associated with getting or setting the attribute. 

The declarations takes the following forms:
```C
struct user
{
	accessor(int)
	{
		get
		{
			std::cout << "get: " << value << std::endl;
		}
		
		set
		{
			std::cout << "set: " << value << std::endl;
		}
	} age;
};
```c
When you reference the attribute, except as the target of an assignment, the get accessor is invoked to read the value of the attribute. For example:
```
int main()
{
	struct user user;

	user.age = 42; // the user.age set accessor is invoked here

	assert(user.age == 42); // and the get accessor is invoked here
}
```
