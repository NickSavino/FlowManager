// list.h
// ENSF 337 Fall 2021, Lab 8 Exercise C
//By: Nicola Savino

#include "list.h"

#include <iostream>
#include <iomanip>

using namespace std;


FlowList::FlowList(): head(0), size(0) {}


FlowList::~FlowList() {
    destroy();
}

void FlowList::display() {
    
        for (const Node* temp_ptr = head; temp_ptr != 0; temp_ptr = temp_ptr->next) {
        cout << temp_ptr->item.year << setw(10) << temp_ptr->item.flow << endl;
        //cout << temp_ptr->next << endl; //debug statement
        }
    }

void FlowList::insert(int year, double flow) {
    
    //allocates new memory space for node, assigns year and flow to members
    Node* new_node = new Node;
    new_node->item.year = year;
    new_node->item.flow = flow;


    //if head is empty, execute statement
    if (head == 0) {
        new_node->next = head;
        head = new_node;
        head->next = nullptr;
        size += 1;
    }
    //year is less then year in head node, execute statement
    else if (year <= head->item.year) {
        new_node->next = head;
        head = new_node;
        size += 1;
    }
    else {
        Node* tp = head; //traversal pointer
        Node* trail = head;

        while (tp != 0) {
            
            if (year == tp->item.year) {
                cout << "Error: duplicate data entry" << endl;
                return;
            }
            //if year is greater than current node and less then next node. execute statement
            if (trail->item.year < year && (tp->item.year > year)) {
                //insert new node into linked list
                new_node->next = tp;
                trail->next = new_node;
                size += 1;
                return;
            }
        //advance trail and traversal pointer
        trail = tp;   
        tp = tp->next;
       }
        //if traversal pointer reaches null, new node is inserted at end of list
        tp = new_node;
        trail->next = new_node;
        new_node->next = nullptr;
        size += 1;


    }
}

void FlowList::index(int n, int* year, double* flow) {
    Node* tp = head;
    
    for (int i = 0; i<n; i++) {
        tp = tp->next;
    }
    *year = tp->item.year;
    *flow = tp->item.flow;
}

void FlowList::remove(int year) {
    Node* tp = head;
    

    //if list is empty, do nothing
    if (head == 0) {
        return;
    }
    //if head is node to be removed, free from memory and set new head to next node
    if (year == head->item.year) {
        head = tp->next;
        free(tp);
        size -= 1;
        cout << "Record was succesfully removed" << endl;
        return;
    }
    else {
        Node* trail = tp;
        tp = tp->next;
        Node* lead = tp->next;
        //traverse list with tp until it reaches null pointer (tail)
        while (tp != 0) {
            //if traversal pointer is to be removed, free from memory and set trailing node to point to lead node
            if (year == tp->item.year) {
                trail->next = lead;
                free(tp);
                size -= 1;
                cout << "Record was succesfully removed" << endl;
                return;
            }
            //increment all traversal pointers until matching value is found
            trail = tp;
            tp = tp->next;
            if (tp != 0) lead = tp->next;
            
            }
        
    }
    cout << "Error: No such data" << endl;
}

void FlowList::destroy() {
    Node *tp = head;
    Node *lead;

    while (tp != 0) {
        lead = tp->next;
        free(tp);
        tp = lead;
    }
    free(tp);
}

int FlowList::getSize() const {
    return size;
}