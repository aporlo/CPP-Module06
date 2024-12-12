#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <climits>
#include <cfloat>

# define LRED	"\033[0;91m"
# define RESET	"\033[0m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"

#define CHAR	1
#define INT		2
#define FLOAT	3
#define	DOUBLE	4

class Convernsion
{
private:
	std::string	_input;

public:
	Convernsion(std::string input);
	Convernsion(Convernsion const & src);
	~Convernsion(void);

	Convernsion &operator=(Convernsion const &ref );

	std::string	getInput(void) const;

	static bool checkNumber(std::string const s);
	static bool	checkLiteral(std::string const s, int type);
	static std::string	to_string(double d);

	void	printOutput(void);
	void	printChar(void);
	void	printInt(void);
	void	printDouble(void);
	void	printFloat(void);

};

#endif
