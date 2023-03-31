// Linked_List_LevelUP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map> //to include unordered_map -> for mappping the addresses in this question.
using namespace std;

//Clone a LL having random pointers.(Means->Same LL but with Different Addresses in memory than the original LL)


/*

class Node {

    int data;
    Node* next;
    Node* random;
public:
    Node(int d)
    {
        data = d;
        next = NULL;
        random = NULL;
    }

    void setData(int d)
    {
        data = d;

    }
    int getData()
    {
        return data;
    }
    void setNext(Node* n)
    {
        next = n;
    }
    Node* getNext()
    {
        return next;
    }
    void setRandom(Node* r)
    {
        random = r;
    }
    Node* getRandom()
    {
        return random;
    }

};


class LinkedList {

    Node* head;
    Node* tail;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    Node* getHead()
    {
        return head;
    }
    Node* getTail()
    {
        return tail;
    }
    void insertAtTheEnd(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node* curr = head;
            while (curr->getNext() != NULL)
            {
                curr = curr->getNext();
            }
            curr->setNext(newNode);
            tail = newNode;
        }
    }

    void print()
    {
        Node* curr = head;
        while (curr != NULL)
        {
            cout <<"("<<curr<<"," << curr->getData() << ") ("<<curr->getRandom()<< ", ";
            if (curr->getRandom() != NULL)
                cout << curr->getRandom()->getData()<<")" << endl;
            else
                cout << "NULL)" << endl;
            curr = curr->getNext();
        }
    }

};

LinkedList* createClone(Node* head1)
{
    Node* curr, * next,*head2;
    curr = head1;
    unordered_map<Node*, Node*> um;
    LinkedList ll2 = LinkedList();

    while (curr != NULL)
    {
        ll2.insertAtTheEnd(curr->getData());
        um[curr] = ll2.getTail();
        curr = curr->getNext();
    }
    head2 = ll2.getHead();

    while (head1 != NULL)
    {
        head2->setRandom(um[head1->getRandom()]);
        head1 = head1->getNext();
        head2 = head2->getNext();

    }
    return &ll2;
}

*/

//ADD  1 to the linked List and create the linked list after the addition using RECURSION...

struct Node //Creating Node using Struct 
{
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};


class LinkedList 
{
    Node* head, * tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node* newHead)
    {
        head = newHead;
    }

    Node* getHead()
    {
        return head;
    }
    Node* getTail()
    {
        return tail;
    }

    void insertAtBeginning(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while (current != NULL)
            {
                cout << current->data << "->";
                current = current->next;
            }
            cout << "NULL";
        }
    }

    bool empty()
    {
        return head == NULL;
    }

};


int add1ToNumberUtil(Node* curr)
{
    if (curr == NULL)
    {
        return 1;
    }
    int toAdd = add1ToNumberUtil(curr->next);
    int carry = (curr->data + toAdd) / 10;
    curr->data = (curr->data + toAdd) % 10;
    return carry;
}

Node* add1ToNumber(Node *head)
{
    int carry = add1ToNumberUtil(head);
    if (carry == 1)
    {
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    LinkedList ll= LinkedList();

    ll.print();

    ll.insertAtBeginning(9);
    ll.insertAtBeginning(9);
    ll.insertAtBeginning(9);
    ll.insertAtBeginning(8);

    ll.print();
    ll.setHead(add1ToNumber(ll.getHead()));
    cout << endl;
    ll.print();

    /*
     ll1.insertAtTheEnd(10);
    ll1.insertAtTheEnd(11);
    ll1.insertAtTheEnd(12);
    ll1.insertAtTheEnd(13);


    Node* head1 = ll1.getHead();
    head1->setRandom(head1->getNext()->getNext());
    head1->getNext()->setRandom(NULL);
    head1->getNext()->getNext()->setRandom(head1);
    head1->getNext()->getNext()->getNext()->setRandom(head1->getNext());

    ll1.print();
    cout << endl;

    cout << "LL2 Printint" << endl;

    LinkedList* ll2 = createClone(head1);
    ll2->print();
    
    */
   

    return 0;
}

