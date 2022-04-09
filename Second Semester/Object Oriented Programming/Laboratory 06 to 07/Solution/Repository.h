#pragma once
#include "Template_Lista.h"
#include "Domain.h"



template <class TElem> class Repository {
private:
	Lista<TElem> medicine;
public:
	/*
	Default constructor for Repository class
	input - 
	output - a repository
	*/
	Repository() = default;

	/*
	Do not allow to make copy for an object of type Repository
	*/
	Repository(const Repository& other_rep) = delete;


	/*
	Store a medicine
	Throw an exception if the medicine already exists
	input -a medicine
	output - throw an exception if the medicine already exists
	*/
	void add(const TElem&);


	/*
	Modify an offer
	Throw an exception if the offer does not exist
	input - a medicine
	output - throw an exception if the medicine does not exists
	*/
	void modify(const TElem&);

	/*
	Verify if a medicine already exists 
	input - a medicine
	output - the pozition of the element or throws an exception if the medicine does not exists
	*/
	const TElem find(const  TElem&);

	/*
	Remove a medicine
	Throw an exception if the medicine does not exist
	input -a medicine
	output - throw an exception if the medicine does not exists
	*/
	void remove(const  TElem&);

	/*
	Return all the medicine which were saved
	input - 
	ouput - returns a vector with all the medicine
	*/
	const Lista<TElem>& get_all() const noexcept;

	/*
	Return the number of medicine
	input -
	output- return the number of medicine
	*/
	size_t size_rep() const noexcept;
};

class RepositoryException {
private:
	std::string message;
public:
	/*
	Default constructor for RepositoryException class
	input - a message
	output - a repository exception
	*/
	RepositoryException(std::string msg):message{msg}{}

	/*
	Getter metod for message
	*/
	const std::string& get_message() const noexcept {
		return message;
	}
};