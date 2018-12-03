#include <QtWidgets/QApplication>
#include "Movie.h"
#include "UI.h"
#include "Windows.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"
#include <iostream>
#include "labQt2.h"
#include "Repository.h"
#include "RepositoryException.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"
#include "AdminClass.h"
#include "UserClass.h"
#include <QtWidgets/QLabel.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qmessagebox.h>
#include "WatchlistListViewui.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QMessageBox msgBox{};
	msgBox.setWindowTitle("SELECT MENU");
	msgBox.setText("SELECT MENU");
	QPushButton *admin = msgBox.addButton("Administrator mode", QMessageBox::ActionRole);
	QPushButton *user = msgBox.addButton("User mode", QMessageBox::ActionRole);

	msgBox.exec();
	
	if (msgBox.clickedButton() == admin)
	{
		Repository repo{ "movies.txt" };
		FileWatchlist* w = new CSVWatchlist{ "Watchlist.csv" };
		FileWatchlist* h = new HTMLWatchlist{ "Watchlist.html" };
		Controller ctrl(repo, w, h, MovieValidator{});
		AdminClass ad(ctrl);
		ad.show();
		return a.exec();
	}
	else
	{
		Repository repo{ "movies.txt" };
		FileWatchlist* w = new CSVWatchlist{ "Watchlist.csv" };
		FileWatchlist* h = new HTMLWatchlist{ "Watchlist.html" };
		Controller ctrl(repo, w, h, MovieValidator{});
		UserClass u(ctrl);
		//WatchlistListViewui watch{ w };
		//watch.show();
		u.show();
		return a.exec();
	}
	
}
