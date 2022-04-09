#include "Repository.h"

void Repository::add(const Medicine& m) {

	for (auto& med : medicine) {
		if (med == m)
			throw RepositoryException("Medicine already exists!\n");
	}
	medicine.push_back(m);
}

void Repository::modify(const Medicine& m) {
	const int poz = find(m);
	this->medicine.at(poz) = m;
}

 void Repository::remove(const Medicine& m) {
	 const int poz = find(m);
	 this->medicine.erase(medicine.begin() + poz);
}

int Repository::find(const Medicine& m) {
	int i = 0;
	for (auto& med : medicine)
	{
		if (med == m)
			return i;
		i++;
	}
	throw RepositoryException("Medicine doesn't exist!\n");
}

const std::vector<Medicine>& Repository::get_all() {
	return this->medicine;
}

size_t Repository::size_rep() {
	return this->medicine.size();
}

void FileRepository::load_from_file() {
	std::ifstream in(filename);
	if (!in.is_open())
		throw FileException("Error opening " + filename);
	medicine.clear();
	while (!in.eof()) {
		int k = 0;
		float price = 0;
		std::string buf, name, manufacturer, substance;
		in >> name;
		if (in.eof())
			break;
		while (k != 3) {
			in >> buf;
			if (buf == ";")
				k++;
			else {
				if (k == 0)
					name.append(" "+buf);
				if (k == 1)
					if (manufacturer == "")
						manufacturer.append(buf);
					else
						manufacturer.append(" "+buf);
				if (k == 2)
					if (substance == "")
						substance.append(buf);
					else
						substance.append(" " + buf);
			}
		}
		in >> price;
		Medicine m{ name.c_str(), price, manufacturer.c_str(), substance.c_str() };
		Repository::add(m);
	}
	in.close();
}

void FileRepository::write_to_file() {
	std::ofstream out(filename);
	for (auto& m : medicine)
		out << m.get_name() << " ; " << m.get_manufacturer() << " ; " << m.get_substance() << " ; " << m.get_price() << std::endl;
	out.close();
}