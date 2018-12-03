#pragma once

#include <QWidget>
#include "ui_WatchlistListViewui.h"
#include "WatchlistListViewModel.h"
#include "Watchlist.h"

class WatchlistListViewui : public QWidget
{
	Q_OBJECT

public:
	WatchlistListViewui(Watchlist* w, QWidget *parent = Q_NULLPTR);
	~WatchlistListViewui();

private:
	Watchlist* watch;
	WatchlistListViewModel* listModel;
	Ui::WatchlistListViewui ui;

};
