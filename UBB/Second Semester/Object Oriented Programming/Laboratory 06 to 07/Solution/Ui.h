#pragma once
#include "Service.h"


class Ui {
private:
	Service& srv;

	/*
	prints a list of saved medicine
	input - a vector
	output - prints a list of saved medicine
	*/
	void ui_print_medicine(const Lista<Medicine>&);

	/*
	Reads data form the  keyboard and adds the medicine
	Throws an exception if it can't be saved or is not valid
	input -
	output - throws an exception if the medicine can't be saved or is not valid
	*/
	void ui_add_medicine();

	/*
	Reads data form the  keyboard and modifies the medicine
	Throws an exception if it can't be modified or is not valid
	input -
	output - throws an exception if the medicine can't be modified or is not valid
	*/
	void ui_modify_medicine();

	/*
	Reads data form the  keyboard and deletes the medicine
	Throws an exception if it can't be deleted or is not valid
	input -
	output - throws an exception if the medicine can't be modified or is not valid
	*/
	void ui_remove_medicine();

	/*
	Reads data form the keyboard and filters the medicine
	Throws an exception if the data is not valid
	input -
	output - throws an exception if the medicine can't be modified or is not valid
	*/
	void ui_filtration();

	/*
	Reads data form the keyboard and sorts the medicine
	Throws an exception if the data is not valid
	input -
	output - throws an exception if the medicine can't be modified or is not valid
	*/
	void ui_sort();

public:


	/*
	Constructor for Ui class
	input - a service
	output - a ui
	*/
	Ui(Service& srv) noexcept : srv{ srv } {}

	/*
	Do not allow to make copy for an object of type Ui
	*/
	Ui(const Ui& other_ui) = delete;

	/*
	Prints the menu
	*/
	void ui_print_menu();

	/*
	Execute a command
	input - a command
	output - thows exceptions for every invalid data or unsuccessfull command
	*/
	void ui_execute_cmd(int cmd);

	/*
	runs the program
	*/
	void run();
};

class UiException {
private:
	std::string message;
public:
	/*
	Default constructor for UiException class
	input - a message
	output - a repository exception
	*/
	UiException(std::string msg) :message{ msg } {}

	/*
	Getter metod for message
	*/
	const std::string& get_message() const noexcept {
		return message;
	}
};