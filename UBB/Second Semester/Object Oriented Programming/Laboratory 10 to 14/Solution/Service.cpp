#include "Service.h"
#include <algorithm>


void Service::add_medicine(const std::string name, float price, const std::string manufacturer, const std::string substance) {
	Medicine m(name, price, manufacturer, substance);
	this->val.validate(m);
	this->repo.add(m);
	undo.push_back(std::make_unique<AddUndo>(this->repo, m));
}

void Service::modify_medicine(const std::string name, float price, const std::string manufacturer, const std::string substance){
	Medicine m(name,price,manufacturer,substance);
	this->val.validate(m);
	Medicine med = get_all_medicine().at(repo.find(m));
	this->repo.modify(m);
	undo.push_back(std::make_unique<ModifyUndo>(this->repo, med));
}

void Service::remove_medicine(const std::string name) {
	Medicine m(name,122,"Pfizer","paracetamol");
	this->val.validate(m);
	Medicine med = get_all_medicine().at(repo.find(m));
	this->repo.remove(m);
	undo.push_back(std::make_unique<RemoveUndo>(this->repo, med));
}

void Service::undo_action() {
	if (this->undo.empty())
		throw UndoException("Undo action cannot be done!\n");
	undo.back()->do_undo();
	undo.pop_back();
}

const std::vector<Medicine>& Service::get_all_medicine() const {
	return this->repo.get_all();
}
std::vector<Medicine> Service:: filter_medicine_price_lower(float price) const{
	std::vector<Medicine> l = this->get_all_medicine();
	std::vector<Medicine> copy;
	std::copy_if(l.begin(), l.end(), std::back_inserter(copy), [&price](const Medicine& m) noexcept { return m.get_price() <= price; });
	return copy;
}

std::vector<Medicine> Service::filter_medicine_price_greater(float price) const {
	std::vector<Medicine> l = this->get_all_medicine();
	std::vector<Medicine> copy;
	std::copy_if(l.begin(), l.end(), std::back_inserter(copy), [&price](const Medicine& m) noexcept { return m.get_price() >= price; });
	return copy;
}

std::vector<Medicine> Service::filter_medicine_substance(std::string substance) const {
	std::vector<Medicine> l = this->get_all_medicine();
	std::vector<Medicine> copy;
	std::copy_if(l.begin(), l.end(), std::back_inserter(copy), [&substance](const Medicine& m) noexcept { return m.get_substance() == substance; });
	return copy;
}

std::vector<Medicine> Service::sort_by_name() const {
	std::vector<Medicine> copy;
	for (const auto& m : this->get_all_medicine())
		copy.push_back(m);
	std::sort(copy.begin(), copy.end(), cmp_name);
	return copy;
}

std::vector<Medicine> Service::sort_by_manufacturer() const {
	std::vector<Medicine> copy;
	for (const auto& m : this->get_all_medicine())
		copy.push_back(m);
	std::sort(copy.begin(), copy.end(), cmp_manufacturer);
	return copy;
}

std::vector<Medicine> Service::sort_by_substance_price() const {
	std::vector<Medicine> copy;
	for (const auto& m : this->get_all_medicine())
		copy.push_back(m);
	std::sort(copy.begin(), copy.end(), cmp_substance_price);
	return copy;
}

int Service::random_prescription(int nr) {
	if (this->get_all_medicine().size() == 0)
		throw RepositoryException("There is no medicine to add!\n");
	pre.fill_random(nr, this->get_all_medicine());
	return pre.size();
}

int Service::add_prescription(std::string name) {
	int poz = this->repo.find(Medicine(name, 12, "default", "default"));
	std::cout << poz;
	pre.add(this->get_all_medicine().at(poz));
	return this->pre.size();
}

void Service::empty_prescription() noexcept{
	pre.empty();
}

std::vector<Medicine> Service::get_prescription() {
	return pre.get_presc();
}

int Service::export_prescription(std::string file) {
	if(this->pre.size()==0)
		throw RepositoryException("The prescription doesn't have any medicine to export!\n");
	export_to_HTML(file, pre.get_presc());
	return pre.size();
}

std::map<std::string, int> Service::get_map() {
	std::map<std::string, int> dic;
	std::vector<Medicine> copy = this->get_all_medicine();
	//std::sort(copy.begin(), copy.end(), cmp_manufacturer);
	for (const auto& m : copy) {
		dic[m.get_manufacturer()] = 0;
	}
	for (const auto& m : copy) {
		dic[m.get_manufacturer()]++;
	}
	return dic;
}

void Service::add_observer(Observer* obs) {
	pre.add_obs(obs);
}