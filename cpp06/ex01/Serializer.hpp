#ifndef SERIALIZER_H
# define SERIALIZER_H


#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
	std::string		name;
	int			height;
};

class Serializer
{

public:
	Serializer();
	~Serializer();

	Serializer& operator=(const Serializer& ref);
	Serializer(const Serializer &ref);


	static uintptr_t serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);

};

#endif
