#pragma once

#include <iostream>

int InputInt(std::string message, int min, int max);

double InputDouble(std::string message, double min, double max);

std::string InputString(std::string message);

bool InputBool(std::string message);

bool is_filepath_valid(std::string& filepath);

int confirm_overwrite();