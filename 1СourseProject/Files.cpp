#include "Utils.h"
#include "Inputs.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

bool is_filepath_valid(string filepath) {

    regex filepath_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.txt$");

    if (!regex_match(filepath, filepath_regex)) {
        cerr << "Error: Invalid file path." << endl;
        return false;
    }

    return true;
}

bool is_filename_valid(string filename) {

    regex filename_regex("^[^\\/:*?\"<>|]+\\.txt");

    if (!regex_match(filename, filename_regex)) {
        cerr << "Error: Invalid file name." << endl;
        return false;
    }

    return true;
}

string get_valid_fullpath() {

    string fullpath;

    while (true) {
        fullpath = InputString("Input fullpath to file (only txt acceptable): ");

        if (is_filepath_valid(fullpath)) {
            return fullpath;
        }
    }
}

string get_valid_filename() {

    string filename;

    while (true) {
        filename = InputString("Input filename (only txt acceptable): ");

        if (is_filename_valid(filename)) {
            return filename;
        }
    }

}

vector<vector<double>> get_matrix_from_file(string filename) {

    vector<vector<double>> matrix;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return matrix;
    }

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