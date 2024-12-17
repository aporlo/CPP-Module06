#include "Serializer.hpp"

int	main(void) {
	Data*	data = new Data;

	data->name = "Aporlo";
	data->height = 154;

	std::cout << "Original Address: " << data << std::endl;
	std::cout << "name: " << data->name << std::endl;
	std::cout << "height: " << data->height << std::endl;

	std::cout << "---------------------------------------------------------------------" << std::endl;

	std::cout << "After deserialize Adress: " << Serializer::deserialize(Serializer::serialize(data))  << std::endl;
	std::cout << "Name: " <<  Serializer::deserialize(Serializer::serialize(data))->name << std::endl;
	std::cout << "Height: " << Serializer::deserialize(Serializer::serialize(data))->height << std::endl;


	delete data;
	return 0;
}
