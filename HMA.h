#ifndef HMA_H
#define HMA_H
#include "Avl.h"

class HMA
{
private:
    Avl * table;
    int tb_size;
    int full;
    int l;

    bool Is_prime(int number);
    void Rehashing();

public:
    HMA(int t_size, int lambda);
    virtual ~HMA();

    void Insert(int info);
    void Delete(int info);
    bool Search(int info);
    void Print();

    Avl * Get_table();
    int Get_full();
    int Get_size();

};

#endif // HMA_H
