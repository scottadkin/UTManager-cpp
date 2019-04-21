#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <stdio.h>

using namespace std;

class UTManager
{
public:
	UTManager();
	void readCacheIni();
	~UTManager();
	void sortFiles();
	void updateFileList(string line, int type);
	bool moveFile(string fileName, string dir);
	void convertFiles();

private:
	int _totalFiles = 0;
	string _cacheIni = "Cache/cache.ini";
	vector<string> _musicFiles;
	vector<string> _mapFiles;
	vector<string> _textureFiles;
	vector<string> _soundFiles;
	vector<string> _otherFiles;
	vector<string> _allFiles;
};

