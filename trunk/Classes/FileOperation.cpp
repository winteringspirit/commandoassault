#include "FileOperation.h"
#include <fstream>

FileOperation::FileOperation(std::string filepath)
{
	_FilePath = filepath;

	// Get string from file
	_FileContent = CCFileUtils::sharedFileUtils()->getStringFromFile(filepath);

	//put in iss for substring
	// iss = std::istringstream(_FileContent);
}

std::string FileOperation::getDetail()
{
	//if iss != null then do somthing
	if (iss)
	{
		//declare sub variable for getting result from subtracting string
		iss >> _SubString;
		//subtracting string
		return _SubString;
	}
}

void FileOperation::saveFile(std::string content)
{
	this->saveFile(content, _FilePath);
}

void FileOperation::saveFile(std::string content, std::string filepath)
{
	std::ifstream my_file(filepath);
	if (!my_file)
	{
		std::ofstream file(filepath);
		if (!file)
		{
			return;
		}
	}
	FILE *fp = fopen(filepath.c_str(), "w");
	fputs(content.c_str(), fp);
	fclose(fp);
}
