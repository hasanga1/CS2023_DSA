#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

class Stack {
public:
    int size;
    int current = 0;
    int arr[];
    explicit Stack(int size) {
        this->size = size;
        arr[size];
    }
    bool isFull() {
        return current >= size;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[current] = data;
        current++;
    }
    bool isEmpty() {
        if (current == 0) {
            return true;
        }
        else
            return false;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return NULL;
        }
        current--;
        return arr[current];
    }
    void display() {
        for (int i = current - 1; i > -1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int stackTop() {
        return arr[current - 1];
    }
};

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
    }
};

class StackLinked {
public:
    int size, current = 0;
    Node* top;
    explicit StackLinked(int size) {
        this->size = size;
        top = nullptr;
    }
    bool isFull() {
        return current >= size;
    }
    bool isEmpty() {
        return current == 0;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        current++;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return NULL;
        }
        top = top->next;
        int popData = top->data;
        current--;
        return popData;
    }
    int display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int stackTop() {
        return top->data;
    }
};

int main() {
    int size;
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter the size of the stack: ";
        cin >> size;

        auto *stack = new Stack(size);
        auto *stackLinked = new StackLinked(size);

        //-----------------------------------------------------------------

        cout << "\nStack Using Arrays" << endl;

        auto start = high_resolution_clock::now();

        for (int j = 0; j < 10; j++) {
            stack->push(j * 2 + 5);
        }

        stack->display();

        for (int j = 0; j < 5; j++) {
            stack->pop();
        }

        stack->display();

        for (int j = 10; j < 14; j++) {
            stack->push(j * 2 + 5);
        }

        stack->display();

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "\nTime taken for stack using array:  " << duration.count() << "ns." << endl;

        delete stack;

        //--------------------------------------------------------------------------

//        cout << "Stack Using Linked List" << endl;
//
//        auto start = high_resolution_clock::now();
//
//        for (int j = 0; j < 10; j++) {
//            stackLinked->push(j * 2 + 5);
//        }
//
//        stackLinked->display();
//
//        for (int j = 0; j < 5; j++) {
//            stackLinked->pop();
//        }
//
//        stackLinked->display();
//
//        for (int j = 10; j < 14; j++) {
//            stackLinked->push(j * 2 + 5);
//        }
//
//        stackLinked->display();
//
//        auto stop = high_resolution_clock::now();
//
//        auto duration = duration_cast<nanoseconds>(stop - start);
//
//        cout << "Time taken for stack using Linked List:  " << duration.count() << "ns." << endl;
//
//        delete stackLinked;

        //--------------------------------------------------------------------------
    }



    return 0;
}
