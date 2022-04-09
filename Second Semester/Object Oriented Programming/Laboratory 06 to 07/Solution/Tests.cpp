#include "Tests.h"
#include <assert.h>
#include <string>

void run_all_tests() {
	std::cout << "Running tests ...\n";
	test_domain();
	test_repository();
	test_service();
	test_validator();
	test_list();
	std::cout << "All tests completed!\n";
}

void test_domain() {
	Medicine m("paracetamol", 3.5, "pfizer", "paracetamol");
	assert(m.get_name() == "paracetamol");
	assert(m.get_price() == 3.5);
	assert(m.get_manufacturer() == "pfizer");
	assert(m.get_substance() == "paracetamol");
	Medicine m1("paracetamol", 4.5, "ggg", "paracetamol");
	assert(m == m1);
	Medicine m2 ("algocalmin", 4.5, "ggg", "paracetamol");
	assert(!(m == m2));
}

void test_repository() {
	Repository<Medicine> repo;
	Medicine m("paracetamol", 3.5, "pfizer", "paracetamol");
	repo.add(m);
	repo.find(m);
	assert(repo.size_rep() == 1);
	Medicine m1("algocalmin", 3.5, "pfizer", "paracetamol");
	try {
		const Medicine poz = repo.find(m1); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	try {
		repo.modify(m1); assert(false);
	}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	try {
		repo.remove(m1); assert(false);
	}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	Medicine m2("paracetamol", 4.5, "pf", "paracetamol");

	try {
		repo.add(m2); assert(false);
	}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine already exists!\n"); }

	repo.modify(m2);
	repo.add(m1);
	assert(repo.size_rep() == 2);
	Lista<Medicine> v = repo.get_all();
	assert(v.element(0) == m2);
	assert(v.element(1) == m1);
	repo.remove(m2);
	assert(repo.size_rep() == 1);
	try {
		const Medicine poz = repo.find(m2); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }
}

void test_service() {
	Repository<Medicine> repo;
	Validator<Medicine> val;
	Service srv{ repo, val };
	srv.add_medicine("s", 2, "h", "l");
	assert(repo.size_rep() == 1);
	try {
		srv.add_medicine("", 3.4F, "f", "f"); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\n"); }
	try {
		srv.modify_medicine("", -8, "t", "t"); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\nInvalid price!\n"); }
	try {
		srv.add_medicine("", -3, "", ""); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\nInvalid price!\nInvalid manufacturer!\nInvalid substance!\n"); }
	srv.modify_medicine("s",4.5, "h", "l");
	srv.add_medicine("ab", 5, "ggg", "p");
	Medicine m("s", 4.5, "h", "l");
	assert(m == srv.get_all_medicine().element(0));
	srv.add_medicine("a", 6, "v", "b");
	srv.add_medicine("b", 1, "n", "j");
	srv.add_medicine("c", 3, "k", "j");
	assert(repo.size_rep() == 5);
	Lista<Medicine> v = srv.sort_by_name();
	assert(v.element(0) == srv.get_all_medicine().element(2));
	assert(v.element(1) == srv.get_all_medicine().element(1));
	assert(v.element(2) == srv.get_all_medicine().element(3));
	assert(v.element(3) == srv.get_all_medicine().element(4));
	assert(v.element(4) == srv.get_all_medicine().element(0));
	Lista<Medicine> v1 = srv.sort_by_manufacturer();
	assert(v1.element(0) == srv.get_all_medicine().element(1));
	assert(v1.element(1) == srv.get_all_medicine().element(0));
	assert(v1.element(2) == srv.get_all_medicine().element(4));
	assert(v1.element(3) == srv.get_all_medicine().element(3));
	assert(v1.element(4) == srv.get_all_medicine().element(2));
	Lista<Medicine> v2 = srv.sort_by_substance_price();
	assert(v2.element(0) == srv.get_all_medicine().element(2));
	assert(v2.element(1) == srv.get_all_medicine().element(3));
	assert(v2.element(2) == srv.get_all_medicine().element(4));
	assert(v2.element(3) == srv.get_all_medicine().element(0));
	assert(v2.element(4) == srv.get_all_medicine().element(1));
	Lista<Medicine> v3 = srv.filter_medicine_price_lower(5);
	assert(v3.size() == 4);
	Lista<Medicine> v4 = srv.filter_medicine_price_gratter(5);
	assert(v4.size() == 2);
	Lista<Medicine> v5 = srv.filter_medicine_substance("j");
	assert(v5.size() == 2);
	srv.remove_medicine("ab");
	assert(repo.size_rep() == 4);
}

void test_validator() {
	Medicine m("", 3.4F, "g", "g");
	Validator<Medicine> val;
	try {
		val.validate(m); assert(false);
	}
	catch (ValidatorException) { assert(true); }
	Medicine m1("", 3.4F, "g", "g");
	try {
		val.validate(m1); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\n"); }
	Medicine m2("s", -9, "g", "g");
	try {
		val.validate(m2); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid price!\n"); }
	Medicine m3("s", 9, "", "g");
	try {
		val.validate(m3); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid manufacturer!\n"); }
	Medicine m4("s", 9, "v", "");
	try {
		val.validate(m4); assert(false);
	}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid substance!\n"); }
}

void test_list() {
	Lista<Medicine> list;
	assert(list.vid() == true);
	Medicine m1 = Medicine("a", 10, "a", "a");
	list.add(m1);
	assert(list.size() == 1);
	Medicine m2 = Medicine("a", 10, "b", "b");
	list.modify(m2);
	Medicine m3 = Medicine("c", 10, "c", "c");
	list.add(m3);
	assert(list.size() == 2);
	Medicine m4 = Medicine("c", 10, "d", "d");
	list.modify(m4);
	list.remove(m2);
	assert(list.size() == 1);
	Medicine m5 = Medicine("aaa", 10, "aaa", "aaa");
	list.add(m5);
	assert(list.vid() == false);
	assert(list.element(1) == m5);
	Medicine m6 = Medicine("bbb", 10, "bbb", "bbb");
	list.add(m6);
	Lista<Medicine> l1 = list;
	l1.sort(cmp_name);
	assert(l1.element(0) == m5);
	assert(l1.element(1) == m6);
	assert(l1.element(2) == m3);
	l1.remove(m6);
	assert(l1.size() == 2);
	Iterator<Medicine> it = list.iterator();
	int k = 0;
	std::cout << it.element();
	while (it.valid()) {
		assert(it.element() == list.element(k));
		k++;
		it.next();
	}
}