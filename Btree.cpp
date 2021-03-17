#include "Btree.h"
using namespace std;

Btree::Btree(int order)
{
    this->ps = (order * 2) + 1;
    this->root = nullptr;
}

Btree::~Btree()
{
    //dtor
}

bool Btree::Is_leaf(Index** page)
{
    if(page[0]->Get_left() == nullptr) return true;
    else return false;
}

Index** Btree::New_page()
{
    int i;
    Index** neo_p = new Index*[ps];

    for(i = 0; i < ps; i++) neo_p[i] = nullptr;

    return neo_p;
}

void Btree::Insert_on_leaf(Index** father, Index** page, Index* neo)
{
    int i;


    if(not Is_leaf(page)){
        for(i = 0; page[i]!= nullptr; i++){
            if(neo->Get_info() == page[i]->Get_info()) return;
            else if(neo->Get_info() < page[i]->Get_info()){
                Insert_on_leaf(page, page[i]->Get_left(), neo);
                break;
            }

        }

        if(page[i] == nullptr) Insert_on_leaf(page, page[i-1]->Get_right(), neo);
    }
    else{

        Insert_on_page(father, page, neo);
    }

}
void Btree::Insert_on_page(Index** father,Index** page, Index* neo)
{
    int i;
    Index* trade;
    neo->Set_father(father);

    for(i = 0; page[i]!= nullptr; i++){
        if(neo->Get_info() == page[i]->Get_info()) return;
        else if(neo->Get_info() < page[i]->Get_info()){
            trade = page[i];
            page[i] = neo;
            neo = trade;

            neo->Set_left(page[i]->Get_right());
            if(i != 0)page[i-1]->Set_right(page[i]->Get_left());
        }
    }

    page[i] = neo;
    if(i != 0)page[i-1]->Set_right(page[i]->Get_left());

    if(page[ps-1] != nullptr) Split(page);
}

void Btree::Split(Index** page)
{
    int i;
    int mid = ps/2;

    Index** father = page[mid]->Get_father();

    if(father == nullptr){
            father = New_page();
            root = father;
    }
    else page[mid]->Set_father(father[0]->Get_father());

    Index** l = New_page();
    Index** r = New_page();
    page[mid]->Set_left(l);
    page[mid]->Set_right(r);

    for(i = 0; i < ps; i++){
        if(i < mid)Insert_on_page(father, l, page[i]);
        else if(i > mid)Insert_on_page(father, r, page[i]);
    }

    Insert_on_page(page[mid]->Get_father(), father, page[mid]);

    delete page;
}


void Btree::Insert(int info)
{
    Index* neo = new Index(info);

    if(root == nullptr){
            root =  New_page();
            root[0] = neo;
    }
    else{
        Insert_on_leaf(nullptr, root, neo);
    }
}

bool Btree::Search(int info)
{
    return Search_2(root, info);
}

bool Btree::Search_2(Index** page, int info)
{
    int i;

    if(page == nullptr) return false;

    else{
        for(i = 0; page[i]!= nullptr; i++){
            if(info == page[i]->Get_info()) return true;
            else if(info < page[i]->Get_info()){
                return Search_2(page[i]->Get_left(), info);
            }
        }

        if(page[i] == nullptr) return Search_2(page[i-1]->Get_right(), info);
    }
}

