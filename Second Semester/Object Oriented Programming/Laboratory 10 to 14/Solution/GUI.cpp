#include "GUI.h"
#include <string>
#include <algorithm>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFormLayout>

void MedicineGUI::init_GUI_components() {


	QHBoxLayout* main_layout = new QHBoxLayout;
	setLayout(main_layout);

	QWidget* left_vertical = new QWidget;
	QVBoxLayout* ly_left_vertical = new QVBoxLayout;
	left_vertical->setLayout(ly_left_vertical);
	label_all = new QLabel;
	label_all->setText(QString{ "	Name \tManufacturer \tSubstance \tPrice" });
	ly_left_vertical->addWidget(label_all);

	QWidget* wid_left = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	wid_left->setLayout(vl);
	list_model = new MyListModel;
	list_of_all = new QListView;
	list_of_all->setUniformItemSizes(true);
	vl->addWidget(list_of_all);
	list_of_all->setModel(list_model);

	QWidget* wid_l = new QWidget;
	QVBoxLayout* v = new QVBoxLayout;
	wid_l->setLayout(v);
	new_table = new QTableWidget{ 20, 4 };
	vl->addWidget(new_table);



	QWidget* wid_btn_left = new QWidget;
	QHBoxLayout* ly_btns_left = new QHBoxLayout;
	wid_btn_left->setLayout(ly_btns_left);

	btn_sort_by_name = new QPushButton("Sort by name");
	QPalette pal = btn_sort_by_name->palette();
	btn_sort_by_name->setStyleSheet("background-color: yellow");
	ly_btns_left->addWidget(btn_sort_by_name);
	ly_btns_left->addStretch();



	btn_sort_by_manufacturer = new QPushButton("Sort by manufacturer");
	btn_sort_by_manufacturer->setStyleSheet("background-color: yellow");
	ly_btns_left->addWidget(btn_sort_by_manufacturer);
	ly_btns_left->addStretch();

	btn_sort_by_substance_price = new QPushButton("Sort by substance and price");
	btn_sort_by_substance_price->setStyleSheet("background-color: yellow");
	ly_btns_left->addWidget(btn_sort_by_substance_price);
	ly_btns_left->addStretch();


	vl->addWidget(wid_btn_left);
	ly_left_vertical->addWidget(wid_left);


	main_layout->addWidget(left_vertical);


	QWidget* wid_right = new QWidget;
	QFormLayout* layout_right = new QFormLayout;
	wid_right->setLayout(layout_right);
	txt_name = new QLineEdit;
	layout_right->addRow(new QLabel("Name:"), txt_name);
	txt_manufacturer = new QLineEdit;
	layout_right->addRow(new QLabel("Manufacturer:"), txt_manufacturer);
	txt_substance = new QLineEdit;
	layout_right->addRow(new QLabel("Substance:"), txt_substance);
	txt_price = new QLineEdit;
	layout_right->addRow(new QLabel("Price:"), txt_price);
	txt_prescription_name = new QLineEdit;

	btn_undo = new QPushButton("Undo");
	btn_empty_prescription = new QPushButton("Empty prescription");

	btn_add_medicine = new QPushButton("Add medicine");
	btn_modify_medicine = new QPushButton("Modify medicine");
	btn_remove_medicine = new QPushButton("Remove medicine");
	btn_prescriptionCRUDGUI = new QPushButton("CRUD GUI");
	btn_prescriptionReadOnlyGUI = new QPushButton("Read only GUI");


	QWidget* wid_middle = new QWidget;
	QFormLayout* layout_middle = new QFormLayout;
	wid_middle->setLayout(layout_middle);
	filter_substance = new QLineEdit;
	layout_middle->addRow(new QLabel("Substance"), filter_substance);
	main_layout->addWidget(wid_middle);
	btn_filter_by_substance = new QPushButton("Filter by substance");
	btn_filter_by_substance->setStyleSheet("background-color: green");
	layout_middle->addWidget(btn_filter_by_substance);

	layout_middle->addRow("  ", (QWidget*)nullptr);
	filter_price = new QLineEdit;
	layout_middle->addRow(new QLabel("Price"), filter_price);
	btn_filter_by_price_lower = new QPushButton("Filter by price lower");
	btn_filter_by_price_lower->setStyleSheet("background-color: green");
	layout_middle->addWidget(btn_filter_by_price_lower);
	btn_filter_by_price_greater = new QPushButton("Filter by price greater");
	btn_filter_by_price_greater->setStyleSheet("background-color: green");
	layout_middle->addWidget(btn_filter_by_price_greater);

	layout_middle->addRow("  ", (QWidget*)nullptr);
	layout_middle->addRow("  ", (QWidget*)nullptr);
	txt_prescription_name = new QLineEdit;
	layout_middle->addRow(new QLabel("Name"), txt_prescription_name);
	btn_add_prescription = new QPushButton("Add to prescription");
	btn_add_prescription->setStyleSheet("background-color: blue");
	layout_middle->addWidget(btn_add_prescription);
	layout_middle->addRow("  ", (QWidget*)nullptr);
	txt_number = new QLineEdit;
	layout_middle->addRow(new QLabel("How many"), txt_number);
	btn_random_prescription = new QPushButton("Add random to prescription");
	btn_random_prescription->setStyleSheet("background-color: blue");
	layout_middle->addWidget(btn_random_prescription);
	layout_middle->addRow("  ", (QWidget*)nullptr);
	txt_file_name = new QLineEdit;
	layout_middle->addRow(new QLabel("File name"), txt_file_name);
	btn_export_HTML = new QPushButton("Export prescription to HTML");
	btn_export_HTML->setStyleSheet("background-color: blue");
	layout_middle->addWidget(btn_export_HTML);
	layout_middle->addRow("  ", (QWidget*)nullptr);
	btn_empty_prescription = new QPushButton("Empty prescription");
	btn_empty_prescription->setStyleSheet("background-color: blue");
	layout_middle->addWidget(btn_empty_prescription);


	btn_add_medicine->setStyleSheet("background-color: red");
	btn_modify_medicine->setStyleSheet("background-color: red");
	btn_remove_medicine->setStyleSheet("background-color: red");
	btn_undo->setStyleSheet("background-color: red");
	layout_right->addWidget(btn_add_medicine);
	layout_right->addWidget(btn_modify_medicine);
	layout_right->addWidget(btn_remove_medicine);
	layout_right->addWidget(btn_undo);
	layout_right->addRow("  ", (QWidget*)nullptr);
	layout_right->addRow("  ", (QWidget*)nullptr);
	layout_right->addWidget(btn_prescriptionCRUDGUI);
	layout_right->addWidget(btn_prescriptionReadOnlyGUI);

	main_layout->addWidget(wid_right);
}

