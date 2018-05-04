/**
	@file
	@brief Удобное добавление trainhaar.xml файлов
	@author SavaLione
	@date 25 Apr 2018
*/
/**
	@defgroup yenotdatabasecpp YenotDatabase.cpp
	@ingroup database
	@{
*/
#include "..\Yenot.h"
#include "..\Core.h"
#include "..\Logger.h"

using namespace std;
using namespace yenot;

int main(int argc, char* argv[]) {
	int i_return = 0;

	try {
		if ((strcmp(argv[1], "-add") == 0) && (argc > 1)) {
			databaseAdd(argv[2]);
		} else {
			throw ERROR_DATABASE_ADD_ARGUMENTS;
		}
	} catch (string& e) {
		cerr << e;
		logger((char*)LOGGER_LEVEL_WARNING, (char*)e.c_str());
		i_return = ERROR_DATABASE;
	}

	return i_return;
}
/** @} */