#include "Inputs.h"
#include "Files.h"
#include "Utils.h"

#include <iostream>
#include <vector>

using namespace std;

void show_matrix(vector<vector<double>> array, int size, string message) {

	cout << message << endl << endl;

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < array[i].size(); j++) {

			cout << array[i][j] << '\t';

		}

		cout << endl;

	}

}

void show_table(vector<vector<string>>& table, int size, string message) {

	cout << message << endl << endl;

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < table[i].size(); j++) {

			cout << table[i][j] << '\t';

		}

		cout << endl;

	}

}

vector<vector<double>> set_user_input_matrix(){

	int rows = InputInt("Enter number of matrix's rows:", 0, INT_MAX);

	int columns = InputInt("Enter number of matrix's columns:", 0, INT_MAX);

	vector<vector<double>> matrix(rows, vector<double>(columns));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			cout << "Enter matrix[" << i << "][" << j << "]:";

			matrix[i][j] = InputDouble("", DBL_MIN, DBL_MAX);
		}
	}

	return matrix;

}

vector<vector<double>> set_random_input_matrix() {

	int rows = InputInt("Enter number of matrix's rows:", 0, INT_MAX);

	int columns = InputInt("Enter number of matrix's columns:", 0, INT_MAX);

	vector<vector<double>> matrix(rows, vector<double>(columns));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			matrix[i][j] = rand();
		}
	}

	return matrix;

}

void clear_matrix(vector<vector<double>>& matrix) {

	for (int i = 0; i < matrix.size(); i++) {

		matrix[i].clear();
	}

	matrix.clear();
}

vector<vector<double>> import_matrix() {

	string file;

	cout << "1 - Enter the fullpath to the file;" << endl;
	cout << "0 - Enter only the filename (for the root folder);" << endl;

	bool user_choice = InputBool("Choose input type:");

	if (user_choice) { file = get_valid_fullpath(); }
	else { file = get_valid_filename(); }

	return get_matrix_from_file(file);

}