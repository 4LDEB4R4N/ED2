#ifndef NODET_H
#define NODET_H


class Nodet
{
private:
    int info;
    Nodet * father;
    Nodet * left;
    Nodet * right;



public:
    Nodet(int info);
    virtual ~Nodet();

    int Getinfo() { return info; }
    void Setinfo(int val) { info = val; }
    Nodet * Getfather() { return father; }
    void Setfather(Nodet * val) { father = val; }
    Nodet * Getleft() { return left; }
    void Setleft(Nodet * val) { left = val; }
    Nodet * Getright() { return right; }
    void Setright(Nodet * val) { right = val; }



    bool Is_leaf();

    Nodet * Max();
    Nodet * Min();
    Nodet * Max_of_min();
    Nodet * Min_of_max();

    int Height();
    int Balance();
};

#endif // NODET_H
