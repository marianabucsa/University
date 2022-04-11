#pragma once
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <map>

class Medicine {
private:
	std::string name;
	std::string manufacturer;
	std::string substance;
	float price;

	

public: 
	static int c;
	/*
	Create a new object of type Medicine
	input: -
	output: a medicine
	*/
	Medicine() noexcept{
		price = 0;
	}

	/*
	Create a new object of type Medicine	
	input - name, price, manufacturer,substance
	output - a medicine
	*/
	Medicine(const std:: string name, float price, const std:: string manufacturer, const std::string substance): name{name}, manufacturer{manufacturer}, substance{substance},price{price}{}
	
	/*
	Copy constructor
	input - a medicine
	output - a copy of the medicine
	*/
	Medicine(const Medicine &m) :name{ m.name }, manufacturer{ m.manufacturer }, substance{ m.substance }, price{ m.price } {
		c++;
	}

	/*
	Getter metod for name
	*/
	const std::string& get_name() const noexcept;
	
	/*
	Getter metod for manufacturer
	*/
	const std::string& get_manufacturer() const noexcept;
	
	/*
	Getter metod for substance
	*/
	const std::string& get_substance() const noexcept;
	
	/*
	Getter metod for price
	*/
	const float& get_price() const noexcept;
	
	/*
	Initialize the == operator for Medicine entities
	input - a medicine
	output - a boolean number
	*/
	bool operator==(const Medicine&) noexcept;

	const bool operator==(const Medicine& m) const noexcept {
		return m.get_name() == this->get_name();
	}
	/*
	Initialize the != operator for Medicine entities
	input - a medicine
	output - a boolean number
	*/
	bool operator!=(const Medicine&) noexcept;

	Medicine& operator=(const Medicine&) = default;

	Medicine(Medicine&&) = default;

	Medicine& operator=(Medicine&&) = default;

	virtual ~Medicine() = default;

	friend std::ostream& operator<<(std::ostream&, const Medicine&);
};

/*
Compare the names of 2 objects of type Medicine
input - 2 objects of type medicine
output - a boolean number
*/
bool cmp_name(const Medicine& m1, const Medicine& m2) noexcept;

/*
Compare the manufacturers of 2 objects of type Medicine
input - 2 objects of type medicine
output - a boolean number
*/
bool cmp_manufacturer(const Medicine& m1, const Medicine& m2) noexcept;

/*
Compare the substances of 2 objects of type Medicine. If the substances are equal , it compares the price .
input - 2 objects of type medicine
output - a boolean number
*/
bool cmp_substance_price(const Medicine& m1, const Medicine& m2) noexcept;

std::ostream& operator<<(std::ostream&, const Medicine&);


class Observer {
public:
	virtual void update() = 0;
};

class Observable {
protected:
	std::vector<Observer*> obs;
	void notify() {
		for (auto o : obs)
			o->update();
	}
public:
	void add_obs(Observer* o) {
		obs.push_back(o);
	}

	void remove_obs(Observer* ob) {
		obs.erase(std::remove(begin(obs), end(obs), ob),
			obs.end());
	}
};

class Prescription: public Observable{
private:
	std::vector<Medicine> prescription;
public:
	Prescription() = default;

	/*
	Adds a medicine to the prescription
	*/
	void add(const Medicine& m);

	/*
	Modifies a medicine in the prescription
	*/
	//void modify(const Medicine& m);

	/*
	Removes a medicine from the prescription
	*/
	//void remove(const Medicine& m);

	/*
	Deletes all medicine from the prescription
	*/
	void empty() noexcept;

	/*
	Adds a number of medicine to the prescription
	*/
	void fill_random(size_t nr, std::vector<Medicine> v);

	/*
	Returns a vector containing all the medicine in the prescription
	*/
	const std::vector<Medicine>& get_presc() const noexcept;

	/*
	Returns the size of the prescription
	*/
	int size() noexcept;

};

class FileException {
private:
	std::string message;
public:
	FileException(std::string msg) :message{ msg } {}
	const std::string& get_message() const noexcept {
		return message;
	}
};

void export_to_HTML(const std::string& file, const std::vector<Medicine>& v);

class Manufacturer_med {
private:
	std::string  manufacturer;
	int count;
public:

	Manufacturer_med(std::string manufacturer, int count) {
		this->manufacturer = manufacturer;
		this->count = count;
	}
	const std::string& get_manufacturer() noexcept {
		return this->manufacturer;
	}

	const int& get_count() noexcept {
		return this->count;
	}
};