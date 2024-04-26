#pragma once
#include "ISort.h"

#include <vector>

using namespace std;

class BubbleSort :public ISort {

private:

	vector<int> array;

public:

	void Sort(vector<int>& array, int size) override {

		for (int i = 0; i < size - 1; i++) {

			for (int j = 0; j < size - i - 1; j++) {

				this -> comparison_counter++;

				if (array[j] > array[j + 1]) { swap(array[j], array[j + 1]); this -> swap_counter++; }

			}

		}

	}




};
