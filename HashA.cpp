#include "HashA.h"
#include <cmath>
#include <iostream>

using namespace std;

HashA::HashA(int t_size)
{
    while(not Is_prime(t_size)) t_size++;

    tb_size = t_size;
    table = new Avl [t_size];
}

HashA::~HashA()
{
    //dtor
}

bool HashA::Is_prime(int number)
{
    if(number % 2 == 0) return false;

    int i;
    int root = sqrt(number);

    if(number % root == 0) return false;

    for(i = 2; i < root; i++){
        if(number % i == 0) return false;
    }

    return true;
}

void HashA::Insert(int info)
{
    int index = info % tb_size;

    table[index].Insert(info);
}

void HashA::Delete(int info)
{
    int index = info % tb_size;

    table[index].Delete(info);
}

bool HashA::Search(int info)
{
    int index = info % tb_size;

    return table[index].Search(info);
}


void HashA::Print()
{
    int i;

    for(i = 0; i < tb_size; i++){
        if(table[i].Is_empty()) cout << "empty" << endl;
        else table[i].Print();
    }
}