/*
void Btree::Remove_2(Index** page, int info)
{
    int i;
    if(page == nullptr) return;

    else{
        for(i = 0; page[i]!= nullptr; i++){
            if(info == page[i]->Get_info()) Remove_3(page, i);
            else if(info < page[i]->Get_info()){
                Remove_2(page[i]->Get_left(), info);
                break;
            }
        }

        if(page[i] == nullptr) Remove_2(page[i-1]->Get_right(), info);
    }
}

void Btree::Remove_3(Index** page, int index)
{
    int i;
    Index** father;
    Index** l;
    Index** r;

    if(Is_leaf(page)){

        delete page[index];
        page[index] = nullptr;

        for(i = index; i < ps-1; i++){
            page[i] = page[i+1];
        }

        if(page[(ps/2) - 1] == nullptr){
            father = page[0]->Get_father();

            for(i = 0; father[i] != nullptr; i++){
                if(page[0]->Get_info() < father[i]->Get_info()){
                    break;
                }
            }
            if(father[i] == nullptr) i--;

            l = father[i]->Get_right();
            r = father[i]->Get_left();

            if(l == page){
                if(r[(ps/2)] == nullptr) Merge(father, i, page);
                else{
                    page[(ps/2) - 1] = father[i];
                    r[0]->Set_left(father[i]->Get_left());
                    r[0]->Set_right(father[i]->Get_right());
                    r[0]->Set_father(father[i]->Get_father());
                    father[i]->Set_left(nullptr);
                    father[i]->Set_right(nullptr);
                    Insert_on_page(father, l, father[i]);
                    father[i] = nullptr;
                    Insert_on_page(r[0]->Get_father(), father, r[0]);
                    r[0] = nullptr;

                    for(i = 0; i < ps-1; i++){
                        r[i] = r[i+1];
                    }
                }
            }
            else{
                if(l[(ps/2)] == nullptr) Merge(father, i, page);
                else{
                    page[(ps/2) - 1] = father[i];
                    l[0]->Set_left(father[i]->Get_left());
                    l[0]->Set_right(father[i]->Get_right());
                    l[0]->Set_father(father[i]->Get_father());
                    father[i]->Set_left(nullptr);
                    father[i]->Set_right(nullptr);
                    Insert_on_page(father, r, father[i]);
                    father[i] = nullptr;
                    Insert_on_page(r[0]->Get_father(), father, l[0]);
                    l[0] = nullptr;

                    for(i = 0; i < ps-1; i++){
                        l[i] = l[i+1];
                    }
                }
            }
        }
    }
    else{

        l = page[index]->Get_left();
        r = page[index]->Get_right();

        if(l[])



    }
}

void Btree::Merge(Index** father, int father_i, Index** page)
{
    int i;
    Index** merge_p = New_page();
    Index** l = father[father_i]->Get_left();
    Index** r = father[father_i]->Get_right();

    father[father_i]->Set_left(nullptr);
    father[father_i]->Set_right(nullptr);
    Insert_on_page(nullptr, page, father[father_i]);

    father[father_i] = nullptr;

    for(i = 0; l[i] != nullptr; i++) Insert_on_page(father, merge_p, l[i]);
    for(i = 0; r[i] != nullptr; i++) Insert_on_page(father, merge_p, r[i]);
    delete l;
    delete r;

    for(i = father_i; i < ps-1; i++){
        father[i] = father[i+1];
    }

    for(i = 0; father[i] != nullptr; i++){
        if(merge_p[0]->Get_info() < father[i]->Get_info()){
            father[i]->Set_left(merge_p);
            break;
        }
    }
    if(i > 0) father[i-1]->Set_right(merge_p);

    if(page[ps-1] != nullptr) Split(page);

}
*/

void Btree::Show()
{
    int i, height;
    Index ** page = root;
    for(i = 0, height = 0; page != nullptr; i++, height++, page = page[0]->Get_left());

    for(i = 0; i < height; i++){
        Show_level(root,i);
        cout << "\n\n";
    }
}

void Btree::Show_level(Index** page, int l)
{
    int i;
    if(l == 0){
        cout << " [ ";
        for(i = 0; page[i] != nullptr; i++){
            cout << page[i]->Get_info() << " ";
        }
        cout << "] ";
    }
    else{
        for(i = 0; page[i] != nullptr; i++){
            Show_level(page[i]->Get_left(), l-1);
        }
        Show_level(page[i-1]->Get_right(), l-1);
    }
}
