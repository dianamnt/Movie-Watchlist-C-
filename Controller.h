#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include "Watchlist.h"
#include <memory>
#include "MovieValidator.h"
#include "Undo.h"
#include "Redo.h"

using namespace std;

class Controller
{
private:
	Repository repo;
	FileWatchlist* watch;
	FileWatchlist* html;
	MovieValidator validator;
	vector<unique_ptr<UndoAction>> undoActions;
	vector<unique_ptr<UndoAction>> redoActions;

public:
	//Controller();

	Controller(const Repository& r, FileWatchlist* w, FileWatchlist* h,MovieValidator v) : repo{ r }, watch{ w }, html{ h }, validator{ v } {}

	Controller(const Controller& ctrl) = delete;

	void operator=(const Controller& ctrl) = delete;

	Repository getRepo() const { return repo; }
	Watchlist* getWatchlist() const { return watch; }

	// Adds a movie of a given genre to the watchlist, if the genre is an empty string it adds all movies;
	void addMovieToWatchlist(const Movie& movie);

	// Removes a movie from the watchlist
	void removeMovieFromWatchlist(const std::string&title, int like);

	void startRepository(const std::string& genre);
	void nextMovieRepository(const std::string& genre);

	// Adds a movie to the repository
	void addMovieToRepo(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);

	//Deletes a movie from the repository
	void removeMovieFromRepo(const std::string& title);

	// Updates a movie from the repository
	void updateMovieRepo(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);

	void saveWatchlist();

	void openWatchlist() const;

	void saveWatchlistHTML();

	void openWatchlistHTML() const;

	void undo();

	void redo();

};
