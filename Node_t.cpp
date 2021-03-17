#include "Node_t.h"
#include <iostream>

Node_t::Node_t(int info):
    info(info),
    father(NULL),
    left(NULL),
    right(NULL)
{}


Node_t::~Node_t()
{
    //dtor
}
