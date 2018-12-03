#pragma once

#include "Movie.h"
#include "Repository.h"

class UndoAction
{
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction
{
private:
	Movie addedMovie;
	Repository& repo;

public:
	UndoAdd(Repository& r, const Movie& m): repo{r}, addedMovie{m} {}

	void executeUndo() override
	{
		this->repo.removeMovie(addedMovie);
	}

	void executeRedo() override
	{
		this->repo.addMovie(addedMovie);
	}
};

class UndoRemove : public UndoAction
{
private:
	Movie removedMovie;
	Repository& repo;

public:
	UndoRemove(Repository& r, const Movie& m): repo{r}, removedMovie{m} {}

	void executeUndo() override
	{
		this->repo.addMovie(removedMovie);
	}

	void executeRedo() override
	{
		this->repo.removeMovie(removedMovie);
	}
};

class UndoUpdate : public UndoAction
{
private:
	Movie updatedMovieUndo;
	Movie updatedMovieRedo;
	Repository& repo;

public:
	UndoUpdate(Repository& r, const Movie& m1, const Movie& m2): repo{r}, updatedMovieUndo{m1}, updatedMovieRedo(m2){}

	void executeUndo() override
	{
		this->repo.updateMovie(updatedMovieUndo);
	}

	void executeRedo() override
	{
		this->repo.updateMovie(updatedMovieRedo);
	}
};