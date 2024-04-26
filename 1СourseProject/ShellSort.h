#pragma once

#include "ISort.h"

#include <vector>

using namespace std;

class ShellSort : public ISort {

public:

	void Sort(vector<int>& array, int size) override {

		for (int gap = size / 2; gap > 0; gap /= 2) {

			for (int i = gap; i < size; i++) {

				for (int j = i; j > 0; j--) {

					this -> comparison_counter++;

					if (array[j - 1] > array[j]) {

						swap(array[j - 1], array[j]);

						this -> swap_counter++;

					}

				}

			}
		}

	}

};