/**
	\file
	\brief :D
	\author SavaLione
*/
#ifndef YENOT_H
#define YENOT_H

#include <opencv2/opencv.hpp>

namespace yenot {
	///////////////////////////////////////////////////////////////////////////////
	//	General
	///////////////////////////////////////////////////////////////////////////////
	const char settings_file_name[] = "./config.ini";
	const char logger_file_name[] = "Yenot.log";
	const char database_file_name[] = "database.xml";
	const char database_name[] = "database";

	const char extensions_database_member[] = ".xml";
	const char extensions_database_member_photo[] = ".png";

	const int buffer_size = 128;

	///////////////////////////////////////////////////////////////////////////////
	//	Core
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_core[] = "Core";
	const char settings_block_default[] = "General";

	const char settings_fastmode[] = "fMode";
	const char settings_fastmode_value[] = "0";
	const int settings_fastmode_value_int = 0;

	const char settings_noiseReduction[] = "nReduction";
	const char settings_noiseReduction_value[] = "1";
	const int settings_noiseReduction_value_int = 1;

	const char settings_machineLearning[] = "mLearning";
	const char settings_machineLearning_value[] = "1";
	const int settings_machineLearning_value_int = 1;

	const char settings_lineDetection[] = "lDetection";
	const char settings_lineDetection_value[] = "1";
	const int settings_lineDetection_value_int = 1;

	const char use_detection[] = "detection";
	const char use_detection_value[] = "1";
	const int use_detection_value_int = 1;

	const char save_processed_image[] = "sImage";
	const char save_processed_image_value[] = "0";
	const int save_processed_image_value_int = 0;
	const char save_processed_image_name[] = "test.png";

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

	const char settings_log[] = "log";
	const char settings_log_value[] = "1";

	const char settings_logTime[] = "lTime";
	const char settings_logTime_value[] = "1";

	const char logger_level_warning[] = "WARN";
	const char logger_level_error[] = "ERROR";
	const char logger_level_message[] = "MSG";

	///////////////////////////////////////////////////////////////////////////////
	//	Log messages
	///////////////////////////////////////////////////////////////////////////////
	const char logger_message_noiseRemoval[] = "Noise filter is disabled.";
	const char logger_message_lDetection[] = "Line detection is disabled.";
	const char logger_message_fMode[] = "Fast mode enabled.";
	const char logger_message_cDir[] = "Folder created.";
	const char logger_message_cDir_not[] = "Folder not created.";

	///////////////////////////////////////////////////////////////////////////////
	//	Car model
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_carModel[] = "carmodel";
	const char settings_carModel_listphoto[] = "listphoto";

	const char settings_carModel_example[] = "example";
	const char settings_carModel_example_description[] = "The car of model \"Example\"";
	const char settings_carModel_example_file[] = "example.xml";

	const char settings_block_description[] = "description";
	const char settings_description_ifnotfound[] = "Not found";
	const char settings_description_example[] = "Example brand";

	const int settings_size_photo = 512;
}

#endif // YENOT_H