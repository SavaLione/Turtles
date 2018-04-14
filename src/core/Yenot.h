/**
	\file
	\brief Заголовочный файл с ОПИСАНИЕ___.
	\author SavaLione
*/
#ifndef YENOT_H
#define YENOT_H

namespace yenot {
	const char settings_file_name[] = "./config.ini";
	const char logger_file_name[] = "Yenot.log";

	const int i_return = -1;
	const bool b_return = true;
	const char ch_default_block[] = "General";

	const char settings_logger[] = "log";

	const char ch_default_value[] = "Default";

	const int buffer_size = 128;

	///////////////////////////////////////////////////////////////////////////////
	//	Core
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_core[] = "Core";

	const char settings_value_fastmode[] = "fastmode";
	//const int settings_value_fastmode_Value

	const char settings_value_noiseReduction[] = "noiseReduction";

	const char settings_value_machineLearning[] = "machineLearning";

	///////////////////////////////////////////////////////////////////////////////
	//	Filters
	///////////////////////////////////////////////////////////////////////////////
	const int diameter_each_pixel = 9;
	const int sigmaColor = 75;
	const int sigmaSpace = 75;

	const int gaussianblur_kernel_x = 5; //odd
	const int gaussianblur_kernel_y = 5; //odd

	const int blur_kernel_x = 5; //odd
	const int blur_kernel_y = 5; //odd

	///////////////////////////////////////////////////////////////////////////////
	//	Logger
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_logger[] = "Logger";
	const char settings_value_log[] = "log";
	const char settings_value_logTime[] = "logTime";
}

#endif // YENOT_H