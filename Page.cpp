#include "Page.h"

Page::Page(int o)
{
    this->ps = (o * 2) + 1;
    this->father = nullptr;
}

Page::~Page()
{
    //dtor
}

void Page::Insert(int info)
{
    unsigned int i;
    bool key = true;
    Index neo(info);
    vector<Index> order;

    for(i = 0; i < page.size(); i++){
        if(neo.Get_info() < page[i].Get_info() and key){
            order.push_back(neo);
            key = false;
        }
        order.push_back(page[i]);
    }



    if(page.size() == ps) Split();
}
