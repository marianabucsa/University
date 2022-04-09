#pragma once
#include "Domain.h"
#include <vector>
#include <string>
#include <time.h>

class AbstractRepo {
public:
	AbstractRepo() = default;

	AbstractRepo(const AbstractRepo& other_rep) = delete;

	virtual void add(const Medicine&) = 0;

	virtual void modify(const Medicine&) = 0;

	virtual int find(const  Medicine&) = 0;

	virtual void remove(const  Medicine&) = 0;

	virtual const std::vector<Medicine>& get_all() = 0;

	virtual size_t size_rep() = 0;

	virtual ~AbstractRepo() = default;
};

class Repository :public AbstractRepo {
protected:
	std::vector<Medicine> medicine;
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
	virtual void add(const Medicine&) override;


	/*
	Modify an offer
	Throw an exception if the offer does not exist
	input - a medicine
	output - throw an exception if the medicine does not exists
	*/
	virtual void modify(const Medicine&) override;

	/*
	Verify if a medicine already exists 
	input - a medicine
	output - the pozition of the element or throws an exception if the medicine does not exists
	*/
	virtual int find(const  Medicine&)override;

	/*
	Remove a medicine
	Throw an exception if the medicine does not exist
	input -a medicine
	output - throw an exception if the medicine does not exists
	*/
	virtual void remove(const  Medicine&)override;

	/*
	Return all the medicine which were saved
	input - 
	ouput - returns a vector with all the medicine
	*/
	virtual const std::vector<Medicine>& get_all() override;

	/*
	Return the number of medicine
	input -
	output- return the number of medicine
	*/
	virtual size_t size_rep() override;
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

class FileRepository :public Repository {
private:
	std::string filename;
	void load_from_file();
	void write_to_file();
public:
	FileRepository(std::string filename) {
		this->filename = filename;
		load_from_file();
	}

	void add(const Medicine& m) override {
		load_from_file();
		Repository::add(m);
		write_to_file();
	}

	void modify(const Medicine& m) override {
		load_from_file();
		Repository::modify(m);
		write_to_file();
	}
	void remove(const Medicine& m) override {
		load_from_file();
		Repository::remove(m);
		write_to_file();
	}

	int find(const Medicine& m) override {
		load_from_file();
		return Repository::find(m);
	}

	const std::vector<Medicine>& get_all() override {
		load_from_file();
		return Repository::get_all();
	}

	size_t size_rep() override {
		load_from_file();
		return Repository::size_rep();
	}
};

class UndoAction {
public:
	virtual void do_undo() = 0;
	virtual ~UndoAction() = default;
};

class AddUndo :public UndoAction {
private:
	Medicine m_added;
	AbstractRepo& repo;
public:
	AddUndo(AbstractRepo& repo, const Medicine& m) :repo{ repo }, m_added{ m } {}
	void do_undo() override {
		repo.remove(m_added);
	}
};

class RemoveUndo :public UndoAction {
private:
	Medicine m_removed;
	AbstractRepo& repo;
public:
	RemoveUndo(AbstractRepo& repo, const Medicine& m) :repo{ repo }, m_removed{ m } {}
	void do_undo() override {
		repo.add(m_removed);
	}
};

class ModifyUndo :public UndoAction {
private:
	Medicine m_modified;
	AbstractRepo& repo;
public:
	ModifyUndo(AbstractRepo& repo, const Medicine& m) :repo{ repo }, m_modified{ m } {}
	void do_undo() override {
		repo.modify(m_modified);
	}
};


class UndoException {
private:
	std::string message;
public:
	UndoException(std::string msg) :message{ msg } {}
	const std::string& get_message() const noexcept {
		return message;
	}
};


class ExceptionRepo: public AbstractRepo {
private:
	double prob;
	std::map<std::string, Medicine> medicine;
	std::vector<Medicine> medi;
public:
	ExceptionRepo(double prob) {
		this->prob = prob;
	}

	void add(const Medicine& m) override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception! \n");
		for (const auto& med : medicine)
			if (med.second == m)
				throw RepositoryException("Medicine already exists!");
		medicine[m.get_name()] = m;
	}

	void modify(const Medicine& m) override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception! \n");
		std::map<std::string, Medicine>::iterator it = medicine.find(m.get_name());
		if (it == medicine.end())
			throw RepositoryException("Medicine doesn't exist!");
		it->second = m;
	}

	int find(const  Medicine& m) override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception!\n");
		int i = 0;
		for (auto med : medicine) {
			if (med.second == m)
				return i;
			i++;
		}
		throw RepositoryException("Medicine doesn't exist!\n");
	}

	void remove(const  Medicine& m) override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception! \n");
		std::map<std::string, Medicine>::iterator it = medicine.find(m.get_name());
		if (it == medicine.end())
			throw RepositoryException("Medicine doesn't exist!\n");
		medicine.erase(m.get_name());
	}

	const std::vector<Medicine>& get_all() override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception! \n");
		this->medi.clear();
		for (auto i : medicine) {
			medi.push_back(i.second);
		}
		return medi;
	}

	size_t size_rep() override {
		srand((unsigned)time(nullptr));
		const double x = (double)rand() / RAND_MAX;
		std::cout << x << std::endl;
		if (this->prob > x)
			throw RepositoryException("Probability exception! \n");
		return medicine.size();
	}
};