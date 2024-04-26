#pragma once
#include "ISort.h"

#include <vector>

using namespace std;

class SelectionSort : public ISort {

public:

	void Sort(vector<int>& array, int size) override {

		for (int i = 0; i < size; i++) {

			int min_index = i;

			for (int j = i + 1; j < size - i; j++) {

				this->comparison_counter++;

				if (array[min_index] > array[j]) { min_index = j; }

			}

			if (min_index != i) {

				swap(array[i], array[min_index]);

				this->swap_counter++;

			}

		}
	}




};
