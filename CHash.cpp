#include "CHash.h"
#include <cmath>
#include <iostream>

using namespace std;


CHash::CHash(int t_size, int probing)
{
    int i;
    P = probing;
    tb_size = t_size;

    while(not Is_prime(tb_size)) tb_size++;

    table = new int[tb_size];

    for(i = 0; i < tb_size; i++){
        table[i] = 0;
    }

}

CHash::~CHash()
{
    //dtor
}

bool CHash::Is_prime(int number)
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

void CHash::Insert(int info)
{

    int index;
    int i;

    for(i = 0; i < tb_size ;++i){
        index = H_function(info, i);

        if(table[index] == 0){
            table[index] = info;
            break;
        }
    }
}

void CHash::Delete(int info)
{
    int index;
    int i;

    for(i = 0; i < tb_size ;++i){
        index = H_function(info, i);
        if(table[index] == info){
            table[index] = 0;
            break;
        }
    }
}

bool CHash::Search(int info)
{
    int index;
    int i;

    for(i = 0; i < tb_size ;++i){
        index = H_function(info, i);
        if(table[index] == info){
            return true;
        }
    }

    return false;
}

void CHash::Print()
{
    int i;

    for(i = 0; i < tb_size; i++){
        cout << table[i] << endl;
    }
}

int CHash::H_function(int info, int age)
{
    int r;

    switch(P){
        case 1:
            return (info + (age * age)) %  tb_size;
            break;
        case 2:
            if(age == 0) return info % tb_size;
            else{
                r = info % tb_size;
                while(not Is_prime(r)) r++;

                return (age * r) % tb_size;
            }
            break;
        default:
            return (info + age) %  tb_size;
    }
}
