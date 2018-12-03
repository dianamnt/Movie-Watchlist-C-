#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryException.h"
#include <algorithm>

using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
	this->current = 0;
}

Movie Repository::getCurrentMovie(const std::string& genre)
{
	if (genre == "")
	{
		if (this->current == this->movies.size())
			this->current = 0;
		return this->movies[this->current];
		return Movie{};
	}
	else
	{
		if (this->current == this->movies.size())
			this->current = 0;
		std::vector<Movie> elems = this->getMovies();
		while (elems[this->current].getGenre() != genre)
		{
			if (this->current != this->movies.size())
			{
				this->current++;
				if (int(this->current) >= int(this->movies.size()))
					this->current = 0;
			}
			else
				return Movie{};
		}
		return elems[this->current];
	}
}

void Repository::play(const std::string& genre)
{
	if (this->movies.size() == 0)
		return;
	this->current = 0;
	Movie currentM = this->getCurrentMovie(genre);
	currentM.play();
}


void Repository::next(const std::string& genre)
{
	if (this->movies.size() == 0)
		return;
	this->current++;
	Movie currentM = this->getCurrentMovie(genre);
	currentM.play();
}

void Repository::addMovie(const Movie& m)
{
	if (this->findByTitleAndGenre(m.getTitle()).getTitle() != "")
		throw DuplicateMovieException();
	this->movies.push_back(m);
	this->writeToFile();
}

void Repository::removeMovie(const Movie& movie)
{
	if (this->findByTitleAndGenre(movie.getTitle()).getTitle() == "")
		throw MovieNotFoundException();

	int i;
	for(i=0;i<int(this->movies.size());i++)
		if (this->movies[i].getTitle() == movie.getTitle())
		{
			this->movies.erase(this->movies.begin() + i);
			break;
		}
	this->writeToFile();
}

void Repository::updateMovie(const Movie& movie)
{
	if (this->findByTitleAndGenre(movie.getTitle()).getTitle() == "")
		throw MovieNotFoundException();
	int i;
	for (i = 0; i<int(this->movies.size()); i++)
		if (this->movies[i].getTitle() == movie.getTitle())
		{
			this->movies[i].setGenre(movie.getGenre());
			this->movies[i].setYear(movie.getYear());
			this->movies[i].setLikes(movie.getLikes());
			this->movies[i].setTrailer(movie.getTrailer());
			this->movies[i].setDuration(movie.getDuration());
		}
	this->writeToFile();
}

Movie Repository::findByTitleAndGenre(const std::string& title)
{	
	for (auto m : this->movies)
	{
		if (m.getTitle() == title)
			return m;
	}

	return Movie{};
	
	/*
	auto it = std::find_if(this->movies.begin(), this->movies.end(), [&title](const Movie& obj) {return obj.getTitle() == title; });
	if (it == this->movies.end())
		return Movie{};
	return *it;
	*/
}

void Repository::readFromFile()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Movie m;
	while (file >> m)
		this->movies.push_back(m);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		file << m;
	}

	file.close();
}

