#include "UserClass.h"
#include <string>
#include <qmessagebox.h>
#include "CSVWatchlist.h"
#include "FileWatchlist.h"
#include "RepositoryException.h"

using namespace std;

UserClass::UserClass(Controller& c,QWidget *parent)
	: ctrl(c), QWidget(parent)
{
	ui.setupUi(this);
	
	QObject::connect(ui.showTrailersButton, &QPushButton::clicked, this, [this] {
		QString str;
		str = ui.movieGenreLineEdit->text();
		string genre = str.toStdString();
		this->ctrl.startRepository(genre);
		Movie m{};
		m = this->ctrl.getRepo().getCurrentMovie(genre);
		//afisez
		QString st = "";
		st += QString::fromStdString(m.getTitle());
		st += " | ";
		st += QString::fromStdString(m.getGenre());
		st += " | ";
		st += QString::number(m.getYear());
		st += " | ";
		st += QString::number(m.getLikes());
		st += " | ";
		st += QString::number(m.getDuration());
		ui.currentMovieLineEdit->setText(st);

		QObject::connect(ui.addToWatchlistButton, &QPushButton::clicked, this, [this] {
			QString str;
			str = ui.movieGenreLineEdit->text();
			string genre = str.toStdString();
			Movie m{};
			m = this->ctrl.getRepo().getCurrentMovie(genre);
			this->ctrl.addMovieToWatchlist(m);
			this->ctrl.nextMovieRepository(genre);
			m = this->ctrl.getRepo().getCurrentMovie(genre);
			//afisez
			QString st = "";
			st += QString::fromStdString(m.getTitle());
			st += " | ";
			st += QString::fromStdString(m.getGenre());
			st += " | ";
			st += QString::number(m.getYear());
			st += " | ";
			st += QString::number(m.getLikes());
			st += " | ";
			st += QString::number(m.getDuration());
			ui.currentMovieLineEdit->setText(st);
		});
		QObject::connect(ui.nextButton, &QPushButton::clicked, this, [this] {
			QString str;
			str = ui.movieGenreLineEdit->text();
			string genre = str.toStdString();
			Movie m{};
			this->ctrl.nextMovieRepository(genre);
			m = this->ctrl.getRepo().getCurrentMovie(genre);
			// afisez
			QString st = "";
			st += QString::fromStdString(m.getTitle());
			st += " | ";
			st += QString::fromStdString(m.getGenre());
			st += " | ";
			st += QString::number(m.getYear());
			st += " | ";
			st += QString::number(m.getLikes());
			st += " | ";
			st += QString::number(m.getDuration());
			ui.currentMovieLineEdit->setText(st);
		});
	});

	QObject::connect(ui.displayWatchlistButton, &QPushButton::clicked, this, [this] {
		this->populateWatchlist();
		//Watchlist watch;
		WatchlistListViewui* w =  new WatchlistListViewui{ ctrl.getWatchlist() };
		w->show();
	});
	
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, [this] {
		QString str;
		str = ui.removeLineEdit->text();
		string title = str.toStdString();

		if (title != "")
		{
			QMessageBox msgBox{};
			msgBox.setWindowTitle("Remove");
			msgBox.setText("Did you like the movie?");
			QPushButton *yes = msgBox.addButton("Yes", QMessageBox::ActionRole);
			QPushButton *no = msgBox.addButton("No", QMessageBox::ActionRole);

			msgBox.exec();

			if (msgBox.clickedButton() == yes)
			{
				this->ctrl.removeMovieFromWatchlist(title, 1);
			}
			else
			{
				this->ctrl.removeMovieFromWatchlist(title, 0);
			}
		}
		this->populateWatchlist();
	});

	QObject::connect(ui.csvButton, &QPushButton::clicked, this, [this] {
		this->ctrl.saveWatchlist();
		this->ctrl.openWatchlist();
	});

	QObject::connect(ui.htmlButton, &QPushButton::clicked, this, [this] {
		this->ctrl.saveWatchlistHTML();
		this->ctrl.openWatchlistHTML();
	});
	
}

UserClass::~UserClass()
{
}

void UserClass::populateWatchlist()
{
	if (ui.watchlistListWidget->count() > 0)
		ui.watchlistListWidget->clear();

	for (auto m : this->ctrl.getWatchlist()->getMovies())
	{
		QString st = "";
		st += QString::fromStdString(m.getTitle());
		st += " | ";
		st += QString::fromStdString(m.getGenre());
		st += " | ";
		st += QString::number(m.getYear());
		st += " | ";
		st += QString::number(m.getLikes());
		st += " | ";
		st += QString::fromStdString(m.getTrailer());
		st += " | ";
		st += QString::number(m.getDuration());
		ui.watchlistListWidget->addItem(st);
	}
}