#pragma once

#include "ISort.h"

#include <vector>

using namespace std;

class InsertionSort : public ISort {

public:

	void Sort(vector<int>& array, int size) override {
	
	
		for (int i = 1; i < size; i++) {

			for (int j = i; j > 0; j--) {

				this -> comparison_counter++;

				if (array[j - 1] > array[j]) {

					this -> swap_counter;

					swap(array[j - 1], array[j]);

				}

			}

		}
	
	}






};
