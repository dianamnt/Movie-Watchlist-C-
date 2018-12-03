#pragma once

#pragma once

#include "Movie.h"
#include "Repository.h"

class RedoAction
{
public:
	virtual void executeRedo() = 0;
	virtual ~RedoAction() {};
};

class RedoAdd : public RedoAction
{
private:
	Movie addedMovie;
	Repository& repo;

public:
	RedoAdd(Repository& r, const Movie& m) : repo{ r }, addedMovie{ m } {}

	void executeRedo() override
	{
		this->repo.addMovie(addedMovie);
	}
};

class RedoRemove : public RedoAction
{
private:
	Movie removedMovie;
	Repository& repo;

public:
	RedoRemove(Repository& r, const Movie& m) : repo{ r }, removedMovie{ m } {}

	void executeRedo() override
	{
		this->repo.removeMovie(removedMovie);
	}
};

class RedoUpdate : public RedoAction
{
private:
	Movie updatedMovie;
	Repository& repo;

public:
	RedoUpdate(Repository& r, const Movie& m) : repo{ r }, updatedMovie{ m } {}

	void executeRedo() override
	{
		this->repo.updateMovie(updatedMovie);
	}
};