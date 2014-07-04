#pragma once
#define accessor_class(accessor, type)					\
	class accessor							\
	{								\
		type value;						\
									\
		accessor(const accessor&)	 = delete;		\
		type& operator=(const accessor&) = delete;		\
									\
		public:							\
		template <typename... Args>				\
		accessor(Args... args) : value() {}			\
									\
		inline operator const type& (void) const		\
		{							\
			__get();					\
			return value;					\
		}							\
									\
		inline accessor& operator=(const type & rhs)		\
		{							\
			value = rhs;					\
			__set();					\
			return *this;					\
		}							\
		enum

#define accessor_class_definition(NAME, ID, TYPE) accessor_class(NAME##ID, TYPE)
#define accessor_classname_gen(NAME, ID, TYPE)	  accessor_class_definition(NAME, ID, TYPE)
#define accessor(TYPE)				  accessor_classname_gen(accessor, __COUNTER__, TYPE)

#define get __dummy}; private:			\
	inline void __get (void) const

#define set					\
	inline void __set(void)