void MedicineGUI::connect_signals_slots() {

	QObject::connect(btn_sort_by_name, &QPushButton::clicked, [&]() {
		reload_list(srv.sort_by_name());
		});
	QObject::connect(btn_sort_by_manufacturer, &QPushButton::clicked, [&]() {
		reload_list(srv.sort_by_manufacturer());
		});
	QObject::connect(btn_sort_by_substance_price, &QPushButton::clicked, [&]() {
		reload_list(srv.sort_by_substance_price());
		});
	QObject::connect(btn_filter_by_substance, &QPushButton::clicked, [&]() {

		std::vector<Medicine> v = srv.filter_medicine_substance(filter_substance->text().toStdString());
		if (v.size())
			reload_list(v);
		else
			QMessageBox::warning(this, "Warning", "No medicine with this substance!");
		});
	QObject::connect(btn_filter_by_price_lower, &QPushButton::clicked, [&]() {
		if (filter_price->text().toFloat() < 0) {
			QMessageBox::warning(this, "Warning", "Invalid price!");
		}
		else {
			std::vector<Medicine> v = srv.filter_medicine_price_lower(filter_price->text().toFloat());
			if (v.size())
				reload_list(v);
			else
				QMessageBox::warning(this, "Warning", "No medicine with the price lower than" + filter_price->text() + "!");
		}
		});
	QObject::connect(btn_filter_by_price_greater, &QPushButton::clicked, [&]() {
		if (filter_price->text().toFloat() < 0) {
			QMessageBox::warning(this, "Warning", "Invalid price!");
		}
		else {
			std::vector<Medicine> v = srv.filter_medicine_price_greater(filter_price->text().toFloat());
			if (v.size())
				reload_list(v);
			else
				QMessageBox::warning(this, "Warning", "No medicine with the price greater than" + filter_price->text() + "!");
		}
		});
	QObject::connect(btn_add_medicine, &QPushButton::clicked, this, &MedicineGUI::gui_add_medicine);
	QObject::connect(btn_modify_medicine, &QPushButton::clicked, this, &MedicineGUI::gui_modify_medicine);
	QObject::connect(btn_remove_medicine, &QPushButton::clicked, this, &MedicineGUI::gui_remove_medicine);
	QObject::connect(btn_random_prescription, &QPushButton::clicked, this, [&]() {
		try {
			QMessageBox::information(this, "Information", "The prescription has "+QString::number(srv.random_prescription(txt_number->text().toFloat()))+" medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});

	QObject::connect(btn_add_prescription, &QPushButton::clicked, this, [&]() {
		try {
			QMessageBox::information(this, "Information", "The prescription has "+QString::number(srv.add_prescription(txt_prescription_name->text().toStdString()))+" medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});
	QObject::connect(btn_empty_prescription, &QPushButton::clicked, this, [&]() {
		srv.empty_prescription();
		QMessageBox::information(this, "Information", "The prescription has 0 medicine!");
		});
	QObject::connect(btn_export_HTML, &QPushButton::clicked, [&]() {
		try {
			QMessageBox::information(this, "Information","The prescription has "+ QString::number(srv.export_prescription(txt_file_name->text().toStdString()))+" medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});
	QObject::connect(btn_undo, &QPushButton::clicked, [&]() {
		try {
			srv.undo_action();
			upload_list(srv.get_all_medicine());
			upload_table(srv.get_all_medicine());
		}
		catch (const UndoException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});
	/*QObject::connect(list_all, &QListWidget::itemSelectionChanged, this, [&]() {
		if (list_all->selectedItems().isEmpty()) {
			txt_name->setText("");
			txt_manufacturer->setText("");
			txt_substance->setText("");
			txt_price->setText("");
			return;
		}
		QListWidgetItem* selItem = list_all->selectedItems().at(0);
		txt_name->setText(selItem->text());
		const std::vector<Medicine>& v = srv.get_all_medicine();
		for (const auto & m : v) {
			if (m.get_name() == txt_name->text().toStdString()) {
				txt_manufacturer->setText(QString::fromStdString(m.get_manufacturer()));
				txt_substance->setText(QString::fromStdString(m.get_substance()));
				txt_price->setText(QString::number(m.get_price()));
			}
		}
		
	});*/

	QObject::connect(list_of_all->selectionModel(), &QItemSelectionModel::selectionChanged, this, [&]() {
		auto sel = list_of_all->selectionModel()->selectedIndexes();
		if (sel.isEmpty()) {
			txt_name->setText("");
			txt_manufacturer->setText("");
			txt_substance->setText("");
			txt_price->setText("");
		}
		auto first_sel = sel.at(0);
		Medicine m = list_model->get_prescription(first_sel);
		txt_name->setText(QString::fromStdString(m.get_name()));
		txt_manufacturer->setText(QString::fromStdString(m.get_manufacturer()));
		txt_substance->setText(QString::fromStdString(m.get_substance()));
		txt_price->setText(QString::number(m.get_price()));
		});

	QObject::connect(btn_prescriptionCRUDGUI, &QPushButton::clicked, [&]() {
		PrescriptionCRUDGUI* crud_gui= new PrescriptionCRUDGUI(srv);
		crud_gui->show();
	});

	QObject::connect(btn_prescriptionReadOnlyGUI, &QPushButton::clicked, [&]() {
		PrescriptionReadOnlyGUI* paint_gui= new PrescriptionReadOnlyGUI(srv);
		paint_gui->show();
	});
}

void MedicineGUI::upload_list(const std::vector<Medicine>& v) {
	/*list_all->clear();
	QListWidgetItem* item = new QListWidgetItem("Name", list_all);
	for (const auto& m : v) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.get_name()), list_all);
	}*/
	list_model->set_prescription(v);

}

void MedicineGUI::upload_table(const std::vector<Medicine>& v) {
	new_table->clear();
	new_table->setItem(0, 0, new QTableWidgetItem("Name"));
	new_table->setItem(0, 1, new QTableWidgetItem("Manufacturer"));
	new_table->setItem(0, 2, new QTableWidgetItem("Substance"));
	new_table->setItem(0, 3, new QTableWidgetItem("Price"));
	for (int i = 0; i < v.size(); i++) {
		new_table->setItem(i+1, 0, new QTableWidgetItem(QString::fromStdString(v[i].get_name())));
		new_table->setItem(i+1, 1, new QTableWidgetItem(QString::fromStdString(v[i].get_manufacturer())));
		new_table->setItem(i+1, 2, new QTableWidgetItem(QString::fromStdString(v[i].get_substance())));
		new_table->setItem(i+1, 3, new QTableWidgetItem(QString::number(v[i].get_price())));
		
	}

}

void MedicineGUI::reload_list(const std::vector<Medicine>& v) {
	QWidget* ot = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	new_list = new QListWidget;
	vl->addWidget(new_list);
	ot->setLayout(vl);
	QListWidgetItem* item = new QListWidgetItem("Name\tManufacturer\tSubstance\tPrice\n", new_list);
	for (const auto& m : v) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.get_name() + "	" + m.get_manufacturer() + "\t     " + m.get_substance()) + "\t" + QString::number(m.get_price())+"\t", new_list);
	}
	ot->show();
}

void MedicineGUI::gui_add_medicine() {
	try {
		srv.add_medicine(txt_name->text().toStdString(), txt_price->text().toFloat(), txt_manufacturer->text().toStdString(), txt_substance->text().toStdString());
		upload_list(srv.get_all_medicine());
		upload_table(srv.get_all_medicine());
	}
	catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const ValidatorException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
}

void MedicineGUI::gui_modify_medicine() {
	try {
		srv.modify_medicine(txt_name->text().toStdString(), txt_price->text().toFloat(), txt_manufacturer->text().toStdString(), txt_substance->text().toStdString());
		upload_list(srv.get_all_medicine());
		upload_table(srv.get_all_medicine());
	}
	catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const ValidatorException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
}

void MedicineGUI::gui_remove_medicine() {
	try {
		srv.remove_medicine(txt_name->text().toStdString());
		upload_list(srv.get_all_medicine());
		upload_table(srv.get_all_medicine());
	}
	catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const ValidatorException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
	catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
}

void PrescriptionCRUDGUI::reload_prescription(const std::vector<Medicine>& v) {
	prescription_list->clear();
	QListWidgetItem* item = new QListWidgetItem("Name\tManufacturer\tSubstance\tPrice\n",prescription_list);
	for (const auto& m : v) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.get_name() + "	" + m.get_manufacturer() + "\t     " + m.get_substance()) + "\t" + QString::number(m.get_price()) + "\t", prescription_list);
	}
}

void PrescriptionCRUDGUI::init_GUI_components() {
	QHBoxLayout* pres_main_layout = new QHBoxLayout;
	setLayout(pres_main_layout);

	QWidget* pres_wid_left = new QWidget;
	QVBoxLayout* layout_left = new QVBoxLayout;
	pres_wid_left->setLayout(layout_left);

	prescription_list = new QListWidget;
	layout_left->addWidget(prescription_list
	);
	pres_main_layout->addWidget(pres_wid_left);

	QWidget* pres_wid_right = new QWidget;
	QFormLayout* layout_right = new QFormLayout;
	pres_wid_right->setLayout(layout_right);
	txt_name = new QLineEdit;
	layout_right->addRow(new QLabel("Name"), txt_name);
	btn_add_prescription= new QPushButton("Add to prescription");
	layout_right->addWidget(btn_add_prescription);
	txt_how_many= new QLineEdit;
	layout_right->addRow(new QLabel("How many"), txt_how_many);
	btn_random_prescription=new QPushButton("Add random to prescription");
	layout_right->addWidget(btn_random_prescription);
	btn_empty_prescription = new QPushButton("Empty prescription");
	layout_right->addWidget(btn_empty_prescription);
	txt_file_name = new QLineEdit;
	layout_right->addRow(new QLabel("File name"), txt_file_name);
	btn_export_HTML= new QPushButton("Export to HTML");
	layout_right->addWidget(btn_export_HTML);

	pres_main_layout->addWidget(pres_wid_right);
}

void PrescriptionCRUDGUI::connect_signal_slots() {
	QObject::connect(btn_random_prescription, &QPushButton::clicked, this, [&]() {
		try {
			QMessageBox::information(this, "Information", "The prescription has " + QString::number(srv.random_prescription(txt_how_many->text().toFloat())) + " medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});

	QObject::connect(btn_add_prescription, &QPushButton::clicked, this, [&]() {
		try {
			QMessageBox::information(this, "Information", "The prescription has " + QString::number(srv.add_prescription(txt_name->text().toStdString())) + " medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});
	QObject::connect(btn_empty_prescription, &QPushButton::clicked, this, [&]() {
		srv.empty_prescription();
		QMessageBox::information(this, "Information", "The prescription has 0 medicine!");
		});
	QObject::connect(btn_export_HTML, &QPushButton::clicked, [&]() {
		try {
			QMessageBox::information(this, "Information", "The prescription has " + QString::number(srv.export_prescription(txt_file_name->text().toStdString())) + " medicine!");
		}
		catch (const FileException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		catch (const RepositoryException& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_message())); }
		});
}