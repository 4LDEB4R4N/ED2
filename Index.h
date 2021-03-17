#ifndef INDEX_H
#define INDEX_H

using namespace std;


class Index
{
    private:
        int info;
        Index** father;
        Index** left;
        Index** right;

    public:
        Index(int info);
        virtual ~Index();

        void Set_info(int neo_i);
        void Set_father(Index** neo_f);
        void Set_left(Index** neo_l);
        void Set_right(Index** neo_r);
        int Get_info();
        Index** Get_father();
        Index** Get_left();
        Index** Get_right();
};

#endif // INDEX_H
