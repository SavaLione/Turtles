/**
	@file
    @brief Описание
	@author SavaLione
	@date 28 Mar 2018
*/

#include "..\core\Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;
using namespace yenot;

int main(int argc, char* argv[]) {
	int i_return = 0;
	Mat src, dst;
	char* imagename = argc == 2 ? argv[1] : "image.png";

	src = imread(imagename, 1);

	settingsInitialization();
	clearning((NAME_DATABASE + std::string("\\") + FILE_NAME_DATABASE), NAME_DATABASE);


	resize(src, dst, Size(settings_size_photo, settings_size_photo));
	if (dst.data) { src = dst.clone(); }

	noiseRemoval(src, dst);
	if (dst.data) { src = dst.clone(); }

	lineDetection(src, dst);
	if (dst.data) { src = dst.clone(); }

	detection(src);

	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_SAVE_PROCESSED_IMAGE, SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT)) {
		imwrite((char*)SETTINGS_SAVE_PROCESSED_IMAGE_NAME, src);
	}
	return i_return;
}