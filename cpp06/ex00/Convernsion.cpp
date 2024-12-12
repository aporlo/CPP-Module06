#include "Convernsion.hpp"

Convernsion::Convernsion(std::string input): _input(input) {}

Convernsion::Convernsion(Convernsion const & src)
{
	*this = src;
}

Convernsion & Convernsion::operator=(Convernsion const & ref)
{
	if (this != &ref){}
		return *this;
	this->_input = ref._input;
	return *this;
}

Convernsion::~Convernsion() {}

std::string	Convernsion::getInput() const {
	return this->_input;
}

std::string	Convernsion::to_string(double d) {
	std::ostringstream s;
	s << d;
	return s.str();
}

bool	Convernsion::checkNumber(std::string s)
{
	if(s.find_first_of(".") != s.find_last_of(".") ||
		isdigit(s[s.find_first_of(".") + 1]) == false ||
		s.find_first_of(".") == 0 ||
		s.find_first_of("f") != s.find_last_of("f") ||
		s.find_first_of("+-") != s.find_last_of("+-"))
			return false;
	 else
			return true;
}

bool	Convernsion::checkLiteral(std::string s, int type)
{
	switch (type)
	{
		case CHAR:
		case INT:
			if ((s == "nan" || s == "-inf" || s == "+inf" || s== "-inff" || s == "+inff"))
				return true;
			return false;
		case FLOAT:
			if (s == "nanf" || s == "-inff" || s == "+inff")
				return true;
			return false;
		case DOUBLE:
			if (s == "nan" || s == "-inf" || s == "+inf")
				return true;
			return false;
	}
	return false;
}

void	Convernsion::printOutput(void)
{
	this->printChar();
	this->printInt();
	this->printDouble();
	this->printFloat();
}

void	Convernsion::printChar(void)
{
	int	i;

	std::istringstream(this->_input) >> i;
	if (this->checkLiteral(this->_input, CHAR) || i < 0 || i > 128 )
		std::cout << "char: imposible" << std::endl;
	else if (i < 32 || i > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << (char) i << "'" << std::endl;

}


void	Convernsion::printInt() {
	double d;

	std::istringstream(this->_input) >> d;
	if (this->checkLiteral(this->_input, INT) ||
		(d == 0 && this->_input != "0") ||
		d < INT_MIN || d > INT_MAX ||
		!this->checkNumber(this->_input))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int) d << std::endl;
}

void	Convernsion::printDouble(void) {
	long double dd;

	std::istringstream(this->_input) >> dd;
	if (this->checkLiteral(this->_input, DOUBLE))
		std::cout << "double: " << this->getInput() <<std::endl;
	else if ((dd != 0 && (dd < DBL_MIN ||dd > DBL_MAX)) || !this->checkNumber(this->_input))
		std::cout << "double: impossible" << std::endl;
	else if (to_string((double) dd).find(".") != std::string::npos)
		std::cout << "double: " <<(double) dd << std::endl;
	else
		std::cout << "double: " << (double) dd << ".0" <<std::endl;
}


void	Convernsion::printFloat(void) {
	double d;

	std::istringstream(this->_input) >> d;
	if (this->checkLiteral(this->_input, DOUBLE))
		this->_input += "f";
	if (this->checkLiteral(this->_input, FLOAT))
		std::cout << "float: " << this->getInput() << std::endl;
	else if ((d !=0 && (d < FLT_MIN || d > FLT_MAX )) || !this->checkNumber(this->_input))
		std::cout << "float: impossible" << std::endl;
	else if (to_string(d).find(".") != std::string::npos)
		std::cout << "float: " << (float) d << "f" << std::endl;
	else
		std::cout << "float: " << (float) d << ".0f" << std::endl;
}


