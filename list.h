// list.cpp
// ENSF 337 Fall 2021, Lab 8 Exercise C
//By: Nicola Savino

#ifndef list_h
#define list_h

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList {
    private:
        Node* head;
        int size;

    public:
        FlowList();
        ~FlowList();

        void index(int n, int* year, double* flow);

        void insert(int item, double flow);
        void remove(int year);
        void destroy();
        void display();

        int getSize() const;
};






#endif