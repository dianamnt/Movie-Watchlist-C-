#include "UI.h"
#include <string>
#include "MovieValidator.h"
#include "RepositoryException.h"
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "      ~~~ MENU ~~~      " << endl;
	cout << "1. Administrator mode." << endl;
	cout << "2. User mode." << endl;
	cout << "0. ...exit" << endl;
}

void UI::printRepoMenu()
{
	cout << "------------------------------------------------------" << endl;
	cout << "   Administrator menu   " << endl;
	cout << "1. Add a movie." << endl;
	cout << "2. Delete a movie." << endl;
	cout << "3. Update a movie." << endl;
	cout << "4. Display all movies." << endl;
	cout << "5. Display all movies by duration." << endl;
	cout << "0. back..." << endl;
}

void UI::printWatchListMenu()
{
	cout << "------------------------------------------------------" << endl;
	cout << "   User menu   " << endl;
	cout << "1. Display movies one by one by genre." << endl;
	cout << "2. Display all movies in the watchlist." << endl;
	cout << "3. Delete a movie from the watchlist." << endl;
	cout << "4. Save the watchlist to file." << endl;
	cout << "5. Display the watchlist from file." << endl;
	cout << "0. back..." << endl;
}

void UI::printM()
{
	cout << "What do you want to do?" << endl;
	cout << "1. Add movie to watchlist." << endl;
	cout << "2. Next." << endl;
	cout << "0. Back." << endl;
}

