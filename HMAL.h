#ifndef HMAL_H
#define HMAL_H
#include "List.h"

class HMAL
{
private:
    List * table;
    int tb_size;
    int full;
    int l;

    bool Is_prime(int number);
    void Rehashing();

public:
    HMAL(int t_size, int lambda);
    virtual ~HMAL();

    void Insert(int info);
    void Delete(int info);
    bool Search(int info);
    void Print();

    List * Get_table();
    int Get_full();
    int Get_size();

};

#endif // HMAL_H
