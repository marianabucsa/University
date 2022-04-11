#include "Ui.h"
#include <iostream>

void Ui::ui_print_medicine(const Lista<Medicine>& medicine) {
	if (medicine.vid())
		std::cout << std::endl << "No medicine added!" << std::endl;
	else {
		Iterator<Medicine> it = medicine.iterator();
		while (it.valid())
		{
			std::cout << it.element();
			it.next();
		}
		std::cout << std::endl << std::endl;
	}
}
void Ui::ui_add_medicine(){
	std::string name, manufacturer, substance, price_buff;
	float price = -1;
	std::cout << "Enter medicine name: ";
	std::cin >> name;
	std::cout << "Enter medicine price: ";
	std::cin >> price_buff;
	std::cout << "Enter medicine manufacturer: ";
	std::cin >> manufacturer;
	std::cout << "Enter medicine active substance: ";
	std::cin >> substance;
	price = stof(price_buff);
	this->srv.add_medicine(name, price, manufacturer, substance);
	std::cout << "Medicine succesfully added!\n" << std::endl << std::endl;
}
void Ui::ui_modify_medicine() {
	std::string name, manufacturer, substance, price_buff;
	float price = -1;
	std::cout << "Enter medicine name: ";
	std::cin >> name;
	std::cout << "Enter the new price: ";
	std::cin >> price_buff;
	std::cout << "Enter the new manufacturer: ";
	std::cin >> manufacturer;
	std::cout << "Enter the new active substance: ";
	std::cin >> substance;
	price = stof(price_buff);
	srv.modify_medicine(name, price, manufacturer, substance);
	std::cout << "Medicine succesfully modified!\n" << std::endl << std::endl;
}
void Ui::ui_remove_medicine() {
	std::string name;
	std::cout << "Enter medicine name: ";
	std::cin >> name;
	srv.remove_medicine(name);
	std::cout << "Medicine succesfully deleted!\n" << std::endl << std::endl;
}

void Ui::ui_filtration() {
	std::string filter, mode, substance;
	std::cout << "Enter filter(price/substance): ";
	std::cin >> filter;
	if (filter.compare("price")!=0 && filter.compare("substance")!=0)
		throw UiException("Invalid filter!");
	if (filter.compare("price") == 0)
	{
		std::cout << "Enter mode(<=,>=):";
		std::cin >> mode;
		if (mode.compare("<=")!=0 && mode.compare(">=")!=0)
			throw UiException("Invalid mode!");
		else {
			float price;
			std::cout << " Enter price: ";
			std::cin >> price;
			if (price < 0)
				throw UiException("Invalid price!");
			if (mode.compare("<=") == 0) {
				Lista<Medicine> v = this->srv.filter_medicine_price_lower(price);
				if (v.vid())
					std::cout << "No medicine to show! " << std::endl << std::endl;
				else
					ui_print_medicine(v);
			}
			if (mode.compare(">=") == 0){
				Lista<Medicine> v1 = this->srv.filter_medicine_price_gratter(price);
				if (v1.vid())
					std::cout << "No medicine to show! " << std::endl << std::endl;
				else
					ui_print_medicine(v1);
			}
		}
	}
	if (filter.compare("substance") == 0) {
		std::cout << " Enter active substance: ";
		std::cin >> substance;
		Lista<Medicine> v2 = this->srv.filter_medicine_substance(substance);
		if (v2.vid())
			std::cout << "No medicine to show! " << std::endl << std::endl;
		else
			ui_print_medicine(v2);
	}
}

void Ui::ui_sort() {
	std::string field;
	std::cout << "Enter sort by field(name/manufacturer/substance+price): ";
	std::cin >> field;
	if (field.compare("name") != 0 && field.compare("manufacturer") != 0 && field.compare("substance+price") != 0)
		throw UiException("Invalid filter!");
	if (field.compare("name") == 0) {
		Lista<Medicine> v = this->srv.sort_by_name();
		ui_print_medicine(v);
	}
	if (field.compare("manufacturer") == 0) {
		Lista<Medicine> v1 = this->srv.sort_by_manufacturer();
		ui_print_medicine(v1);
	}
	if (field.compare("substance+price") == 0) {
		Lista<Medicine> v2 = this->srv.sort_by_substance_price();
		ui_print_medicine(v2);
	}
}

void Ui::ui_print_menu() {
	std::cout << "\t \t \t \t++================Menu===============++" << std::endl;
	std::cout << "\t \t \t \t||             0. Exit.              ||" << std::endl;
	std::cout << "\t \t \t \t||          1. Add medicine.         ||" << std::endl;
	std::cout << "\t \t \t \t||         2. Modify medicine.       ||" << std::endl;
	std::cout << "\t \t \t \t||         3. Delete medicine.       ||" << std::endl;
	std::cout << "\t \t \t \t||          4. View medicine.        ||" << std::endl;
	std::cout << "\t \t \t \t||         5. Filter medicine.       ||" << std::endl;
	std::cout << "\t \t \t \t||          6. Sort medicine.        ||" << std::endl;
	std::cout << "\t \t \t \t++===================================++" << std::endl;
}
void Ui::ui_execute_cmd(int cmd) {
	const Lista<Medicine> v = srv.get_all_medicine();
	switch (cmd)
	{
	case 1:
		ui_add_medicine();
		break;
	case 2:
		ui_modify_medicine();
		break;
	case 3:
		ui_remove_medicine();
		break;
	case 4:
		ui_print_medicine(v);
		break;
	case 5:
		ui_filtration();
		break;
	case 6:
		ui_sort();
		break;
	}
}

void Ui::run()
{
	std::string cmd;
	int nr = -1;
	constexpr int nrcmds = 7;
	while (true) {
		ui_print_menu();
		std::cout << "Enter command: ";
		try {
			std::cin >> cmd;
			nr = stoi(cmd);
			try {
				if (nr >= 0 && nr < nrcmds)
				{
					if (nr == 0)
						return;
					ui_execute_cmd(nr);
				}
				else
					std::cout << "Invalid command!" << std::endl;
			}
			catch (ValidatorException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (RepositoryException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (UiException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
		}
		catch (...) { std::cout << "Invalid number!" << std::endl; }
	}
}