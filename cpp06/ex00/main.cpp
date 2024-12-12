#include "Convernsion.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2)
	{
		std::cerr << LRED << "One Parameter required"<< RESET << std::endl;
		return 1;
	}
	Convernsion c = Convernsion(argv[1]);
	try{
		c.printOutput();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
