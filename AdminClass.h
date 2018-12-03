#pragma once

#include <QWidget>
#include "ui_AdminClass.h"
#include "Controller.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"

class AdminClass : public QWidget
{
	Q_OBJECT

public:
	AdminClass(Controller& c, QWidget *parent = Q_NULLPTR);
	~AdminClass();

	void populateRepo();
	void populateRepoShort();

private:
	Ui::AdminClass ui;
	Controller& ctrl;
};
