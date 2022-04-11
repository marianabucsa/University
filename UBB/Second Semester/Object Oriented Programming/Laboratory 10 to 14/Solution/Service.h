#pragma once
#include "Repository.h"
#include "Validator.h"

class Service {
private:
	AbstractRepo& repo;
	Validator& val;
	Prescription pre;
	std::vector<std::unique_ptr<UndoAction>> undo;
public:

	/*
	Constructor for Service class
	input - a repository, a validator
	output - a service
	*/
	Service(AbstractRepo& repo, Validator& val) noexcept: repo{repo},val{val}{}

	/*
	Do not allow to make copy for an object of type Service
	*/
	Service(const Service& other_srv) = delete;

	/*
	Create a medicine and stores it
	Throw an exception if the medicine is not valid or it already exists
	input -a name, a price, a manufacturer, a substance
	output - throw an exception if the medicine is not valid or it already exists
	*/
	void add_medicine(const std::string, float, const std::string, const std::string);


	/*
	Create a medicine and and replaces a medicine with the same name 
	Throw an exception if the medicine is not valid or does not exist
	input -a name, a price, a manufacturer, a substance
	output - throw an exception if the medicine is not valid or does not exist
	*/
	void modify_medicine(const std::string, float, const std::string, const std::string);

	/*
	Create a medicine and deletes the one with the same name
	Throw an exception if the medicine is not valid or does not exist
	input - a name, a price, a manufacturer, a substance
	output - throw an exception if the medicine is not validor does not exist
	*/
	void remove_medicine(const std::string);

	/*
	Return all the medicine which were saved
	input -
	ouput - returns a vector with all the medicine
	*/
	const std::vector<Medicine>& get_all_medicine() const;

	/*
	Filters the medicine by maximum price
	input - a price
	output - returns the list of the medicine which has the price <= then the given price
	*/
    std::vector<Medicine> filter_medicine_price_lower(float) const;

	/*
	Filters the medicine by minimum price
	input - a price
	output - returns the list of the medicine which has the price >= then the given price
	*/
	std::vector<Medicine> filter_medicine_price_greater(float) const;

	/*
	Filters the medicine by substance
	input - a substance
	output - returns the list of the medicine which has the substance equal to the given substance
	*/
	std::vector<Medicine> filter_medicine_substance(std::string) const;

	/*
	Sort a list ascending by name
	input -
	output - returns the list of medicine sorted ascending by name
	*/
	std::vector<Medicine> sort_by_name() const;

	/*
	Sort a list ascending by manufacturer
	input -
	output - returns the list of medicine sorted ascending by manufacturer
	*/
	std::vector<Medicine> sort_by_manufacturer() const;

	/*
	Sort a list ascending by substance and price
	input -
	output - returns the list of medicine sorted ascending by substance and by price
	*/
	std::vector<Medicine> sort_by_substance_price() const;

	/*
	Adds a number of medicine to the prescription
	*/
	int random_prescription(int );

	/*
	Adds a medicine to the prescription
	*/
	int add_prescription(std::string);

	/*
	Deletes all medicine from the prescription
	*/
	void empty_prescription() noexcept;

	/*
	Prints all the medicine from the prescription
	*/
	std::vector<Medicine> get_prescription();

	int export_prescription(std::string);

	std::map<std::string, int> get_map();

	void undo_action();

	void add_observer(Observer* obs);
};
