#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "UTManager.h";


using namespace std;



void dogFart(string input) {

	regex pat{ R"(^.+$)" };

	regex mapPattern {R"(^.+\.unr$)"};

	smatch matches;

	if (regex_search(input, matches, mapPattern)) {
		cout << "This is a map file" << endl;
	}
}


int main() {


	
	UTManager potato;

	
}