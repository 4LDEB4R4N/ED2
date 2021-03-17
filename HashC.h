#ifndef HASHC_H
#define HASHC_H


class HashC
{
private:
    int * table;
    int tb_size;
    int full;

    bool Is_prime(int number);
    void Rehashing();

public:
    HashC(int t_size);
    virtual ~HashC();

    void Insert(int info);
    void Delete(int info);
    bool Search(int info);

    void Print();

    int * Get_table();
    int Get_size();

};

#endif // HASHC_H
