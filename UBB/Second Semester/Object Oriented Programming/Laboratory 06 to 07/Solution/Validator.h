#pragma once
#include "Domain.h"

class ValidatorException {
private:
	std::string message;
public: 
	/*
	Default constructor for ValidatorException class
	input - a message
	output - a validator exception
	*/
	ValidatorException(std::string message):message{message}{}

	/*
	Getter metod for message
	*/
	const std::string& get_message() const noexcept {
		return message;
	}
};

template <class TElem> class Validator {
public:
	/*
	Validates an object of type medicine
	input - a medicine
	output - thows an exception if if the medicine is not corect
	*/
	void validate(const Medicine&);
};