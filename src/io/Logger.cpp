#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

#include "..\core\Yenot.h"
#include "Settings.h"

void logger(char *level, char *text) {
	if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_log)) {
		if (!check_file((char*)yenot::logger_file_name)) {
			std::ofstream fout(yenot::logger_file_name);
			fout.close();
		}
		if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_logTime)) {
			std::string year = "", month = "", day = "", hour = "", minute = "", second;
			SYSTEMTIME time;
			GetLocalTime(&time);

			if (time.wYear < 10) { year = "0"; }
			if (time.wMonth < 10) { month = "0"; }
			if (time.wDay < 10) { day = "0"; }
			if (time.wHour < 10) { hour = "0"; }
			if (time.wMinute < 10) { minute = "0"; }
			if (time.wSecond < 10) { second = "0"; }

			std::ofstream fout(yenot::logger_file_name, std::ios_base::app);

			fout
				<< "["
				<< year << time.wYear << "/"
				<< month << time.wMonth << "/"
				<< day << time.wDay << " "
				<< hour << time.wHour << ":"
				<< minute << time.wMinute << ":"
				<< second << time.wSecond << "] "
				<< "[" << level << "]" << text
				<< "\n";
			fout.close();
		} else {
			std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
			fout
				<< "[" << level << "]" << text << "\n";
			fout.close();
		}
	}
}