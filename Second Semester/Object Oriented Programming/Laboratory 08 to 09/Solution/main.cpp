#include "Ui.h"
#include "Tests.h"

int main() {
	{
		run_all_tests();
		//std::cout << Medicine::c << std::endl;
		ExceptionRepo repo(0.5);
		Validator val;
		Service serv{ repo,val };
		Ui ui{ serv };
		ui.run();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}