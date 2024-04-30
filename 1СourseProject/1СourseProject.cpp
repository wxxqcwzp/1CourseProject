#include "ISort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "Utils.h"
#include "Show_menu.h"
#include "Files.h"


#include <iostream>
#include <vector>

using namespace std;


int main()
{
    srand(time(0));
    
    show_greeting();

    vector<vector<double>> test = get_matrix_from_file("test1.txt");

    run_sorts(test);

    vector<vector<double>> array = { 
        { -5, 4, 3, 7, 1 },
        { 6, 5, -4, 3, 2 },
        { 7, -6, 5, 4, 3 }
    };

    run_sorts(array);

    array = set_random_input_matrix();

    run_sorts(array);
    
    
    
    

}
