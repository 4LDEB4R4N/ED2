#ifndef PAGE_H
#define PAGE_H
#include <vector>
#include <Index.h>
using namespace std;
class Index;

class Page
{
    private:
        vector<Index> page;
        Page * father;
        int ps;

    public:
        Page(int o);
        virtual ~Page();
        void Insert(int info);

};



#endif // PAGE_H
