#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List
{
private:
        Node * first;

        Node * Delete(int info, Node * node);
        bool Search(Node * node, int info);
        int Height(Node * node);

public:
        List();
        virtual ~List();

        void Insert(int info);
        void Delete(int info);
        bool Search(int info);
        void Print();

        int Height();
        int Take();
        bool Is_empty();

};

#endif // LIST_H
