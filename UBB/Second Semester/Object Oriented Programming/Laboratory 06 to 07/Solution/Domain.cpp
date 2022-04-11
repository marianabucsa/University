#include "Domain.h"

int Medicine::c = 0;

const std::string& Medicine::get_name() const noexcept {
	return name;
}

const std::string& Medicine::get_manufacturer() const noexcept {
	return manufacturer;
}

const std::string& Medicine::get_substance() const noexcept {
	return substance;
}

const float& Medicine::get_price() const noexcept {
	return price;
}

bool Medicine::operator==(const Medicine& m) noexcept {
	if (m.get_name()==this->get_name())
		return true;
	return false;
}

bool Medicine::operator !=(const Medicine& m) noexcept{
	return m.get_name() != this->get_name();
}

std::ostream& operator<<(std::ostream& stream, const Medicine& m)
{
	stream << "Name: " << m.name << "\t" << "Manufacturer: " << m.manufacturer << "\t" << "Substance: " << m.substance << "\t" << "Price: " << m.price << std::endl;
	return stream;
}

bool cmp_name(const Medicine& m1, const Medicine& m2) noexcept {
	return m1.get_name() < m2.get_name();
}

bool cmp_manufacturer(const Medicine& m1, const Medicine& m2) noexcept {
	return m1.get_manufacturer() < m2.get_manufacturer();
}

bool cmp_substance_price(const Medicine& m1, const Medicine& m2) noexcept {
	if (m1.get_substance() != m2.get_substance())
		return m1.get_substance() < m2.get_substance();
	return m1.get_price() < m2.get_price();
}