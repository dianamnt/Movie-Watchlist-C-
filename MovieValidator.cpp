#include "MovieValidator.h"

using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }{}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

void MovieValidator::validate(const Movie & m)
{
	vector<string> errors;
	if (m.getTitle().size() < 2)
		errors.push_back("The title name cannot be less than 1 character long!\n");
	if (!isupper(m.getTitle()[0]))
		errors.push_back(string("The title must begin with a capital letter!\n"));
	if (m.getDuration() == 0)
		errors.push_back(string("The duration cannot be 0!\n"));

	size_t posWww = m.getTrailer().find("www");
	size_t posHttp = m.getTrailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"\n");

	if (errors.size() > 0)
		throw MovieException(errors);
}