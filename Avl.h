#ifndef AVL_H
#define AVL_H
#include "Nodet.h"

class Avl
{
private:
    Nodet * root;

    void Insert(Nodet * node, Nodet * neo);
    void Delete(Nodet * to_delete);
    void Delete_leaf(Nodet * to_delete);
    void Balance_tree(Nodet * neo);
    void D_rotation(Nodet * k2, int type);
    void S_rotation(Nodet * k2, int type);
    Nodet * Node_search(int info);
    Nodet * Search(Nodet * node, int info);
    void Print_avl(Nodet * node,int height);
    void Print_avl(Nodet * node, int height, double p);
    void Print_avl_2(Nodet * node, int height, double p);
    void Hard_balance(Nodet * node);
    void Delete_balance(Nodet * to_delete, int b);
    void Insert_balance(Nodet * root, Nodet * neo, int b);

public:
    Avl();
    virtual ~Avl();

    void Insert(int info);
    void Delete(int info);
    bool Search(int info);

    void Print();
    void Print_t();
    void Print_b();

    void Hard_balance();

    //HMA methods
    int  Take();
    bool Is_free();
    bool Is_empty();
    int  Height();

};

#endif // AVL_H
