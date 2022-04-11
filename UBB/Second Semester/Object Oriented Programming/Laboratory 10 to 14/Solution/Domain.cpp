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

void Prescription::add(const Medicine& m) {
	prescription.push_back(m);
	notify();
}
/*
void Prescription::modify(const Medicine& m) {
	int i = 0;
	for (auto& med : prescription) {
		if (med == m) {
			prescription[i] = m;
			break;
		}
		i++;
	}
	notify();
}

void Prescription::remove(const Medicine& m) {
	int i = 0;
	for (auto& med : prescription) {
		if (med == m) {
			prescription.erase(prescription.begin() + i);
			break;
		}
		i++;
	}
	notify();
}
*/

void Prescription::empty() noexcept{
	prescription.clear();
	notify();
}

void Prescription::fill_random(size_t nr, std::vector<Medicine> v) {
	//std::shuffle(v.begin(), v.end(), std::default_random_engine(std::random_device{}()));
	nr = nr + prescription.size();
	while (prescription.size() < nr) {
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> const dist(0, v.size() - 1);
		const int rndNr = dist(mt);// numar aleator intre [0,size-1]
		prescription.push_back(v.at(rndNr));
	}
	notify();
}

const std::vector<Medicine>& Prescription::get_presc() const noexcept {
	return prescription;
}

int Prescription::size() noexcept{
	return prescription.size();
}

void export_to_HTML(const std::string& file, const std::vector<Medicine>& v)
{
	std::ofstream out(file, std::ios::trunc);
	if (!out.is_open())
		throw FileException("Could not open file " + file);
	out << "<html><body>" << std::endl;
	out << "<table border=\"3\" style=\"width:200 % \">" << std::endl;
	for (const auto& m : v) {
		out << "<tr>" << std::endl;
		out << "<td>" << m.get_name() << "</td>" << std::endl;
		out << "<td>" << m.get_manufacturer() << "</td>" << std::endl;
		out << "<td>" << m.get_substance() << "</td>" << std::endl;
		out << "<td>" << m.get_price() << "</td>" << std::endl;
		out << "</tr>" << std::endl;
	}
	out << "</table>" << std::endl;
	out << "</body></html>" << std::endl;
	out.close();
}