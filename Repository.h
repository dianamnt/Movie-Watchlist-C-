#pragma once
#include "Movie.h"
#include <vector>

class Repository
{
private:

	std::vector<Movie> movies;
	std::string filename;
	int current;
public:
	Repository() {}

	Repository(const std::string& filename);

	/*
	Adds a movie to the list of movies
	*/
	void addMovie(const Movie& m);

	// Determines the current movie to show
	Movie getCurrentMovie(const std::string& genre);

	// Plays the first movie from the repository
	void play(const std::string& genre);

	// Plays the next movie
	void next(const std::string& genre);

	/*
	Removes a movie from the list of movies
	*/
	void removeMovie(const Movie& movie);

	/*
	Updates a movie from the list of movies
	*/
	void updateMovie(const Movie& movie);

	/*
	Finds a movie in the list of movies that has a given title and genre
	in: a given title and a given genre
	out: the found movie
	*/
	Movie findByTitleAndGenre(const std::string& title);
	

	std::vector<Movie> getMovies() const { return movies; }

private:
	void readFromFile();
	void writeToFile();
};