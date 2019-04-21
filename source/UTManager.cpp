#include "UTManager.h"



UTManager::UTManager(){


	//this->cunt = vector<int>;
	//cout << "there is a total of " << this->_totalFiles << " files to process \n";

	cout << "NEW UTMANAGE";

	this->readCacheIni();
	this->sortFiles();

	this->convertFiles();
	//this->moveFile("9013DABB4E8670FB3F3EB2863A406640=CTF-[4]-(EoW)Kanjar.unr","System/");
}

void UTManager::convertFiles() {

	for (int i = 0; i < size(this->_mapFiles); i++) {
		this->moveFile(this->_mapFiles[i],"Maps/");
	}

	for (int i = 0; i < size(this->_musicFiles); i++) {
		this->moveFile(this->_musicFiles[i], "Music/");
	}

	for (int i = 0; i < size(this->_soundFiles); i++) {
		this->moveFile(this->_soundFiles[i], "Sounds/");
	}

	for (int i = 0; i < size(this->_textureFiles); i++) {
		this->moveFile(this->_textureFiles[i], "Textures/");
	}

	for (int i = 0; i < size(this->_otherFiles); i++) {
		this->moveFile(this->_otherFiles[i], "System/");
	}
}

void UTManager::updateFileList(string line, int type) {

	if (type == 0) {
		this->_mapFiles.push_back(line);
	}
	else if (type == 1) {
		this->_musicFiles.push_back(line);
	}
	else if (type == 2) {
		this->_soundFiles.push_back(line);
	}
	else if (type == 3) {
		this->_textureFiles.push_back(line);
	}
	else if (type == 4) {
		this->_otherFiles.push_back(line);
	}
}

void UTManager::sortFiles() {

	regex mapPat{ R"(^.+\.unr$)" };
	regex musicPat{ R"(^.+\.umx$)" };
	regex soundPat{ R"(^.+\.uax$)" };
	regex texturePat{ R"(^.+\.utx$)" };
	regex otherPat{R"(^.+\..+$)"};

	smatch matches;
	string currentFile;

	for (int i = 0; i < size(this->_allFiles); i++) {
		
		//currentFile = this->_allFiles[i];
		if (regex_search(this->_allFiles[i], matches, mapPat)) {
			this->updateFileList(this->_allFiles[i],0);
		}
		else if (regex_search(this->_allFiles[i], matches, musicPat)) {
			this->updateFileList(this->_allFiles[i],1);
		}
		else if (regex_search(this->_allFiles[i], matches, soundPat)) {
			this->updateFileList(this->_allFiles[i], 2);
		}
		else if (regex_search(this->_allFiles[i], matches, texturePat)) {
			this->updateFileList(this->_allFiles[i], 3);
		}
		else if (regex_search(this->_allFiles[i], matches, otherPat)) {
			this->updateFileList(this->_allFiles[i], 4);
		}
	}
}

bool UTManager::moveFile(string fileName, string dir) {

	string test = "System/";
	string currentFileName = "penis";

	string horse = test + currentFileName;

	regex splitPat{R"(^(.+?)=(.+)(\..+)$)"};

	smatch matches;

	int uxxFileLength = 0;
	int outputFileNameLength = 0;
	int outputFileExtLength = 0;
	int outputFileFullLength = 0;

	if (regex_search(fileName, matches, splitPat)) {


		//uxxFileLength = matches[1].length();
		////outputFileNameLength = matches[2].length();
		//outputFileExtLength = matches[3].length() + 1;

		outputFileFullLength = outputFileNameLength + outputFileExtLength;

		for (int i = 0; i < size(matches); i++) {
			cout << fileName << "matches[" << i << "] = " << matches[i] << endl;
			
		}

		char uxxFile[255] = "";
		char outputFile[255] = "";



		string uxx = "Cache/";
		uxx += matches[1];
		uxx += ".uxx";
		int uxxOffset = 0;
		string file = dir;
		file += matches[2];
		file += matches[3];
		int fileOffset = 0;

		//for (int a = 0; a < uxx.length; a++) {
			//uxxFile[a] = uxx[a];
		//}

		for (char& c : uxx) {
			uxxFile[uxxOffset] = c;
			uxxOffset++;
		}

		for (char& c : file) {
			outputFile[fileOffset] = c;
			fileOffset++;
		}

		//uxxFile[uxxOffset] = ".";
		//uxxFile[uxxOffset+1] = "u";
		//uxxFile[uxxOffset+2] = "x";
		//uxxFile[uxxOffset+3] = "x";

		cout << "uxxFile = " << uxxFile << endl;
		cout << "outputFile = " << outputFile << endl;

		if (rename(uxxFile, outputFile)) {
			cout << "fileMoved\n";
		}
		else {
			cout << "failed to move file";
		}
	}

	//if (rename("dogpoo.txt", horse)) {
	//	return true;
	//}


	return false;
}

void UTManager::readCacheIni() {

	fstream ini;
	ini.open(this->_cacheIni, ios::in);

	string line;


	int currentFile = 0;
	int totalFiles = 0;

	if (ini.is_open()) {
		cout << "FOUND FILE";

		while (getline(ini, line)) {
			currentFile++;

			if (currentFile > 1) {
				this->_allFiles.push_back(line);
			}
			cout << line << endl;
		}
	}
	else {
		cout << "didnt find file";
	}


}

UTManager::~UTManager()
{
}
