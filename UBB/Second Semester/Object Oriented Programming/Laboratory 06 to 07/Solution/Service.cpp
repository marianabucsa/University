#include "Service.h"
#include <algorithm>


void Service::add_medicine(const std::string name, float price, const std::string manufacturer, const std::string substance) {
	Medicine m(name, price, manufacturer, substance);
	this->val.validate(m);
	this->repo.add(m);
}

void Service::modify_medicine(const std::string name, float price, const std::string manufacturer, const std::string substance){
	Medicine m(name,price,manufacturer,substance);
	this->val.validate(m);
	this->repo.modify(m);
}

void Service::remove_medicine(const std::string name) {
	Medicine m(name,122,"Pfizer","paracetamol");
	this->val.validate(m);
	this->repo.remove(m);
}

const Lista<Medicine>& Service::get_all_medicine() const noexcept {
	return this->repo.get_all();
}

Lista<Medicine> Service:: filter_medicine_price_lower(float price) const{
	Lista<Medicine> copy;
	const Lista<Medicine> l= this->get_all_medicine();
	Iterator<Medicine> it = l.iterator();
	while (it.valid()) {
		if (it.element().get_price() <= price) {
			copy.add(it.element());
		}
		it.next();
	}
	return copy;
}

Lista<Medicine> Service::filter_medicine_price_gratter(float price) const {
	Lista<Medicine> copy;
	const Lista<Medicine> l = this->get_all_medicine();
	Iterator<Medicine> it = l.iterator();
	while (it.valid()) {
		if (it.element().get_price() >= price) {
			copy.add(it.element());
		}
		it.next();
	}
	return copy;
}

Lista<Medicine> Service::filter_medicine_substance(std::string substance) const {
	Lista<Medicine> copy;
	const Lista<Medicine> l = this->get_all_medicine();
	Iterator<Medicine> it = l.iterator();
	while (it.valid()) {
		if (it.element().get_substance() == substance) {
			copy.add(it.element());
		}
		it.next();
	}
	return copy;
}

Lista<Medicine> Service::sort_by_name() const {
	Lista<Medicine> copy = this->get_all_medicine();
	copy.sort(cmp_name);
	return copy;
}

Lista<Medicine> Service::sort_by_manufacturer() const {
	Lista<Medicine> copy = this->get_all_medicine();
	copy.sort(cmp_manufacturer);
	return copy;
}

Lista<Medicine> Service::sort_by_substance_price() const {
	Lista<Medicine> copy = this->get_all_medicine();
	copy.sort(cmp_substance_price);
	return copy;
}
