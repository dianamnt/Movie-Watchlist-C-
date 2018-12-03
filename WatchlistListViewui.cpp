#include "WatchlistListViewui.h"

WatchlistListViewui::WatchlistListViewui(Watchlist* w, QWidget *parent)
	: QWidget(parent), watch(w)
{
	ui.setupUi(this);
	this->listModel = new WatchlistListViewModel{ w };
	ui.watchlistListView->setModel(this->listModel);
}

WatchlistListViewui::~WatchlistListViewui()
{
}
