#include "Utils.h"
#include "Inputs.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;


bool is_filepath_valid(string& filepath){
	
	if (filepath.size() < 3 ||filepath[-1] != 't' || filepath[-2] != 'x' || filepath[-3] != 't') { return false; }

	ifstream file(filepath);
	if (!file) { return false; }

	error_code ec;
	if (!std::filesystem::is_regular_file(filepath, ec)) { return false; }

	file.close();

	return true;

}

int confirm_overwrite() {

	cout << "1 - Overwrite file;" << endl;
	cout << "2 - Add to file;" << endl;
	cout << "3 - Choose another file;" << endl;

	return InputInt("Choose menu item:", 0, 4);

}