/*#include "Tests.h"

void Tests::testMovie()
{
	Movie m{ "Anna Karenina","drama",2014,100,"link",90 };

	assert(m.getTitle() == "Anna Karenina");
	assert(m.getGenre() == "drama");
	assert(m.getYear() == 2014);
	assert(m.getLikes() == 100);
	assert(m.getTrailer() == "link");
	assert(m.getDuration() == 90);
	m.setTitle("Life of Pi");
	assert(m.getTitle() == "Life of Pi");
	m.setGenre("sci-fi");
	assert(m.getGenre() == "sci-fi");
	m.setYear(2012);
	assert(m.getYear() == 2012);
	m.setLikes(200);
	assert(m.getLikes() == 200);
	m.setTrailer("lik");
	assert(m.getTrailer() == "lik");
	m.setDuration(80);
	assert(m.getDuration() == 80);
}

void Tests::testDynamicVector()
{
	DynamicVector v1, v2;
	Movie m1{ "Anna Karenina","drama",2014,100,"link",90 };
	Movie m2{ "Life of Pi","sci-fi",2012,200,"lik",80 };
	v1.add(m1);
	v2.add(m2);
	assert(v1.getSize() == 1);
	assert(v2.getSize() == 1);
	v1 = v2;
	{
		assert(v1.getAllElems()[0].getTitle() == v2.getAllElems()[0].getTitle());
		assert(v1.getAllElems()[0].getGenre() == v2.getAllElems()[0].getGenre());
		assert(v1.getAllElems()[0].getYear() == v2.getAllElems()[0].getYear());
		assert(v1.getAllElems()[0].getLikes() == v2.getAllElems()[0].getLikes());
		assert(v1.getAllElems()[0].getTrailer() == v2.getAllElems()[0].getTrailer());
	}

	v1 = v1 + m1;
	assert(v1.getSize() == 2);

	v1.remove(m2);
	assert(v1.getSize() == 1);

	v2 = m1 + v2;
	assert(v2.getSize() == 2);


	m2 = { "Anna Karenina","sci-fi",2012,200,"lik",90 };
	v1.update(m2);
	assert(v1.getAllElems()[0].getGenre() == "sci-fi");
	assert(v1.getAllElems()[0].getYear() == 2012);
	assert(v1.getAllElems()[0].getLikes() == 200);
	assert(v1.getAllElems()[0].getTrailer() == "lik");

	assert(v1.getSize() == 1);
	assert(v1.getCapacity() == 10);

	Movie m11{ "Pulp fiction","crime",1994,1500,"https://www.youtube.com/watch?v=s7EdQ4FqbhY",80 };
	Movie m12{ "Fight club","drama",1999,1540,"https://www.youtube.com/watch?v=D3Yw9Yc1YmY",90 };
	Movie m3{ "Gone with the wind","romance",1939,2000,"https://www.youtube.com/watch?v=0X94oZgJis4",100 };
	Movie m4{ "A clockwork orange","sci-fi",1971,1200,"https://www.youtube.com/watch?v=SPRzm8ibDQ8",120 };
	Movie m5{ "Captain fantastic","drama",2016,130,"https://www.youtube.com/watch?v=D1kH4OMIOMc",90 };
	Movie m6{ "Mr Nobody","fantasy",2009,181,"https://www.youtube.com/watch?v=9k8SoLS0KwU",100 };
	Movie m7{ "Lord of the rings","fantasy",2001,1700,"https://www.youtube.com/watch?v=V75dMMIW2B4",80 };
	Movie m8{ "The Pianist","drama",2002,583,"https://www.youtube.com/watch?v=u_jE7-6Uv7E",120 };
	Movie m9{ "The Theory of everything","biography",2015,700,"https://www.youtube.com/watch?v=Salz7uGp72c",110 };
	Movie m10{ "Into the wild","indie",2013,200,"https://www.youtube.com/watch?v=g7ArZ7VD-QQ",90 };

	DynamicVector v3;
	v3.add(m11);
	v3.add(m12);
	v3.add(m3);
	v3.add(m4);
	v3.add(m5);
	v3.add(m6);
	v3.add(m7);
	v3.add(m8);
	v3.add(m9);
	v3.add(m10);
	v3.add(m1);
	assert(v3.getCapacity() == 20);
}

void Tests::testWatchlist()
{
	Repository repo;
	Watchlist arr(repo);
	Movie m1{ "Anna Karenina","drama",2014,100,"link",60 };
	Movie m2{ "Life of Pi","sci-fi",2012,200,"lik",70 };
	arr.add(m1);
	assert(arr.getMovies().getAllElems()[0].getTitle() == "Anna Karenina");
	arr.remove(m1, 1);
	assert(arr.getMovies().getSize() == 0);
}

void Tests::testRepository()
{
	Movie m1{ "Anna Karenina","drama",2014,100,"link",80 };
	Movie m2{ "Life of Pi","sci-fi",2012,200,"lik",90 };
	Repository repo;
	repo.addMovie(m1);
	repo.addMovie(m2);
	assert(repo.getMovies().getSize() == 2);
	repo.removeMovie(m2);
	assert(repo.getMovies().getSize() == 1);
	m2 = { "Anna Karenina","sci-fi",2012,200,"lik",90 };
	repo.updateMovie(m2);
	assert(repo.getMovies().getAllElems()[0].getTitle() == "Anna Karenina");
	Movie m3{};
	assert(repo.findByTitleAndGenre("Anna Karenina").getTitle() == m2.getTitle());
	assert(repo.findByTitleAndGenre("Life of Pi").getTitle() == m3.getTitle());
	repo.removeMovie(m2);
	assert(repo.findByTitleAndGenre("Life of Pi").getTitle() == m3.getTitle());
	Repository r;
	r.addMovie(m1);
	r.addMovie(m2);
	assert(r.getCurrentMovie("").getTitle() == m1.getTitle());
	assert(r.getCurrentMovie("sci-fi").getTitle() == m2.getTitle());
}

void Tests::testController()
{
	Repository repo;
	Controller ctrl(repo);
	ctrl.addMovieToRepo("abc", "def", 1, 2, "ghi", 3);
	ctrl.addMovieToRepo("ana", "are", 3, 4, "mere", 2);
	assert(ctrl.getRepo().getMovies().getSize() == 2);
	ctrl.removeMovieFromRepo("abc");
	assert(ctrl.getRepo().getMovies().getSize() == 1);
	ctrl.updateMovieRepo("ana", "def", 7, 8, "gdf", 1);
	assert(ctrl.getRepo().getMovies().getAllElems()[0].getGenre() == "def");


	Movie m1{ "Anna Karenina","drama",2014,100,"link",90 };
	Movie m2{ "Life of Pi","sci-fi",2012,200,"lik",80 };
	ctrl.addMovieToWatchlist(m1);
	ctrl.addMovieToWatchlist(m2);
	assert(ctrl.getWatchlist().getMovies().getSize() == 2);
	ctrl.removeMovieFromWatchlist("Life of Pi", 1);
	assert(ctrl.getWatchlist().getMovies().getSize() == 1);
}
*/