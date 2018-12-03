#pragma once
#include <string>
#include "Movie.h"
#include <vector>

class MovieException
{
private:
	std::vector<std::string> errors;

public:
	MovieException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class MovieValidator
{
public:
	MovieValidator() {}
	static void validate(const Movie& m);
};