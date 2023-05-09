// Lab 6 inclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


class Array_Stack {
private:
    const static int ARRAY_SIZE = 10;

    int top = -1;
    int arr[ARRAY_SIZE];

public:
    void push(int e)
    {
        if (this -> isFull())
        {
            throw 0;
        }
        top++;
        arr[top] = e;
        
    }
    int pop()
    {
        if (this -> isEmpty())
        {
            throw 1;
        }
        top--;
        return arr[top + 1];
    }
    int StackTop()
    {
        if (this->isEmpty())
        {
            throw 3;
        }
        return arr[top];
    }
    void Display()
    {
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == ARRAY_SIZE - 1)
        {
            return true;
        }
        return false;
    }

};

class Node {
public:
    int data;
    Node* next;

    Node(int e)
    {
        this->data = e;
        next = nullptr;
    }
};
class LinkedList_Stack {
private:
    Node* top;
public:
    LinkedList_Stack()
    {
        this->top = nullptr;
    }

    void push(int e)
    {
        Node* nextItem = new Node(e);
        nextItem->next = top;
        top = nextItem;
    }
    int pop()
    {
        if (this -> isEmpty())
        {
            throw 1;
        }
        int e = this->top->data;
        this->top = top->next;
        return e;
    }
    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }
    int StackTop()
    {
        if (this->isEmpty())
        {
            throw 2;
        }
        return top->data;
    }
    void Display()
    {
        if (!this->isEmpty())
        {
            Node* thisItem = this->top;
            while (thisItem != nullptr)
            {
                cout << thisItem->data << " ";
                thisItem = thisItem->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    auto start1 = high_resolution_clock::now();
    Array_Stack arrayStack;
    arrayStack.push(8);
    arrayStack.push(10);
    arrayStack.push(5);
    arrayStack.push(11);
    arrayStack.push(15);
    arrayStack.push(23);
    arrayStack.push(6);
    arrayStack.push(18);
    arrayStack.push(20);
    arrayStack.push(17);
    arrayStack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        arrayStack.pop();
    }
    arrayStack.Display();
    arrayStack.push(4);
    arrayStack.push(30);
    arrayStack.push(3);
    arrayStack.push(1);
    arrayStack.Display();

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::nanoseconds>(end1 - start1);
    cout << "Array stack running time : " << duration1.count() << " ns" << endl;


    auto start = high_resolution_clock::now();

    LinkedList_Stack linkedlist_Stack;
    linkedlist_Stack.push(8);
    linkedlist_Stack.push(10);
    linkedlist_Stack.push(5);
    linkedlist_Stack.push(11);
    linkedlist_Stack.push(15);
    linkedlist_Stack.push(23);
    linkedlist_Stack.push(6);
    linkedlist_Stack.push(18);
    linkedlist_Stack.push(20);
    linkedlist_Stack.push(17);
    linkedlist_Stack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        linkedlist_Stack.pop();
    }
    linkedlist_Stack.Display();
    linkedlist_Stack.push(4);
    linkedlist_Stack.push(30);
    linkedlist_Stack.push(3);
    linkedlist_Stack.push(1);
    linkedlist_Stack.Display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "LinkedList stack running time : " << duration.count() << " ns" << endl;



}
