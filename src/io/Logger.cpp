#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

#include "..\core\Yenot.h"
#include "Settings.h"


void log(std::string message) {
	if (1) {
		std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
		fout << "[i]" << message << std::endl;
		fout.close();
	}
}