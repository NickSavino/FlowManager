#include <iostream>
#include <iomanip>

#include "hydro.h"
#include "list.h"

using namespace std;


void displayHeader() {
    const char welcome[] =  "Program: Flow Studies, Fall 2022\n"
                            "Version 1.0\n"
                            "Lab section: B01\n"
                            "Produced by: Nicola Savino";
    cout << welcome;
}

int main() {
    
    Hydro program;
    displayHeader();
    program.readData();
    program.menu();

}

