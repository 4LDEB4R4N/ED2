#ifndef HASHA_H
#define HASHA_H
#include "Avl.h"


class HashA
{
private:
    Avl * table;
    int tb_size;

    bool Is_prime(int number);

public:

HashA(int t_size);
virtual ~HashA();

void Insert(int info);
void Delete(int info);
bool Search(int info);
void Print();

};

#endif // HASHA_H
