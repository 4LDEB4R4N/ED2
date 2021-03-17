#include "HashC.h"
#include <cmath>
#include <iostream>

using namespace std;

HashC::HashC(int t_size)
{
    int i;
    while(not Is_prime(t_size)) t_size++;



    full = 0;
    tb_size = t_size;
    table = new int [t_size];

    for(i = 0; i < tb_size; i++){
        table[i] = 0;
    }
}

HashC::~HashC()
{
    //dtor
}

bool HashC::Is_prime(int number)
{
    if(number % 2 == 0) return false;

    int i;
    int root = sqrt(number);

    for(i = 3; i < root; i+=2){
        if(number % i == 0) return false;
    }

    return true;
}

void HashC::Insert(int info)
{

    if(full > tb_size/2) Rehashing();

    int index;
    int i;

    for(i = 0;;++i){
        index = (info + (i * i)) % tb_size;
        if(table[index] == 0){
            table[index] = info;
            full++;
            break;
        }
    }
}

void HashC::Delete(int info)
{
    int index;
    int i;

    for(i = 0;;++i){
        index = (info + (i * i)) % tb_size;
        if(table[index] == info){
            table[index] = 0;
            full--;
            break;
        }
    }
}

bool HashC::Search(int info)
{
    int index;
    int i;

    for(i = 0;;++i){
        index = info + (i * i) % tb_size;
        if(table[index] == info){
            return true;
        }
    }

    return false;
}

void HashC::Print()
{
    int i;

    for(i = 0; i < tb_size; i++){
        cout << table[i] << endl;
    }
}

int * HashC::Get_table(){ return table;}

int HashC::Get_size(){ return tb_size;}

void HashC::Rehashing()
{
    int i;
    int neo_size = (tb_size * 2) + 1;

    while(not Is_prime(neo_size)) neo_size+=2;

    HashC aux = HashC(neo_size);

    for(i = 0; i < tb_size; i++){
        if(table[i] != 0){
            aux.Insert(table[i]);
        }
    }

    delete table;

    table = aux.Get_table();

    tb_size = aux.Get_size();
}





















