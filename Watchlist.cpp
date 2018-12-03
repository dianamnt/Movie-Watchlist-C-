#include "Watchlist.h"
#include "RepositoryException.h"

void Watchlist::add(const Movie& movie)
{
	this->movies.push_back(movie);
}

void Watchlist::remove(const Movie& movie, int like)
{
	if (this->findByTitleAndGenre(movie.getTitle()).getTitle() == "")
		throw MovieNotFoundException();
	
	int i;
	for (i = 0; i<int(this->movies.size()); i++)
		if (this->movies[i].getTitle() == movie.getTitle())
		{
			this->movies.erase(this->movies.begin() + i);
			break;
		}
}

Movie Watchlist::findByTitleAndGenre(const std::string& title)
{
	for (auto m : this->movies)
	{
		if (m.getTitle() == title)
			return m;
	}

	return Movie{};
}