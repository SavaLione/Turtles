#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

#include <iostream>

#include "..\core\Yenot.h"
#include "..\core\Core.h"

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

void logger_xy(int x, int y) {
	if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_log)) {
		std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
		char ch_x[1024], ch_y[1024];
		itoa(x, ch_x, 10);
		itoa(y, ch_y, 10);
		fout << ch_x << " " << ch_y << "\n";
 		fout.close();
	}
}

void logger_xy(double x, int y) {
	if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_log)) {
		std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
		char ch_x[1024];

		sprintf(ch_x, "%f", x);

		fout << ch_x << " " << y << "\n";
		fout.close();
	}
}