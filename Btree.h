#ifndef BTREE_H
#define BTREE_H
#include <Index.h>
#include <iostream>

class Btree
{
    private:
        Index ** root;
        int ps;

        bool Is_leaf(Index** page);
        Index** New_page();
        void Insert_on_leaf(Index** father, Index** page, Index* neo);
        void Insert_on_page(Index** father,Index** page, Index* neo);
        void Split(Index** page);
        void Show_level(Index** page, int l);
        bool Search_2(Index** page, int info);

    public:
        Btree(int order);
        virtual ~Btree();
        void Insert(int info);
        void Show();
        bool Search(int info);

    protected:


};

#endif // BTREE_H
