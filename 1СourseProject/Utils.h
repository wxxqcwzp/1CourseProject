#pragma once

#include<iostream>
#include <vector>

using namespace std;

void show_matrix(std::vector<std::vector<double>> array, int size, std::string message);

void show_table(std::vector<std::vector<std::string>>& table, int size, std::string message);

vector<vector<string>> run_sorts(std::vector<std::vector<double>>& array);

vector<vector<double>> set_user_input_matrix();

vector<vector<double>> set_random_input_matrix();

void clear_matrix(vector<vector<double>>& matrix);

vector<vector<double>> import_matrix();

bool is_filepath_valid(string& filepath);

int confirm_overwrite();