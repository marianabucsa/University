#include "Ui.h"
#include <stdlib.h>
#include "Tests.h"
#include <crtdbg.h>

int main() {
	// /*
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	Ui* ui = init_ui(srv);
	// */
	//run_tests();
	///*
	run(ui);
	destroy_ui(ui);
	// */
	_CrtDumpMemoryLeaks();
	return 0;
}