#include "HMAL.h"
#include <iostream>
#include <cmath>

using namespace std;

HMAL::HMAL(int t_size, int lambda)
{
    while(not Is_prime(t_size)) t_size++;

    full = 0;
    l = lambda;
    tb_size = t_size;
    table = new List[t_size];
}

HMAL::~HMAL()
{
    //dtor
}

bool HMAL::Is_prime(int number)
{
    if(number % 2 == 0) return false;

    int i;
    int root = sqrt(number);

    for(i = 3; i < root; i+=2){
        if(number % i == 0) return false;
    }

    return true;
}

void HMAL::Insert(int info)
{

    if(full > tb_size/2) Rehashing();

    int index;
    int i, h;

    for(i = 0;;++i){
        index = (info + (i * i)) % tb_size;
        h = table[index].Height();
        if(h < l){
            table[index].Insert(info);

            if(table[index].Height() == l ) full++;
            break;
        }
    }
}

void HMAL::Delete(int info)
{
    int index;
    int i, h;

    for(i = 0;;++i){
        index = (info + (i * i)) % tb_size;
        if(table[index].Search(info)){
            table[index].Delete(info);

            if(table[index].Height() == l-1)full--;
            break;
        }
    }
}

bool HMAL::Search(int info)
{
    int index;
    int i;

    for(i = 0;;++i){
        index = (info + (i * i)) % tb_size;
        if(table[index].Search(info)) return true;
    }

    return false;
}

List * HMAL::Get_table(){ return table;}

int HMAL::Get_full(){ return full;}

int HMAL::Get_size(){ return tb_size;}



void HMAL::Rehashing()
{
    int i;
    int neo_size = (tb_size * 2) + 1;

    while(not Is_prime(neo_size)) neo_size += 2;

    HMAL aux = HMAL(neo_size, l);

    for(i = 0; i < tb_size; i++){
        while(not table[i].Is_empty()){
            aux.Insert(table[i].Take());
        }
    }

    delete table;

    table = aux.Get_table();
    full = aux.Get_full();
    tb_size = aux.Get_size();
}

void HMAL::Print()
{
    int i;

    for(i = 0; i < tb_size; i++){
        if(not table[i].Is_empty()){
            cout << endl;
            table[i].Print();
        }
        else cout << endl << "empty" << endl;
    }
}
