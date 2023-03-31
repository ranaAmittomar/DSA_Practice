// Stack_levelUP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include<stack>
using namespace std;

//implementing two stacks in an array....

class TwoStacks 
{
    int* arr;
    int top1;
    int top2;
    int size1;
    int size2;
    int maxsize;
public:
    TwoStacks(int size =10)
    {
        maxsize = size;
        top1 = -1;
        top2 = size;
        size1 = 0;
        size2 = 0;
        arr = new int[maxsize];
    }
    bool full() {
        return top1 + 1 == top2;
    }
    void push1(int data){
        if (full()) {
            cout << "Stack 1 is full.So,can't add more elements !" << endl;
            return;
        }
        else {
            top1++;
            arr[top1] = data;
            size1++;
        }

    }
    void pop1(){
        if (empty1()) {
            cout << "Stack 1 is empty.So,can't delete any item from Stack 1" << endl;
            return;
        }
        else
        {
            arr[top1] = -1;
            top1--;
            size1--;
        }
    }
    void push2(int data) {
        if (full()) {
            cout << "Stack2 is full.So,can't add more elements !!" << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2] = data;
            size2++;
        }
    }
    void pop2(){
        if (empty2()) {
            cout << "Stack2 is empty.So,can't delete more elements !!" << endl;
            return;
        }
        else
        {
            arr[top2] = -1;
            top2++;
            size2--;
        }
    }
    bool empty1() {
        return top1 == -1;
    }
    bool empty2() {
        return top2 == maxsize;
    }
    int getSize1() {
        return size1;
    }
    int getSize2() {
        return size2;
    }

    void print() {
        if (empty1() && empty2())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < maxsize; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};



int main()
{

    TwoStacks ts = TwoStacks(8);
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push1(40);
    ts.push1(50);
    ts.push2(60);
    ts.push2(70);
    ts.push2(80);
    ts.push2(90);
    ts.print();
    ts.pop2();
    ts.print();
    ts.push1(12);
    ts.print();
    ts.push1(88);
    ts.print();
    return 0;
}

