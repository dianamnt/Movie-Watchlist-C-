#include "CSVWatchlist.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void CSVWatchlist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
		f << m;

	f.close();
}

void CSVWatchlist::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\"";

	ShellExecuteA(NULL, NULL, "C://Windows//system32//notepad", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}