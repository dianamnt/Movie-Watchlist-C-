#pragma once
#include <iostream>

class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;
	int duration;

public:

	// default contructor for Movie class
	Movie();

	Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	int getYear() const { return year; }
	int getLikes() const { return likes; }
	std::string getTrailer() const { return trailer; }
	int getDuration() const { return duration; }
	void setYear(int x) { year = x; }
	void setLikes(int x) { likes = x; }
	void setTitle(std::string t) { title = t; }
	void setGenre(std::string g) { genre = g; }
	void setTrailer(std::string t) { trailer = t; }
	void setDuration(int x) { duration = x; }

	int operator<(int x);

	// plays in the browser chrome the trailer for a specific movie
	void play();

	friend std::istream& operator>>(std::istream& is, Movie& m);
	friend std::ostream& operator<<(std::ostream& os, const Movie& m);
};
