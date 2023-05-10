#pragma once
#include <iostream>

using namespace std;


struct monom
{
    double modif;
    size_t degree;
    monom() :modif(0), degree(0) {};
    monom(double midf, size_t deg) :modif(midf), degree(deg) {};
    const monom& operator =(const monom& mon)
    {
        this->modif = mon.modif;
        this->degree = mon.degree;
        return *this;
    }
    friend ostream& operator<<(ostream& ostr, const monom& _monom)
    {
        ostr << _monom.modif << "x^" << _monom.degree / 100 << "y^" << _monom.degree % 100 / 10 << "z^" << _monom.degree % 10;
        return ostr;
    }
    //elem(double mdf) :modif(mdf), _next(nullptr) {}
};

struct Node {
	monom data;
	Node* next;
	Node() :next(nullptr) {};
	Node(monom dt) : data(dt), next(nullptr) {};
    const Node& operator =(const Node& mon)
    {
        this->data = mon.data;
        this->next = mon.next;
        return *this;
    }
};

class List {
public:
    Node* Head;
    Node* sorted;

	List() :Head(new Node),sorted(new Node) {}
    void push(monom val)
    {
        Node* newnode = new Node(val);
        newnode->next = Head;
        Head = newnode;
    }

    void insertionSort(Node* headref)
    {
        sorted = NULL;
        Node* current = headref;

        while (current != NULL)
        {
            Node* next = current->next;

            sortedInsert(current);

            current = next;
        }

        Head = sorted;
    }

    void sortedInsert(Node* newnode)
    {
        // Special case for the head end

        if (sorted == NULL ||
            sorted->data.degree <= newnode->data.degree)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            Node* current = sorted;

            /* Locate the node before the
               point of insertion */
            while (current->next != NULL &&
                current->next->data.degree<= newnode->data.degree)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }

    const List& operator =(const List& mon)
    {
        Head = mon.Head;
        sorted = mon.sorted;
        return *this;
    }

    void pushsorted(const monom& val)
    {
        Node* tmp = new Node(val);
        Node* tmp2 = this->Head;
        if (Head->next == NULL)
        {
            tmp2->next = tmp;
            tmp2 = this->Head;
        }
        else {
            Node* tmp2nxt = this->Head->next;
            while (tmp2nxt && (tmp->data.degree < tmp2nxt->data.degree))
            {
                tmp2 = tmp2->next;
                tmp2nxt = tmp2nxt->next;
            }
            tmp->next = tmp2->next;
            tmp2->next = tmp;
        }
    }
    /*void insertionSort(const double& val)
    {
        {
            Node* elem = new Node(val);
            Node* p = Head;
            if (Head->next == NULL)
            {
                p->next = elem;
                p = elem;
                return;
            }
            Node* p_next = Head->next;
            while (p_next && elem->data < p_next->data)
            {
                p = p->next;
                p_next = p_next->next;
            }
            elem->next = p_next;
            p->next = elem;
        }
    }*/

    //void printlist(Node* head)
    //{
    //    while (head != NULL)
    //    {
    //        cout << head->data << " ";
    //        head = head->next;
    //    }
    //}

};