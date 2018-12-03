#pragma once
#include <QAbstractListModel>
#include "Controller.h"

class WatchlistListViewModel : public QAbstractListModel
{
private:
	Watchlist * watch;

public:
	WatchlistListViewModel(Watchlist* w, QObject* parent = NULL): QAbstractListModel{parent}, watch{w} {}
	~WatchlistListViewModel() {}

	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};