#include "HTMLWatchlist.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void HTMLWatchlist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Watchlist</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border=\"1\">" << endl;
	f << "<tr>" << endl;
	f << "<td>Title</td>" << endl;
	f << "<td>Genre</td>" << endl;
	f << "<td>Year</td>" << endl;
	f << "<td>Likes</td>" << endl;
	f << "<td>Duration</td>" << endl;
	f << "<td>Link</td>" << endl;
	f << "</tr>" << endl;
	for (auto m : this->movies)
	{
		f << "<tr>" << endl;
		f << "<td>" << m.getTitle() << "</td>" << endl;
		f << "<td>" << m.getGenre() << "</td>" << endl;
		f << "<td>" << m.getYear() << "</td>" << endl;
		f << "<td>" << m.getLikes() << "</td>" << endl;
		f << "<td>" << m.getDuration() << "</td>" << endl;
		f << "<td><a href=" << m.getTrailer() << ">Link</a></td>" << endl;
		f << "</tr>" << endl;
	}

	f << "</table>" << endl;
	f << "</body>" << endl;
	f << "</html>" << endl;

	f.close();
}

void HTMLWatchlist::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\"";

	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
