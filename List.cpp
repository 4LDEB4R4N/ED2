#include "List.h"
#include <iostream>
using namespace std;

List::List():
    first(NULL)
{}

List::~List(){}

void List::Insert(int info)
{
    Node * neo = new Node(info);

    neo->Setnext(first);
    first = neo;
}

void List::Delete(int info)
{
    first = Delete(info, first);
}

Node * List::Delete(int info, Node * node)
{
    if(node == NULL) return node;

    if(node->Getinfo() != info){
        node->Setnext(Delete(info, node->Getnext()));

        return node;
    }

    Node * to_return = node->Getnext();

    delete node;

    return to_return;
}

bool List::Search(int info)
{
    return Search(first, info);
}

bool List::Search(Node * node, int info)
{
        if(node == NULL) return false;

        if(node->Getinfo() == info ) return true;

        return Search(node->Getnext(), info);
}
int List::Height()
{
    return Height(first);
}

int List::Height(Node * node)
{
        if(node == NULL) return 0;
        else return Height(node->Getnext()) + 1;
}

void List::Print()
{
    Node * aux;

    for(aux = first; aux != NULL; aux = aux->Getnext()){
        cout << aux->Getinfo() << " ";
    }
    cout << endl;
}

bool List::Is_empty()
{
    if(first == NULL) return true;

    else return false;
}

int List::Take(){

    int to_take = first->Getinfo();

    Delete(to_take);

    return to_take;
}

