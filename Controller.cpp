#include "Controller.h"
#include "RepositoryException.h"
#include <iostream>
using namespace std;

void Controller::addMovieToWatchlist(const Movie& movie)
{
		this->watch->add(movie);	
		this->html->add(movie);
}

void Controller::removeMovieFromWatchlist(const std::string&title, int like)
{
	Movie movie{ title,"",0,0,"",0 };
	Movie m = this->repo.findByTitleAndGenre(movie.getTitle());
	if (like == 1)
	{
		int c = m.getLikes() + 1;
		m.setLikes(c);

	}
	this->repo.updateMovie(m);

	this->watch->remove(m, like);
	this->html->remove(m, like);
}


void Controller::startRepository(const std::string& genre)
{
	this->repo.play(genre);
}

void Controller::nextMovieRepository(const std::string& genre)
{
	this->repo.next(genre);
}

void Controller::addMovieToRepo(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
	Movie m{ title,genre,year,likes,trailer,duration };
	this->validator.validate(m);
	this->repo.addMovie(m);
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, m));
	//this->redoActions.push_back(std::make_unique<RedoAdd>(this->repo, m));
}


void Controller::removeMovieFromRepo(const std::string& title)
{
	Movie m{ title,"",0,0,"www",1 };
	this->validator.validate(m);
	Movie mo = this->repo.findByTitleAndGenre(title);
	this->repo.removeMovie(m);
	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, mo));
	//this->redoActions.push_back(std::make_unique<RedoRemove>(this->repo, m));
}

void Controller::updateMovieRepo(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
	Movie m{ title,genre,year,likes,trailer, duration };
	Movie mo = this->repo.findByTitleAndGenre(title);
	this->validator.validate(m);
	this->repo.updateMovie(m);
	this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, mo, m));
	//this->redoActions.push_back(std::make_unique<RedoUpdate>(this->repo, m));
}

void Controller::saveWatchlist()
{
	if (this->watch == nullptr)
		return;
	this->watch->writeToFile();
}

void Controller::openWatchlist() const
{
	if (this->watch == nullptr)
		return;
	this->watch->displayWatchlist();
}

void Controller::saveWatchlistHTML()
{
	if (this->html == nullptr)
		return;
	this->html->writeToFile();
}

void Controller::openWatchlistHTML() const
{
	if (this->html == nullptr)
		return;
	this->html->displayWatchlist();
}

void Controller::undo()
{	
	if (undoActions.empty())
		throw RepositoryException{ "There are no more undos to be done!" };

	unique_ptr<UndoAction> last = move(undoActions.back());
	last->executeUndo();
	undoActions.pop_back();
	this->redoActions.push_back(move(last));
}

void Controller::redo()
{
	if (redoActions.empty())
		throw RepositoryException{ "There are no more redos to be done!" };

	unique_ptr<UndoAction> last = move(redoActions.back());
	last->executeRedo();
	redoActions.pop_back();
}