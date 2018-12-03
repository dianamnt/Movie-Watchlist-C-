#include "AdminClass.h"
#include <string.h>
#include <iostream>
#include "RepositoryException.h"

using namespace std;

AdminClass::AdminClass(Controller& c,QWidget *parent)
	:ctrl(c), QWidget(parent)
{
	ui.setupUi(this);

	this->populateRepo();
	
	QObject::connect(ui.addButton, &QPushButton::clicked, this, [this]() {
	QString t = ui.titleLineEdit->text();
	const string title = t.toStdString(); 
	QString g = ui.genreLineEdit->text();
	const string genre = g.toStdString();
	QString tr = ui.trailerLineEdit->text();
	const string trailer = tr.toStdString();
	
	string::size_type sz;
	QString y = ui.yearLineEdit->text();
	const string year = y.toStdString();
	int yearr;
	if (year == "")
		yearr = 0;
	else 
		yearr = stoi(year,&sz);
	QString l = ui.likesLineEdit->text();
	const string likes = l.toStdString();
	int likess;
	if (likes == "")
		 likess = 0;
	else
		likess = stoi(likes, &sz);
	QString d = ui.durationLineEdit->text();
	const string duration = d.toStdString();
	int durationn;
	if (duration == "")
		durationn = 0;
	else
		durationn = stoi(duration, &sz);
	try
	{
	this->ctrl.addMovieToRepo(title,genre,yearr,likess,trailer,durationn);
	}
	catch (MovieException& e){}
	
	catch (RepositoryException& e){}
	
	catch (FileException& e){}

	this->populateRepo();

	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.durationLineEdit->clear();
	});

	QObject::connect(ui.removeButton, &QPushButton::clicked, this, [this]() {
		QString t = ui.titleLineEdit->text();
		const string title = t.toStdString();
	try
	{
		this->ctrl.removeMovieFromRepo(title);
	}
	catch (MovieException& e){}
	catch (RepositoryException& e) {}
	catch (FileException& e) {}
		
		this->populateRepo();

		ui.titleLineEdit->clear();
	});

	QObject::connect(ui.updateButton, &QPushButton::clicked, this, [this]() {
		QString t = ui.titleLineEdit->text();
		const string title = t.toStdString();
		QString g = ui.genreLineEdit->text();
		const string genre = g.toStdString();
		QString tr = ui.trailerLineEdit->text();
		const string trailer = tr.toStdString();

		/*
		string::size_type sz;
		QString y = ui.yearLineEdit->text();
		const string year = y.toStdString();
		const int yearr = stoi(year, &sz);
		QString l = ui.likesLineEdit->text();
		const int likes = stoi(l.toStdString(), &sz);
		QString d = ui.durationLineEdit->text();
		const int duration = stoi(d.toStdString(), &sz);
		*/

		string::size_type sz;
		QString y = ui.yearLineEdit->text();
		const string year = y.toStdString();
		int yearr;
		if (year == "")
			yearr = 0;
		else
			yearr = stoi(year, &sz);
		QString l = ui.likesLineEdit->text();
		const string likes = l.toStdString();
		int likess;
		if (likes == "")
			likess = 0;
		else
			likess = stoi(likes, &sz);
		QString d = ui.durationLineEdit->text();
		const string duration = d.toStdString();
		int durationn;
		if (duration == "")
			durationn = 0;
		else
			durationn = stoi(duration, &sz);
	try
	{
		this->ctrl.updateMovieRepo(title, genre, yearr, likess, trailer, durationn);
	}
	catch (MovieException& e) {}
	catch (RepositoryException& e) {}
	catch (FileException& e) {}
		
		this->populateRepo();

		ui.titleLineEdit->clear();
		ui.genreLineEdit->clear();
		ui.yearLineEdit->clear();
		ui.likesLineEdit->clear();
		ui.trailerLineEdit->clear();
		ui.durationLineEdit->clear();
	});

	
	QObject::connect(ui.repoComboBox, &QComboBox::currentTextChanged, this, [this] {
		string s1 = "Short";
		QString str1 = QString::fromStdString(s1);
		if (ui.repoComboBox->currentText() == str1)
			this->populateRepoShort();
		else
		{
			this->populateRepo();
		}
	});

	QObject::connect(ui.undoButton, &QPushButton::clicked, this, [this] {
		try
		{
			this->ctrl.undo();
			this->populateRepo();
		}
		catch (RepositoryException& e)
		{
		}
	});

	QObject::connect(ui.redoButton, &QPushButton::clicked, this, [this] {
		try
		{
			this->ctrl.redo();
			this->populateRepo();
		}
		catch (RepositoryException& e)
		{
		}
	});
}

void AdminClass::populateRepo()
{
	if (ui.movieListWidget->count() > 0)
		ui.movieListWidget->clear();

	for (auto m : this->ctrl.getRepo().getMovies())
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
		ui.movieListWidget->addItem(st);
	}

}

void AdminClass::populateRepoShort()
{
	if (ui.movieListWidget->count() > 0)
		ui.movieListWidget->clear();

	for (auto m : this->ctrl.getRepo().getMovies())
	{
		QString st = "";
		st += QString::fromStdString(m.getTitle());
		ui.movieListWidget->addItem(st);
	}
}

AdminClass::~AdminClass()
{
}
