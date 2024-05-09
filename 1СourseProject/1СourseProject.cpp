#include "ISort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "Utils.h"
#include "Show_menu.h"
#include "Files.h"
#include "Inputs.h"


#include <iostream>
#include <vector>

using namespace std;

enum menu { USER_INPUT = 1, RANDOM_INPUT, FILE_INPUT, EXIT };
int main()
{
    srand(time(0));
    
    show_greeting();

    vector<vector<double>> matrix;

    vector<vector<string>> results;
    
    int user_choice = 0;

    bool repeat = true;
    /*do {

        show_menu();

        user_choice = InputInt("Enter menu item", 0, 5);

        switch (user_choice)
        {
        case(USER_INPUT) : {

            matrix = set_user_input_matrix();
            results = run_sorts(matrix);
            break;

        }
        case(RANDOM_INPUT): {

            matrix = set_random_input_matrix();
            results = run_sorts(matrix);
            break;

        }

        case(FILE_INPUT): {

            matrix = import_matrix();
            results = run_sorts(matrix);
            break;

        }

        case(EXIT): { repeat = false; }
        }

    } while (repeat);*/
    

}
