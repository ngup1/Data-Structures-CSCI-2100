#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class SLinkedList {
private:
    node* head;
    node* tail;

public:
    SLinkedList() {
        head = nullptr;
        tail = nullptr;
        //cout << "head and tail nodes are initiated with nullptr" << endl;
    }

    void ListAppend(int elem) {
        node* newNode = new node;
        newNode->data = elem;
        newNode->next = nullptr;

        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void ListPrepend(int elem) {
        node* newNode = new node;
        newNode->data = elem;
        newNode->next = nullptr;

        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void ListDisplay() {
        node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

//Search function
    node* search(int value) { 
        node* current = head; // Initialize current to head
        while (current != nullptr) {
            if (current->data == value) {
                return current;  //iterate through list, return node if value is found
            }
            current = current->next; //move to next node if value is not found
        }
        return nullptr; //return nullptr if value is not found
    }
};
    }

    void InsertAfter(node* curNode, int elem) {
        node* newNode = new node;
        newNode->data = elem;
        newNode->next = nullptr;

        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        } else if (curNode == tail) { 
            tail->next = newNode;
            tail = newNode;
        } else { 
            newNode->next = curNode->next;
            curNode->next = newNode;
        }
    }

//Function to remove the node after the current node
    void RemoveAfter(node* curNode){
        if (curNode == nullptr || curNode->next == nullptr){ //If the current node is null or the next node is null, return that there is no node to remove
            cout << "There is no node to be removed" << endl;
            return;
        }

        node* temp = curNode->next; //Temporary pointer to store the node to be removed
        curNode->next = temp->next; //Update the next pointer of the current node to skip the removed node
        delete temp; //Delete the removed node to free up memory 
    }
};

        if (temp == tail){ //if the removed node was the tail, update the tail pointer
            curNode = tail;

        }
    }
};

int main() {
    SLinkedList numList1;
   
    numList1.ListAppend(30);
    numList1.ListAppend(40);
    numList1.ListPrepend(20);
    numList1.ListPrepend(10);
    numList1.ListPrepend(5);
    numList1.ListPrepend(1);

    numList1.ListDisplay(); 

    node* curNode = numList1.search(20);
    if (curNode != nullptr) {
        numList1.InsertAfter(curNode, 25);
    }

    numList1.ListDisplay();

    node* curNode2 = numList1.search(10);
        if (curNode2 != nullptr) {
        numList1.RemoveAfter(curNode2);
     }

    numList1.ListDisplay(); 

    //SINCE WE ARE ONLY SEARCHING HERE AND ARENT REUSING THE OUTPUT I DIDNT STORE THE OUTPUT IN a VARIABLE AND JUST PRINTED IT DIRECTLY. I KNOW IT MAKES IT MORE EFFICIENT TO STORE IT IN A VARIABLE IF YOU ARE REUSING IT SO YOU DONT HAVE TO RE SEARCH THE LIST EVERY TIME. something like node* findNode = numList1.search(); etc etc etc and then reflect that in the print statement as well (findNode->data). But approach here is just to check the intended values with if statements and print the results!
     if (numList1.search(30) != nullptr) {
        cout << "Node with value 30 found." << endl;
    } else {
        cout << "Value 30 not found in the list." << endl;
    }

    if (numList1.search(50) != nullptr) {
        cout << "Node with value 50 found." << endl;
    } else {
        cout << "Node with value 50 not found in the list." << endl;
    }
    
    if (numList1.search(1) != nullptr) {
        cout << "Node with value 1 found." << endl;
    } else {
        cout << "Node with value 1 not found in the list." << endl;
    }

    if (numList1.search(40) != nullptr) {
        cout << "Node with value 40 found." << endl;
    } else {
        cout << "Node with value 40 not found in the list." << endl;
    }

    SLinkedList emptyList;
    emptyList.ListDisplay();
    if (emptyList.search(10) != nullptr) {
        cout << "Node with value 10 found." << endl;
    } else {
        cout << "Node with value 10 not found in the empty list." << endl;
    }

    return 0;
    }