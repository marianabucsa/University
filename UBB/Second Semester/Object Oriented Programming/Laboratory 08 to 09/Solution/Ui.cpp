#include "Ui.h"
#include <iostream>

void Ui::ui_print_medicine(const std::vector<Medicine>& medicine) {
	if (medicine.size()==0)
		std::cout << std::endl << "No medicine added!" << std::endl;
	else {
		for (const auto& med : medicine)
			std::cout << med;
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
	std::vector<Medicine> v;
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
				v = this->srv.filter_medicine_price_lower(price);
				if (v.size()==0)
					std::cout << "No medicine to show! " << std::endl << std::endl;
				else
					ui_print_medicine(v);
			}
			if (mode.compare(">=") == 0){
				v = this->srv.filter_medicine_price_gratter(price);
				if (v.size()==0)
					std::cout << "No medicine to show! " << std::endl << std::endl;
				else
					ui_print_medicine(v);
			}
		}
	}
	if (filter.compare("substance") == 0) {
		std::cout << " Enter active substance: ";
		std::cin >> substance;
		v = this->srv.filter_medicine_substance(substance);
		if (v.size()==0)
			std::cout << "No medicine to show! " << std::endl << std::endl;
		else
			ui_print_medicine(v);
	}
}

void Ui::ui_sort() {
	std::string field;
	std::vector<Medicine> v;
	std::cout << "Enter sort by field(name/manufacturer/substance+price): ";
	std::cin >> field;
	if (field.compare("name") != 0 && field.compare("manufacturer") != 0 && field.compare("substance+price") != 0)
		throw UiException("Invalid filter!");
	if (field.compare("name") == 0) {
		v = this->srv.sort_by_name();
		ui_print_medicine(v);
	}
	if (field.compare("manufacturer") == 0) {
		v = this->srv.sort_by_manufacturer();
		ui_print_medicine(v);
	}
	if (field.compare("substance+price") == 0) {
		v = this->srv.sort_by_substance_price();
		ui_print_medicine(v);
	}
}

void Ui::ui_random_prescription() {
	unsigned int nr;
	std::cout << "How many to add?\n";
	std::cin >> nr;
	if (nr <= 0)
		throw UiException("Invalid number!\n");
	const int k = srv.random_prescription(nr);
	std::cout << "There are " << k << " medicine in the prescription!\n";

}

void Ui::ui_add_prescription() {
	std::string name;
	std::cout << "Enter medicine name: \n";
	std::cin >> name;
	const int k = srv.add_prescription(name);
	std::cout << "There are " << k << " medicine in the prescription!\n";
}

void Ui::ui_empty_prescription() {
	srv.empty_prescription();
	std::cout << "There are 0 medicine in the prescription!\n";
}

void Ui::ui_export_prescription() {
	std::string file;
	std::cout << "Enter the HTML file : \n";
	try {
		std::cin >> file;
	}
	catch(UiException ue) { std::cout << std::endl << "File error!\n" << std::endl << std::endl; }
	const int k=srv.export_prescription(file);
	this->files.push_back(file);
	std::cout << "There are " << k << " medicine in the prescription!\n";
}

void Ui::ui_print_dictionar(std::map<std::string, int>& dic) {
	for (const auto& man : dic) {
		std::cout << man.first << " " << man.second<<std::endl;
	}
}

void Ui::ui_undo() {
	this->srv.undo_action();
	std::cout << "\nUndo succesfully done!\n";
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
	std::cout << "\t \t \t \t||       7. Random prescription.     ||" << std::endl;
	std::cout << "\t \t \t \t||       8. Add to prescription.     ||" << std::endl;
	std::cout << "\t \t \t \t||       9. Empty prescription.      ||" << std::endl;
	std::cout << "\t \t \t \t||       10. Export prescription.    ||" << std::endl;
	std::cout << "\t \t \t \t||       11. Raport manufacturer.    ||" << std::endl;
	std::cout << "\t \t \t \t||              12. Undo.            ||" << std::endl;
	std::cout << "\t \t \t \t++===================================++" << std::endl;
}
void Ui::ui_execute_cmd(int cmd) {

	const std::vector<Medicine> v = srv.get_all_medicine();
	std::map<std::string, int> dic = srv.get_map();
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
	case 7:
		ui_random_prescription();
		break;
	case 8:
		ui_add_prescription();
		break;
	case 9:
		ui_empty_prescription();
		break;
	case 10:
		ui_export_prescription();
		break;
	case 11:
		ui_print_dictionar(dic);
		break;
	case 12:
		ui_undo();
		break;
	}
}

void Ui::run()
{
	std::string cmd;
	int nr = -1;
	constexpr int nrcmds = 13;
	while (true) {
		ui_print_menu();
		std::cout << "Enter command: ";
		try {
			std::cin >> cmd;
			nr = stoi(cmd);
			try {
				if (nr >= 0 && nr < nrcmds)
				{
					if (nr == 0) {
						for (auto& file : files) {
							std::ofstream out(file, std::ios::trunc);
							out.close();
						}
						return;
					}
					ui_execute_cmd(nr);
				}
				else
					std::cout << "Invalid command!" << std::endl;
			}
			catch (ValidatorException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (RepositoryException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (UiException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (FileException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
			catch (UndoException e) { std::cout << std::endl << e.get_message() << std::endl << std::endl; }
		}
		catch (...) { std::cout << "Invalid number!" << std::endl; }
	}
}