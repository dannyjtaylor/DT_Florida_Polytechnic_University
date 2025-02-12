int isEmpty();
int sizeList();
void push(int data);
int peek();
int pop();
void printList();
int get(int position);
void removeElement(int position);
void insertLast(int inserted);
void reverseList();

#include <iostream>
using namespace std;

// Declare linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
};


//initialization for top and tail pointers
Node* top = nullptr;
Node* tail = nullptr;

// Utility function to add an element at the top (push)
void push(int data) {
    Node* temp = new Node();
    if (!temp) {
        cout << "\ncannot be allocated";
        exit(1);
    }
    temp->data = data;

    // if list is empty (top returns nullptr), then
    if(isEmpty()) {
        temp->next = nullptr;
        temp->prev = nullptr;
        top = temp;
        tail = temp;
    }

    else {
        temp->next = top;
        temp->prev = nullptr;
        top->prev = temp;
        top = temp;
    }
}

// Utility function to check if the stack (list) is empty
int isEmpty() {
    return top == nullptr;
}

// Utility function to return the top element
int peek() {
    if (!isEmpty()) {
        return top->data;
    }
    else {
        exit(1);
    }
}

// Utility function to pop the top element
int pop() {
    Node* temp;
    int x;
    if (top == nullptr) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } 
    else {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }

    return x;
}

// Function to print the list (stack)
void printList() {
    Node* temp;
    cout << "NULL <->";
    if (top == nullptr) {
        cout << "\nStack Underflow";
        exit(1);
    } 

    else {
        temp = top;
        while (temp != nullptr) {
            cout << " " << temp->data << " <->";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }
}

// Function to get the element at a specific position
int get(int position) {
    int sizeOfList = sizeList();
    if (sizeOfList/2 <= position) {
        Node*temp = tail;
        int i = sizeOfList-1;
        while(temp!= nullptr) {
            if (i== position) {
                return temp->data;
            }
            i--;
            temp = temp->prev;
        }
        cout << "\nReached NULL" << endl;
        return -1;
    }
    else {
        Node*temp = top;
        int i = 0;
        while (temp!= nullptr) {
            if (i == position) {
                return temp->data;
            }
            i++;
            temp = temp->next;
        }
        cout << "\nReached NULL" << endl;
        return -1;
    }
}

// Function to remove an element from a specific position
    void removeElement(int position) {
    int size = sizeList();

    if (top == NULL) {
        cout << "\nStack Underflow";
        return;
    }

    Node* temp;

    if (position == 0) {
        temp = top;
        top = temp->next;
        free(temp);
        if(top == NULL)
            tail = NULL;
        else
            top->prev = NULL;
    }
    else if(position > 0 && position < size/2)
    {
        temp = top;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL  || temp->next == NULL) {
            cout << "\nPosition out of range!" << endl;
            return;
        }
        Node* next = temp->next->next;
        if(next != NULL)
            next->prev = temp;
        else
            tail = temp;
        free(temp->next);
        temp->next = next;
    }
    else if(position > 0)
    {
        temp = tail;
        for (int i = size - 1; temp != NULL && i > position + 1; i--) {
            temp = temp->prev;
        }

        if (temp == NULL || temp->prev == NULL) {
            cout << "\nPosition out of range!" << endl;
            return;
        }
        Node* prev = temp->prev->prev;
        if(prev != NULL)
            prev->next = temp;
        else
            top = temp;
        free(temp->prev);
        temp->prev = prev;
    }
}




    /*
    int size = sizeList();
    if (top == nullptr) {
        cout << "\nStack Underflow";
        return;
    }
    Node* temp;
    if (position == 0) {
        temp = top;
        top = temp->next;
        // if there is a new top, set its prev to null pointer
        if (top != nullptr) {
            top->prev = nullptr;
        } else {
            tail = nullptr; // set tail to null pointer if list is empty
        }
        free(temp);
        return;
    }
    else if (position == size - 1) {
        temp = tail;
        tail = temp->prev;
        if (tail != nullptr) {
            //set the new tail's next to nullptr
            tail->next = nullptr;
        } else {
            //if the list is empty, set top to nullptr
            top = nullptr;
        }
        free(temp);
        return;
    }
    // find node to remove
    if((size/2) <= position) {
        temp = tail; // start from tail if size/2 is less than or equal to the position
        for (int i = size - 1; temp != nullptr && i > position; i--) {
            temp = temp->prev;
        }
    }
    else {
        temp = top; // start from top for smaller index
        for (int i = 0; temp != nullptr && i < position; i++) {
            temp = temp->next;
        }
    }
    if (temp == nullptr) {
        cout << "\nPosition out of range!" << endl;
        return;
    }
    //link the previous node to the next node of the node to be removed
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}*/


// Function to insert an element at the end
void insertLast(int inserted) {
    Node* temp = new Node();
    temp->data = inserted;
    temp->next = nullptr;
    if (top == nullptr) {
        temp->prev = nullptr;
        top = tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

//function to return the size of the list
int sizeList() {
    int count = 0;
    Node* temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList(){
    Node*temp = top;
    top = tail;
    tail = temp;
    while(temp!= NULL) {
        Node*currentNode = temp->next;
        temp->next = temp->prev;
        temp->prev = currentNode;
        temp = currentNode;
    }
}
/*
    Node* temp = nullptr;
    Node* currentNode = top;
    while(currentNode != nullptr) {
        temp = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = temp;
        currentNode = currentNode->prev;
    }
    if (temp != nullptr) {
        tail = top;
        top = temp->prev;
    }
}*/

int main() {

    // Push the elements to stack (list)
    push(34);
    push(12);
    push(85);
    push(78);
    push(11);
    push(81);
    push(19);
    push(913);
    push(69);
    //display doubly linked list
    
    printList();

    //use peek to see element at top of the list
    cout << endl << peek() << " is at the top of the list" << endl;

    //print the size of the list
    cout << "\nSize of the list: " << sizeList() << endl;

    //use pop to delete three elements from stack and display it. Deletes from top FILO style
    pop();
    pop();
    pop();
    cout << "\nList after popping 3 times:" << endl;
    printList();

    //use get to find 2nd and 1st element
    cout << "\nSecond element is: " << get(1) << endl;
    cout << "First element is: " << get(0) << endl;

    //remove first element and print accordingly
    removeElement(0);
    removeElement(1);
    cout << "\nList after removing first element:" << endl;
    printList();

    //insert element at the end, and print accordingly
    insertLast(3);
    cout << "\nList after inserting 3 at the end:\n";
    printList();

    //print the size of the list
    cout << "Size of the list: " << sizeList() << endl;

    //reverse list and print accordingly
    cout << "\nList before reversing:" << endl;
    printList();
    reverseList();
    cout << "\nList after reversing: " << endl;
    printList();

    return 0;
}