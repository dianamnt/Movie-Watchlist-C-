#include "WatchlistListViewModel.h"

int WatchlistListViewModel::rowCount(const QModelIndex &parent) const
{
	int movieNo = this->watch->getMovies().size();
	return movieNo;
}

QVariant WatchlistListViewModel::data(const QModelIndex& index, int role) const
{
	int r = index.row();
	int c = index.column();

	vector<Movie> movies = this->watch->getMovies();

	if (r == movies.size())
		return QVariant();

	Movie m = movies[r];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (c)
		{
		case 0 :
			return QString::fromStdString(m.getTitle());

		case 1:
			return QString::fromStdString(m.getGenre());

		default:
			break;
		}
	}

	return QVariant{};
}