#include "Inputs.h"
#include "Files.h"
#include "Utils.h"

#include <iostream>
#include <vector>

using namespace std;

enum save { OVERWRITE = 1, ADD, ANOTHER };

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

			matrix[i][j] = InputDouble("", -DBL_MAX, DBL_MAX);
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

void save_results(vector<vector<string>> results) {

	switch (confirm_overwrite()) {

	case(OVERWRITE): {




		return;

	}
	case(ADD): {//func

		return;
	}
	case(ANOTHER): { return; }

	}

}