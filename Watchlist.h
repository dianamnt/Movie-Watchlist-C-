#pragma once
//#include "DynamicVector.h"
#include "Repository.h"
#include<vector>
#include "Movie.h"

class Watchlist
{
protected:
	std::vector<Movie> movies;
	//Repository repo;

public:
	Watchlist() {}

	//Watchlist(const Repository& r) : repo{ r } {}

	// Adds a movie to the watchlist
	void add(const Movie& movie);

	// Deletes a movie from the watchlist
	void remove(const Movie& movie, int like);

	//Finds a movie by title
	Movie findByTitleAndGenre(const std::string& title);

	std::vector<Movie> getMovies() const { return movies; }
};