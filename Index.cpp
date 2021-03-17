#include "Index.h"

Index::Index(int info)
{
    this->info = info;
    this->left = nullptr;
    this->right = nullptr;
}

Index::~Index()
{
    //dtor
}

void Index::Set_info(int neo_i)
{
    this->info = neo_i;
}
void Index::Set_father(Index**  neo_f)
{
    this->father = neo_f;
}
void Index::Set_left(Index**  neo_l)
{
    this->left = neo_l;
}
void Index::Set_right(Index** neo_r)
{
    this->right = neo_r;
}
int Index::Get_info()
{
    return this->info;
}
Index** Index::Get_father()
{
    return this->father;
}
Index** Index::Get_left()
{
    return this->left;
}
Index** Index::Get_right()
{
    return this->right;
}

