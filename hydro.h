// hydro.h
// ENSF 337 Fall 2021, Lab 8 Exercise C
//By: Nicola Savino

#ifndef hydro_h
#define hydro_h

class Hydro {

private:
    

public:
    
    Hydro();
    ~Hydro();
    

    void menu(); //creates menu for user to select program options
    void display(); //displays years and average flow for that year

    void readData(); //reads data from text file
    void saveData(); //writes content from linked list into text file

    void addData(); //adds data into linked list from user prompt
    void removeData(); //prompts user to enter a year to be removed

    void average(); //returns flow average in the given list
    
};

#endif