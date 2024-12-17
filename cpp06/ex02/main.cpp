#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base *base[5];
	for (int i = 0; i < 5; i++)
	{
		base[i] = generate();
		if (base[i] == NULL)
			return (1);
		else
		{
			std::cout << i << " * = "; identify(base[i]);
			std::cout << i << " & = "; identify(*base[i]);
			delete (base[i]);

			std::cout << std::endl;
		}
	}
	return (0);
}
