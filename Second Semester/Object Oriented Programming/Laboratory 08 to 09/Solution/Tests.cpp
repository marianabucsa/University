#include "Tests.h"
#include <assert.h>
#include <string>

void run_all_tests() {
	std::cout << "Running tests ...\n";
	test_domain();
	test_repository();
	test_service();
	test_validator();
	test_filerepo();
	test_undo();
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
	assert(m != m2);
	Medicine f;
	std::cout << f;

}

void test_repository() {
	Repository repo;
	Medicine m("paracetamol", 3.5, "pfizer", "paracetamol");
	repo.add(m);
	repo.find(m);
	assert(repo.size_rep() == 1);
	Medicine m1("algocalmin", 3.5, "pfizer", "paracetamol");
	try {
		const int poz = repo.find(m1); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	try {
		repo.modify(m1); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	try {
		repo.remove(m1); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }

	Medicine m2("paracetamol", 4.5, "pf", "paracetamol");

	try {
		repo.add(m2); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine already exists!\n"); }

	repo.modify(m2);
	repo.add(m1);
	assert(repo.size_rep() == 2);
	std::vector<Medicine> v = repo.get_all();
	assert(v.at(0) == m2);
	assert(v.at(1) == m1);
	repo.remove(m2);
	assert(repo.size_rep() == 1);
	try {
		const int poz = repo.find(m2); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "Medicine doesn't exist!\n"); }
}

void test_service() {
	Repository repo;
	Validator val;
	Service srv{ repo, val };

	try {
		srv.random_prescription(4); assert(false);}
	catch (RepositoryException e) { assert(e.get_message() == "There is no medicine to add!\n"); }

	srv.add_medicine("s", 2, "h", "l");
	assert(repo.size_rep() == 1);
	try {
		srv.add_medicine("", 3.4F, "f", "f"); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\n"); }
	try {
		srv.modify_medicine("", -8, "t", "t"); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\nInvalid price!\n"); }
	try {
		srv.add_medicine("", -3, "", ""); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\nInvalid price!\nInvalid manufacturer!\nInvalid substance!\n"); }
	srv.modify_medicine("s",4.5, "h", "l");
	srv.add_medicine("ab", 5, "ggg", "p");
	Medicine m("s", 4.5, "h", "l");
	assert(m == srv.get_all_medicine().at(0));
	srv.add_medicine("a", 6, "v", "b");
	srv.add_medicine("b", 1, "n", "j");
	srv.add_medicine("c", 3, "k", "j");
	assert(repo.size_rep() == 5);
	std::vector<Medicine> v = srv.sort_by_name();
	assert(v.at(0) == srv.get_all_medicine().at(2));
	assert(v.at(1) == srv.get_all_medicine().at(1));
	assert(v.at(2) == srv.get_all_medicine().at(3));
	assert(v.at(3) == srv.get_all_medicine().at(4));
	assert(v.at(4) == srv.get_all_medicine().at(0));
	std::vector<Medicine> v1 = srv.sort_by_manufacturer();
	assert(v1.at(0) == srv.get_all_medicine().at(1));
	assert(v1.at(1) == srv.get_all_medicine().at(0));
	assert(v1.at(2) == srv.get_all_medicine().at(4));
	assert(v1.at(3) == srv.get_all_medicine().at(3));
	assert(v1.at(4) == srv.get_all_medicine().at(2));
	std::vector<Medicine> v2 = srv.sort_by_substance_price();
	assert(v2.at(0) == srv.get_all_medicine().at(2));
	assert(v2.at(1) == srv.get_all_medicine().at(3));
	assert(v2.at(2) == srv.get_all_medicine().at(4));
	assert(v2.at(3) == srv.get_all_medicine().at(0));
	assert(v2.at(4) == srv.get_all_medicine().at(1));

	std::vector<Medicine> v3 = srv.filter_medicine_price_lower(5);
	assert(v3.size() == 4);
	std::vector<Medicine> v4 = srv.filter_medicine_price_gratter(5);
	assert(v4.size() == 2);
	std::vector<Medicine> v5 = srv.filter_medicine_substance("j");
	assert(v5.size() == 2);

	std::map<std::string, int> mapp = srv.get_map();

	int k = srv.add_prescription("a");
	std::vector<Medicine> p = srv.get_prescription();
	assert(k == 1);
	k = srv.random_prescription(4);
	assert(k == 5);
	srv.empty_prescription();

	try {
		srv.export_prescription("testExport.html");assert(false);}
	catch(RepositoryException e) { assert(e.get_message() == ("The prescription doesn't have any medicine to export!\n")); }

	assert(srv.get_prescription().size() == 0);
	k=srv.random_prescription(10);
	assert(srv.get_prescription().size() == 10);

	srv.export_prescription("testExport.html");
	std::ifstream in("testExportHTML");
	in.open("testExportHTML");

	try {
		srv.export_prescription("m/n/export.html"); assert(false);}
	catch (const FileException& e) { assert(e.get_message() == "Could not open file m/n/export.html"); };

	srv.remove_medicine("ab");
	assert(repo.size_rep() == 4);
}

void test_validator() {
	Medicine m("", 3.4F, "g", "g");
	Validator val;
	try {
		val.validate(m); assert(false);}
	catch (ValidatorException) { assert(true); }
	Medicine m1("", 3.4F, "g", "g");
	try {
		val.validate(m1); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid name!\n"); }
	Medicine m2("s", -9, "g", "g");
	try {
		val.validate(m2); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid price!\n"); }
	Medicine m3("s", 9, "", "g");
	try {
		val.validate(m3); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid manufacturer!\n"); }
	Medicine m4("s", 9, "v", "");
	try {
		val.validate(m4); assert(false);}
	catch (ValidatorException e) { assert(e.get_message() == "Invalid substance!\n"); }
}

void test_filerepo() {
	try {
		FileRepository frepo{ "testopen.txt" }; assert(false);}
	catch (const FileException& e) { assert(e.get_message() == "Error opening testopen.txt"); };
	FileRepository frepo{ "test.txt" };
	frepo.add(Medicine{ "as",432,"fdads sfd","sds" });
	std::vector<Medicine> medicine = frepo.get_all();
	assert(medicine.at(0).get_name() == "dd dd");
	assert(medicine.at(1).get_name() == "as");
	assert(frepo.size_rep() == 2);
	try {
		int i;
		i = frepo.find(Medicine("ds", 54,"fwe", "fds")); assert(false);}
	catch (const RepositoryException&) { assert(true); };
	auto i = frepo.find(Medicine{ "as",432,"fdads sfd","sfd"});
	assert(i == 1);
	frepo.modify(Medicine{ "as",432,"sfd","sfd" });
	std::vector<Medicine> v = frepo.get_all();
	assert(v.size() == 2);
	frepo.remove(Medicine{ "as",432,"sfd","sfd" });
	assert(frepo.size_rep() == 1);
}

void test_undo() {
	FileRepository frepo{ "test.txt" };
	Validator valid;
	Service srv{ frepo,valid };
	try {
		srv.undo_action(); assert(false);}
	catch (const UndoException& e) { assert(e.get_message() == "Undo action cannot be done!\n"); };

	srv.add_medicine("ds", 345, "fe", "fsdf");
	srv.add_medicine("dsfd", 978, "frte", "df");
	srv.modify_medicine("ds", 4383, "few", "fer");
	std::vector<Medicine> v = srv.get_all_medicine();
	assert(v.at(frepo.find(Medicine("ds", 4383, "few", "fer"))).get_price() == 4383);
	srv.undo_action();
	v = srv.get_all_medicine();
	assert(v.at(frepo.find(Medicine("ds", 4383, "few", "fer"))).get_price() == 345);
	assert(frepo.size_rep() == 3);
	srv.remove_medicine("dsfd");
	assert(frepo.size_rep() == 2);
	srv.undo_action();
	assert(frepo.size_rep() == 3);
	srv.undo_action();
	assert(frepo.size_rep() == 2);
	srv.remove_medicine("ds");
}
