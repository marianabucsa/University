#include "Validator.h"

void Validator::validate(const Medicine& m) {
	std::string error = "";
	if (m.get_name() == "")
		error += "Invalid name!\n";
	if (m.get_price() < 0)
		error += "Invalid price!\n";
	if (m.get_manufacturer() == "")
		error += "Invalid manufacturer!\n";
	if (m.get_substance() == "")
		error += "Invalid substance!\n";
	if (error != "")
		throw ValidatorException(error);
}