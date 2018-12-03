#pragma once
#include "Controller.h"

class UI
{
private:
	Controller& ctrl;
public:
	UI(Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepoMenu();
	static void printWatchListMenu();
	static void printM();

	void addMovieToRepoUI();
	void removeMovieFromRepoUI();
	void updateMovieRepoUI();
	void displayAllMovies();
	void displayAllMoiviesWL();
	void addMoviesToWatchlistUI(Movie& movie);
	void removeMovieFromWatchlistUI();
	void saveWatchlistToFile();
	void saveWatchlistToFileHTML();
};