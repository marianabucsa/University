#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qwindow.h>
#include <qmainwindow.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qtablewidget.h>
#include <qmdiarea.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <vector>
#include <qtableview.h>
#include <qheaderview.h>
#include <qmessagebox.h>
#include <qtoolbar.h>
#include <qpainter.h>
#include <qpaintengine.h>
#include <qevent.h>
#include <qdebug.h>
#include "MyModel.h"


class MedicineGUI :public QWidget {
private:
	Service& srv;

	MyListModel* list_model; //model view
	QListView* list_of_all;
	QLabel* label_all;

	QListWidget* list_all;
	QListWidget* new_list;
	QTableWidget* new_table;
	QPushButton* btn_sort_by_name;
	QPushButton* btn_sort_by_manufacturer;
	QPushButton* btn_sort_by_substance_price;
	QPushButton* btn_add_medicine;
	QPushButton* btn_modify_medicine;
	QPushButton* btn_remove_medicine;
	QPushButton* btn_filter_by_substance;
	QLineEdit* filter_substance;
	QPushButton* btn_filter_by_price_lower;
	QPushButton* btn_filter_by_price_greater;
	QPushButton* btn_random_prescription;
	QPushButton* btn_add_prescription;
	QPushButton* btn_empty_prescription;
	QPushButton* btn_export_HTML;
	QPushButton* btn_undo;
	QPushButton* btn_prescriptionCRUDGUI;
	QPushButton* btn_prescriptionReadOnlyGUI;
	QLineEdit* filter_price;
	QLineEdit* txt_name;
	QLineEdit* txt_manufacturer;
	QLineEdit* txt_substance;
	QLineEdit* txt_price;
	QLineEdit* txt_prescription_name;
	QLineEdit* txt_file_name;
	QLineEdit* txt_number;
	QLineEdit* name;
	void upload_list(const std::vector<Medicine>&);
	void upload_table(const std::vector<Medicine>&);
	void reload_list(const std::vector<Medicine>&);
	void gui_add_medicine();
	void gui_modify_medicine();
	void gui_remove_medicine();
	void init_GUI_components();
	void connect_signals_slots();
public:
	MedicineGUI(Service& srv) :srv{ srv } {
		init_GUI_components();
		connect_signals_slots();
		upload_list(srv.get_all_medicine());
		upload_table(srv.get_all_medicine());
	}

};


class PrescriptionCRUDGUI :public QWidget, public Observer {
private:
	Service& srv;
	QListWidget* prescription_list;
	QLineEdit* txt_name;
	QLineEdit* txt_how_many;
	QLineEdit* txt_file_name;
	QPushButton* btn_add_prescription;
	QPushButton* btn_random_prescription;
	QPushButton* btn_empty_prescription;
	QPushButton* btn_export_HTML;
	void reload_prescription(const std::vector<Medicine>&);
	void update() override {
		reload_prescription(srv.get_prescription());
	}
	void init_GUI_components();
	void connect_signal_slots();
public:
	PrescriptionCRUDGUI(Service& srv) : srv{ srv } {
		init_GUI_components();
		connect_signal_slots();
		reload_prescription(srv.get_prescription());
		srv.add_observer(this);
	}
};

class PrescriptionReadOnlyGUI : public QWidget, public Observer{
private:
	Service& srv;
	void paintEvent(QPaintEvent* event) override {
		QPainter p{ this };
		std::vector<Medicine> v = srv.get_prescription();
		int x = 40;
		for (const auto& o : v) {
			p.drawRect(x ,70, 10, 40);
			x += 20;
		}
	}

	void update() override {
		repaint();
	}

public:
	PrescriptionReadOnlyGUI(Service& srv) : srv{ srv } {
		srv.add_observer(this);
	}

};