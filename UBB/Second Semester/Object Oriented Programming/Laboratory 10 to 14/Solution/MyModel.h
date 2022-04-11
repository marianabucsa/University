#pragma once
#include <QAbstractListModel>
#include <vector>
#include <string>
#include "Domain.h"
#include "Repository.h"


class MyListModel :public QAbstractListModel {
private:
	std::vector<Medicine> all;
public:
	MyListModel() {
	}
	MyListModel(std::vector<Medicine> all) :all{ all } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return all.size();
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			auto sp = all[index.row()].get_name() + "\t" + all[index.row()].get_manufacturer() + "\t" + all[index.row()].get_substance();
			return QString::fromStdString(sp) + "\t" + QString::number(all[index.row()].get_price());
		}

		return QVariant{};
	}

	Medicine get_prescription(const QModelIndex& index) {
		return all[index.row()];
	}
	void set_prescription(const std::vector<Medicine>& med) {
		this->all = med;
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount(), 0);
		emit dataChanged(topLeft, bottomRight);
	}
};