void UI::addMovieToRepoUI()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year = 0, likes = 0;
	cout << "Enter the year of release: ";
	cin >> year;
	while (cin.fail()) {
		cout << "Invalid input!" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter the year of release: ";
		cin >> year;
	}
	cin.ignore();
	cout << "Enter the number of likes: ";
	cin >> likes;
	while (cin.fail()) {
		cout << "Invalid input!" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter the number of likes: ";
		cin >> likes;
	}
	cin.ignore();
	cout << "Youtube link: ";
	std::string trailer;
	getline(cin, trailer);
	int duration;
	cout << "Enter duration: ";
	cin >> duration;
	try
	{
		this->ctrl.addMovieToRepo(title, genre, year, likes, trailer, duration);
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::removeMovieFromRepoUI()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	try
	{
		this->ctrl.removeMovieFromRepo(title);
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateMovieRepoUI()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year = 0, likes = 0;
	cout << "Enter the year of release: ";
	cin >> year;
	while (cin.fail()) {
		cout << "Invalid input!" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter the year of release: ";
		cin >> year;
	}
	cin.ignore();
	cout << "Enter the number of likes: ";
	cin >> likes;
	while (cin.fail()) {
		cout << "Invalid input!" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter the number of likes: ";
		cin >> likes;
	}
	cin.ignore();
	cout << "Youtube link: ";
	std::string trailer;
	getline(cin, trailer);
	int duration;
	cout << "Enter duration: ";
	cin >> duration;
	try
	{
		this->ctrl.updateMovieRepo(title, genre, year, likes, trailer, duration);
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::displayAllMovies()
{
	std::vector<Movie> v = this->ctrl.getRepo().getMovies();
	
	if (v.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (auto m : v)
	{
		cout << m.getTitle() << " | " << m.getGenre() << " | year " << m.getYear() << " | " << " likes " << m.getLikes() << " |  duration " << m.getDuration() << endl;
	}
}

void UI::displayAllMoiviesWL()
{
	std::vector<Movie> v = this->ctrl.getWatchlist()->getMovies();
	
	if (v.size() == 0)
	{
		cout << "There are no movies in the watchlist." << endl;
		return;
	}

	for (auto m : v)
	{
		cout << m.getTitle() << " | " << m.getGenre() << " | year " << m.getYear() << " | " << " likes " << m.getLikes() << " |  duration " << m.getDuration() << endl;
	}
}

void UI::addMoviesToWatchlistUI(Movie& movie)
{
	this->ctrl.addMovieToWatchlist(movie);
}

void UI::removeMovieFromWatchlistUI()
{
	int like = 0;
	cout << "Enter title: ";
	std::string title;
	getline(cin, title);
	cout << "Did you like the movie? Yes/No ";
	std::string cmd;
	getline(cin, cmd);
	if (cmd == "Yes")
		like = 1;
	else if (cmd == "No")
		like = 0;
	this->ctrl.removeMovieFromWatchlist(title, like);
}

void UI::saveWatchlistToFile()
{
	try
	{
		this->ctrl.saveWatchlist();
		if (this->ctrl.getWatchlist() == nullptr)
		{
			cout << "Watchlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::saveWatchlistToFileHTML()
{
	try
	{
		this->ctrl.saveWatchlistHTML();
		if (this->ctrl.getWatchlist() == nullptr)
		{
			cout << "Watchlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::run()
{
	while (true)

	{
		UI::printMenu();
		int command{ 0 };
		cout << "Command: ";
		cin >> command;
		while (cin.fail()) {
			cout << "Invalid input!" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Command: ";
			cin >> command;
		}
		cin.ignore();
		if (command == 0)
			break;

		else if (command == 1)
		{
			UI::printRepoMenu();
			while (true)
			{
				int commandR{ 0 };
				cout << "Command: ";
				cin >> commandR;
				while (cin.fail()) {
					cout << "Invalid input!" << std::endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Command: ";
					cin >> commandR;
				}
				cin.ignore();
				if (commandR == 0)
					break;
				else if (commandR == 1)
				{
					this->addMovieToRepoUI();
				}
				else if (commandR == 4)
				{
					this->displayAllMovies();
				}
				else if (commandR == 2)
				{
					this->removeMovieFromRepoUI();
				}
				else if (commandR == 3)
				{
					this->updateMovieRepoUI();
				}
				else if (commandR == 5)
				{
					int d;
					cout << "Enter duration: ";
					cin >> d;
					
					for (int i = 0; i < int(this->ctrl.getRepo().getMovies().size()); i++)
						if (this->ctrl.getRepo().getMovies()[i].getDuration() < d)
						{
							cout << this->ctrl.getRepo().getMovies()[i].getTitle() << " | " << this->ctrl.getRepo().getMovies()[i].getGenre() << " | " << this->ctrl.getRepo().getMovies()[i].getYear() << " | " << this->ctrl.getRepo().getMovies()[i].getLikes() << " | " << this->ctrl.getRepo().getMovies()[i].getDuration();
							cout << endl;
						}
				}
			}
		}
		else if (command == 2)
		{
			UI::printWatchListMenu();
			while (true)
			{
				int commandW{ 0 };
				cout << "Command: ";
				cin >> commandW;
				while (cin.fail()) {
					cout << "Invalid input!" << std::endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Command: ";
					cin >> commandW;
				}
				cin.ignore();
				if (commandW == 0)
					break;
				else if (commandW == 1)
				{
					int cmd;
					Movie m;
					cout << "Enter genre: ";
					std::string genre;
					getline(cin, genre);
					this->ctrl.startRepository(genre);
					m = this->ctrl.getRepo().getCurrentMovie(genre);
					cout << m.getTitle() << " | " << m.getGenre() << " | " << m.getYear() << " | " << m.getLikes() << endl;
					while (true)
					{

						printM();
						cout << "Command: ";
						cin >> cmd;
						if (cmd == 1)
						{
							this->addMoviesToWatchlistUI(m);
							this->ctrl.nextMovieRepository(genre);
							m = this->ctrl.getRepo().getCurrentMovie(genre);
							cout << m.getTitle() << " | " << m.getGenre() << " | " << m.getYear() << " | " << m.getLikes() << endl;

						}
						else if (cmd == 2)
						{
							this->ctrl.nextMovieRepository(genre);
							m = this->ctrl.getRepo().getCurrentMovie(genre);
							cout << m.getTitle() << " | " << m.getGenre() << " | " << m.getYear() << " | " << m.getLikes() << endl;

						}
						else if (cmd == 0)
						{
							break;
						}
					}
				}
				else if (commandW == 2)
				{
					this->displayAllMoiviesWL();
				}
				else if (commandW == 3)
				{
					this->removeMovieFromWatchlistUI();
				}
				else if (commandW == 4)
				{	
					int cmd{ 0 };
					cout << "1. CSV file." << endl;
					cout << "2. HTML file." << endl;
					cout << "File format: ";
					cin >> cmd;
					if (cmd == 1)

						this->saveWatchlistToFile();
					else if (cmd == 2)
						this->saveWatchlistToFileHTML();
				}
				else if (commandW == 5)
				{
					int cmd{ 0 };
					cout << "1. CSV file." << endl;
					cout << "2. HTML file." << endl;
					cout << "File format: ";
					cin >> cmd;
					if (cmd == 1)
						this->ctrl.openWatchlist();
					else if (cmd == 2)
						this->ctrl.openWatchlistHTML();
				}
			}
		}
	}
}
