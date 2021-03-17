#ifndef CHASH_H
#define CHASH_H


class CHash
{
private:
    int * table;
    int tb_size;
    int P;

    bool Is_prime(int number);
    void Rehashing();
    int H_function(int info, int age);

public:
    CHash(int t_size, int probing);
    virtual ~CHash();

    void Insert(int info);
    void Delete(int info);
    bool Search(int info);

    void Print();


};

#endif // CHASH_H
