#include "Nodet.h"
#include <iostream>

Nodet::Nodet(int info):
    info(info),
    father(NULL),
    left(NULL),
    right(NULL)
{}

Nodet::~Nodet()
{
    //dtor
}

bool Nodet::Is_leaf()
{
    return left == NULL && right == NULL;
}

Nodet * Nodet::Min()
{
    if(left == NULL) return this;
       else return left->Min();
}

Nodet * Nodet::Max()
{
    if(right == NULL) return this;
       else return right->Max();
}

Nodet * Nodet::Min_of_max()
{
    return right->Min();
}

Nodet * Nodet::Max_of_min()
{
    return left->Max();
}

int Nodet::Height()
{
    if(this->Is_leaf()) return 0;

    else if(left == NULL) return right->Height() + 1;
    else if(right == NULL) return left->Height() + 1;

    else{
        int l, r;

        l = left->Height();
        r = right->Height();

        if(l >= r) return l + 1;
        else return r + 1;
    }
}

int Nodet::Balance()
{
    if(this->Is_leaf()) return 0;

    else if(left == NULL)return -(this->Height());
    else if(right == NULL)return this->Height();

    else return left->Height() - right->Height();
}







