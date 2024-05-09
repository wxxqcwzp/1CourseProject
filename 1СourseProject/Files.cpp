#include "Utils.h"
#include "Inputs.h"
#include "BubbleSort.h"


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


vector<vector<double>> get_matrix_from_file(string filepath) {

    vector<vector<double>> matrix;

    while (!is_filepath_valid(filepath)) { 
        cout << "Error opening file: " << filepath;
        filepath = InputString("Enter filepath (only txt available): ");
    }

    ifstream input_file(filepath);

    string line;
    while (getline(input_file, line)) {

        if (line.empty()) {

            cerr << "Warning: Skipped empty line." << endl;
            continue;

        }

        stringstream ss(line);
        string token;
        vector<double> row;

        while (getline(ss,token,';'))
        {
            try { row.push_back(stod(token)); }

            catch(const exception& e){ cerr << "Warning: Parsing field: " << e.what() << endl; }

        }

        matrix.push_back(row);

    }
    
    input_file.close();

    for (int i = 0; i < matrix.size() - 1; i++) {

        if (matrix[i].size() != matrix[i + 1].size()) { clear_matrix(matrix); break; }

    }

    return matrix;

}


void save_matrix(vector<vector<double>>& matrix, vector<vector<string>> results, int writing) {

    string filepath;

    while (!is_filepath_valid(filepath)) {
        cout << "Error opening file: " << filepath;
        filepath = InputString("Enter filepath (only txt available): ");
    }

    BubbleSort sorted_matrix;

    if(writing == 1){ ofstream file(filepath, ios::app); }
    else if (writing == 2) { ofstream file(filepath, ios::trunc); }

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            if (j == matrix[i].size() - 1) { file << matrix[i][j] << '\n'; }
            else{ file << matrix[i][j] << ';'; }

        }

    }

    sorted_matrix.Sort(matrix, matrix.size());

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            if (j == matrix[i].size() - 1) { file << matrix[i][j] << '\n'; }
            else { file << matrix[i][j] << ';'; }

        }

    }



}



