// hydro.cpp
// ENSF 337 Fall 2021, Lab 8 Exercise C
//By: Nicola Savino


#include <fstream>
#include <iostream>
#include <iomanip>

#include "hydro.h"
#include "list.h"

using namespace std;

FlowList flowlist;

Hydro::Hydro() {
    
}

Hydro::~Hydro() {

}

void PressEnter() {
    cout << "\n<<< Press Enter to Continue>>>>\n";

    cin.get();
    
}

void Hydro::menu() {
    PressEnter();
    const char menu_text[] =  "Please select on the following operations\n"
                            "   1. Display flow list, and the average\n"
                            "   2. Add data\n"
                            "   3. Save data into the file\n"
                            "   4. Remove data\n"
                            "   5. Quit\n"
                            "Enter your choice (1, 2, 3, 4, or 5)";
    
    cout << menu_text << endl;
    bool valid = false;
    do {
        //take selection, ignore \n character
        int selection;
        cin >> selection;
        cin.ignore();

        switch (selection) {
            case 1:
                display();
                average();
                valid = true;
                break;
            case 2:
                addData();
                cin.clear();
                cin.ignore();
                valid = true;
                break;
            case 3:
                saveData();
                valid = true;
                break;
            case 4:
                removeData();
                cin.clear();
                cin.ignore();
                valid = true;
                break;
            case 5:
                cout << "Program terminated successfully";
                valid = true;
                exit(1);
            default:
                cout << "Bad Input, Please Retry" << endl;
                cin.clear();
                cin.ignore();
                break;
        }
    } while (valid == false);
    
    menu();
}

void Hydro::display() {
    cout << "Year" << setw(10) << "Flow" << endl;
    cout << "----" << setw(10) << "-----" << endl;
    flowlist.display();
}

void Hydro::readData() {
    
    //validate and open input file
    ifstream inObj;
    inObj.open("flow.txt");
    if(! inObj) {
        cout << "Error: cannot open the file" << "flow.txt" << endl;
        exit(1);
    }

    //read year and flow respectively from file, inserting into linked list.
    int a = 0;
    double b = 0;
    while (inObj >> a >> b) {
        flowlist.insert(a, b);
    }
    inObj.close();
}

void Hydro::saveData() {
    
    ofstream outObj;
    outObj.open("ordered_flow.txt");

    if(! outObj) {
        cout << "Error: cannot open the file" << "ordered_flow.txt" << endl;
        exit(1);
    }

    int year;
    double flow;
    int size = flowlist.getSize();
    
    for (int i = 0; i < flowlist.getSize(); i++) {
        flowlist.index(i, &year, &flow);
        outObj << setw(4) << year << setw(6) << "" << setw(5) << flow << endl;   
    }

    outObj.close();
    cout << "Data was successfully saved into the file";

}

void Hydro::addData() {
    
    int new_year;
    double new_flow;

    cout << "Please enter a year: ";
    cin >> new_year;
    cout << "Please enter the flow: ";
    cin >> new_flow;


    int size = flowlist.getSize();
    flowlist.insert(new_year, new_flow);
    //if list is larger, insertion was successful
    if (size < flowlist.getSize())
        cout << "New record inserted successfully";
}

void Hydro::removeData() {
    int year;
    cout << "Please enter the year that you want to remove: ";
    cin >> year;
    flowlist.remove(year);
}

void Hydro::average() {
    double flow;
    double flow_sum;
    int year;
    int size = flowlist.getSize();
    double avg;
    //iterates through linked lists and adds value of flow at index to sum
    for (int i = 0; i<size; i++) {
        flowlist.index(i, &year, &flow);
        flow_sum += flow;
    }

    avg = flow_sum/size;
    cout << "The annual average of the flow is: " << avg << " billions of cubic meters" << endl;

}

