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

class LinkedList //These are basically The STRUCTURE OF THE LINKED LIST ,LIKE ADDING,DELETION,and we can use these function we created in class for other functions outside the class.
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

    void insertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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
        return 1;

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


//Segragate the Linked List In Even and Odd Linked List(Basically create two new Linked List having the Even and Odd Numbers in lIst Separately)
void separateEvenAndOdd(LinkedList* ll)
{
    ll->print();
    cout << endl;
    Node* evenHead=NULL, * evenTail=NULL, * oddHead=NULL, * oddTail=NULL;
    Node* head = ll->getHead();

    while (head != NULL)
    {
        if (head->data & 1) // the AND OPERATION(BIT MANIPULATION) to check for even or odd! The Bit Manipulation does Faster Calculations.
        {
            //Odd Node Case
            if (oddHead == NULL)
            {
                oddHead = head;
                oddTail = oddHead;
            }
            else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        else
        {
            //Even Node Case
            if (evenHead == NULL)
            {
                evenHead = head;
                evenTail = evenHead;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        head = head->next;
    }

    if (evenTail)
        evenTail->next = NULL;
    if (oddTail)
        oddTail->next = NULL;

    LinkedList oll = LinkedList();
    oll.setHead(head);
    LinkedList ell = LinkedList();
    ell.setHead(head);
    ell.print();
    oll.print();
}

Node* mergeTwoSortedList(Node* ll1, Node* ll2)
{
    if (ll1 == NULL)
        return ll2;

    else if (ll2 == NULL)
        return ll1;
    else
    {
        Node* newHead;
        if (ll1->data < ll2->data)
        {
            newHead = ll1;
            newHead->next = mergeTwoSortedList(ll1->next, ll2);
        }
        else
        {
            newHead = ll2;
            newHead->next = mergeTwoSortedList(ll1, ll2->next);
        }
        return newHead;
    }
}

int main()
{
    LinkedList ll1= LinkedList();
    LinkedList ll2 = LinkedList();

    /*
    * ll.print();
    //Keep in mind that We must take only single digit for every node(because that's our problem)
    ll.insertAtBeginning(1);
    ll.insertAtBeginning(9);
    ll.insertAtBeginning(9);
    ll.insertAtBeginning(8);
    */

    ll1.insertAtEnd(1);
    ll1.insertAtEnd(3);
    ll1.insertAtEnd(4);
    ll1.insertAtEnd(5);
    ll1.insertAtEnd(7);
    ll1.insertAtEnd(11);
    ll2.insertAtEnd(2);
    ll2.insertAtEnd(8);
    ll2.insertAtEnd(15);
    ll2.insertAtEnd(17);
    ll2.insertAtEnd(19);

//    separateEvenAndOdd(&ll); //We Pass Reference ,so That ,the things we're passing doesn't create it's own entity in the system.
    Node* newHead = mergeTwoSortedList(ll1.getHead(), ll2.getHead());
    LinkedList ll3 = LinkedList();
    ll3.setHead(newHead);
    cout << "The Merged Sorted List :  ";
    ll3.print(); 
    /*
    
    ll.setHead(add1ToNumber(ll.getHead()));
    cout << endl;
    ll.print();
    */

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

