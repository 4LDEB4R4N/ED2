#ifndef HASH_H
#define HASH_H
#include "List.h"


class Hash
{
private:
    List * table;
    int tb_size;

    bool Is_prime(int number);

public:

Hash(int t_size);
virtual ~Hash();

void Insert(int info);
void Delete(int info);
bool Search(int info);
void Print();

};

#endif // HASH_H
