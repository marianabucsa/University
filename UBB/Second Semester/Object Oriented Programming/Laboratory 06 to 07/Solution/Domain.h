#pragma once
#include <string>
#include <iostream>

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
	Medicine() = default;

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