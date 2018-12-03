#pragma once

#include <QWidget>
#include "ui_UserClass.h"
#include "Controller.h"
#include "WatchlistListViewui.h"

class UserClass : public QWidget
{
	Q_OBJECT

public:
	UserClass(Controller& c, QWidget *parent = Q_NULLPTR);
	~UserClass();

	void populateWatchlist();

private:
	Ui::UserClass ui;
	Controller& ctrl;
};
