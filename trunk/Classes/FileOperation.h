#ifndef __FILE_LOADER_H__
#define __FILE_LOADER_H__

#include "cocos2d.h"

USING_NS_CC;

class FileOperation
{
private:
	//file content
	std::string _FileContent;
	//result subtracted string
	std::string _SubString;
	std::string _FilePath;
public:
	~FileOperation(){  }
	//Constructor
	FileOperation(std::string filepath);
	//iss content string
	std::istringstream iss;
	//get detail in file
	std::string getDetail();
	void saveFile(std::string content);
	void saveFile(std::string content, std::string filepath);
};


#endif
