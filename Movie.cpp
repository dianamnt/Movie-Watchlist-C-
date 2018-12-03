#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>

using namespace std;

Movie::Movie() :title(""), genre(""), year(0), likes(0), trailer("") {}

Movie::Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
	this->duration = duration;
}
/*
int Movie::operator<(int x)
{
	if (this->duration < x)
		return 1;
	else
		return 0;
}
*/
void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator>>(istream & is, Movie & m)
{
	string line;
	getline(is, line);
	
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6)
		return is;

	m.title = tokens[0];
	m.genre = tokens[1];
	m.year = stod(tokens[2]);
	m.likes = stod(tokens[3]);
	m.trailer = tokens[4];
	m.duration = stod(tokens[5]);

	return is;

}

ostream & operator<<(ostream & os, const Movie & m)
{
	os << m.title << "," << m.genre << "," << m.year << "," << m.likes << "," << m.trailer << "," << m.duration<<"\n";
	return os;
}