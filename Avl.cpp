#include "Avl.h"
#include <iostream>
#include <cmath>

using namespace std;

Avl::Avl():
    root(NULL)
{}

Avl::~Avl()
{
    //dtor
}

void Avl::Insert(int info)			//Gets a int info, creates a node, insert in the tree
{
    Nodet * neo =  new Nodet(info);	//Creates a node with the info

    if(root == NULL) root = neo;	//If the tree is empty, the node is the root

    else{							//Else, insert the node in the tree and balance
        Insert(root,neo);			

        Balance_tree(neo);
    }
}

void Avl::Insert(Nodet * node, Nodet * neo)			//Insert a node in the tree
{
    if(neo->Getinfo() > node->Getinfo()){			//Search for the place to insert the node...
        if (node->Getright() == NULL){				//intiates in the root, if the info is grater than the...
            node->Setright(neo);					//info in the actual node search for a place in the right son of the node,...
            neo->Setfather(node);					//else, if the info is smaller than the info in the actual node...
        }											//search for a place in the left son of the node...
        else this->Insert(node->Getright(), neo);	//if the place is empty insert the node, else...
    }												//search for a place in this node.
    else if(neo->Getinfo() < node->Getinfo()){
        if(node->Getleft() == NULL){
            node->Setleft(neo);
            neo->Setfather(node);
        }
        else Insert(node->Getleft(), neo);
    }
}

void Avl::Delete(int info)	//Gets a int info, searches the node with the info, delete the node
{
    Delete(Node_search(info));
}

void Avl::Delete(Nodet * to_delete){ //Gets the pointer for a node, delete this node
    Nodet * aux;
    int info;

    if(to_delete->Is_leaf()) Delete_leaf(to_delete);	//If the node is a leaf, delete leaf

    else{												//Else, if the left son is empty, search for the...
        if(to_delete->Getleft() == NULL){ 				//smaller leaf in the right son, else search the greater...	
            aux = to_delete->Min_of_max();				//leaf in the left son, then swap the infos and delete the leaf
            info = aux->Getinfo();
            Delete(aux);
        }
        else{
            aux = to_delete->Max_of_min();
            info = aux->Getinfo();
            Delete(aux);
        }

        to_delete->Setinfo(info);
    }
}

void Avl::Delete_leaf(Nodet * to_delete)
{
    Nodet * father = to_delete->Getfather();

    if (father == NULL){

        delete root;
        root = NULL;

    }
    else{
        if(father->Getinfo() > to_delete->Getinfo())
            father->Setleft(NULL);

        else father->Setright(NULL);

        delete to_delete;
    }

    Balance_tree(father);
}

void Avl::Balance_tree(Nodet * neo)
{
    if(neo == NULL) return;

    Nodet * aux;

    int b = neo->Balance();

    switch(b){
        case -2:
            aux = neo->Getright();

            if(aux->Balance() == -1) S_rotation(aux,1);

            else D_rotation(aux->Getleft(),1);

            break;
        case 2:
            aux = neo->Getleft();

            if(aux->Balance() == 1) S_rotation(aux,2);

            else D_rotation(aux->Getright(),2);

            break;
        default:
            if(b > 2) Balance_tree(neo->Getleft());
            else if(b < -2) Balance_tree(neo->Getright());
            else Balance_tree(neo->Getfather());
            break;
    }
}

bool Avl::Search(int info)
{
    if(Node_search(info) == NULL) return false;

    else return true;
}

Nodet * Avl::Node_search(int info)
{
    return Search(root, info);
}

Nodet * Avl::Search(Nodet * node, int info)
{
    if(node == NULL)return NULL;

    else{
        int i = node->Getinfo();

        if(i == info) return node;
        else if(i > info) return Search(node->Getleft(), info);
        else return Search(node->Getright(), info);
    }
}

void Avl::S_rotation(Nodet * k2,int type)
{
    Nodet * k1 = k2->Getfather();
    Nodet * father = k1->Getfather();

    k2->Setfather(father);
    k1->Setfather(k2);

    if(father == NULL)root = k2;
    else if(k2->Getinfo() > father->Getinfo()) father->Setright(k2);
    else father->Setleft(k2);

    switch(type){
        case 1:
            k1->Setright(k2->Getleft());
            k2->Setleft(k1);

            if(k1->Getright() != NULL)
                k1->Getright()->Setfather(k1);

            break;
        case 2:
            k1->Setleft(k2->Getright());
            k2->Setright(k1);

            if(k1->Getleft() != NULL)
                k1->Getleft()->Setfather(k1);

            break;
    }
}

void Avl::D_rotation(Nodet * k2,int type)
{
    Nodet * k1 = k2->Getfather();
    Nodet * k3 = k1->Getfather();
    Nodet * father = k3->Getfather();

    k2->Setfather(father);
    k1->Setfather(k2);
    k3->Setfather(k2);

    if(father == NULL)root = k2;
    else if(k2->Getinfo() > father->Getinfo()) father->Setright(k2);
    else father->Setleft(k2);

    switch(type){
        case 1:
            k1->Setleft(k2->Getright());
            k3->Setright(k2->Getleft());
            k2->Setright(k1);
            k2->Setleft(k3);


            if(k1->Getleft() != NULL)
                k1->Getleft()->Setfather(k1);

            if(k3->Getright() != NULL)
                k3->Getright()->Setfather(k3);

            break;
        case 2:
            k1->Setright(k2->Getright());
            k3->Setleft(k2->Getleft());
            k2->Setleft(k1);
            k2->Setright(k3);

            if(k1->Getright() != NULL)
                k1->Getright()->Setfather(k1);

            if(k3->Getleft() != NULL)
                k3->Getleft()->Setfather(k3);

            break;
    }
}

void Avl::Print()
{
    int h;

    for(h = 0; h <= root->Height() ; h++){
        cout << "|";
        Print_avl(root, h);
        cout << endl;
    }
}

void Avl::Print_t()
{
    int h;
    double p;

    for(h = 0; h <= root->Height() ; h++){
        p = (pow(2,(root->Height() - h)) - 1);
        Print_avl(root, h,p);
        cout << endl;
    }
}

void Avl::Print_b()
{
    int h;
    double p;

    for(h = 0; h <= root->Height() ; h++){
        p = (pow(2,(root->Height() - h)) - 1);
        Print_avl_2(root, h,p);
        cout << endl;
    }
}

void Avl::Print_avl(Nodet * node, int height)
{
    if(node == NULL) cout << " - |";

    else{
        if(height == 0){
            double p = floor(log10(node->Getinfo()));
            for(;p < 2; p++)cout << " ";
            cout << node->Getinfo();
            cout << "|";
        }

        else{
            height--;
            Print_avl(node->Getleft(),height);
            Print_avl(node->Getright(),height);
        }
    }
}

void Avl::Print_avl(Nodet * node, int height,double p)
{
    int i;
    if(node == NULL){
        if(height == 0){
            for(i = 0;i < p; i++)cout << " ";
            cout << "x ";
            for(i = 0;i < p; i++)cout << " ";
        }
        else cout << "x x ";
    }
    else{
        if(height == 0){
            for(i = 0;i < p; i++)cout << " ";
            cout << "o ";
            for(i = 0;i < p; i++)cout << " ";
        }
        else{
            height--;
            Print_avl(node->Getleft(),height,p);
            Print_avl(node->Getright(),height,p);
        }
    }

}

void Avl::Print_avl_2(Nodet * node, int height,double p)
{
    int i;
    if(node == NULL){
        if(height == 0){
            for(i = 0;i < p; i++)cout << " ";
            cout << "x ";
            for(i = 0;i < p; i++)cout << " ";
        }
        else cout << "x x ";
    }
    else{
        if(height == 0){
            if(node->Balance() >= 0 && p > 0)cout << " ";
            for(i = 1;i < p; i++)cout << " ";
            cout << node->Balance() << " ";
            for(i = 0;i < p; i++)cout << " ";
        }
        else{
            height--;
            Print_avl_2(node->Getleft(),height,p);
            Print_avl_2(node->Getright(),height,p);
        }
    }

}

void Avl::Hard_balance()
{
    Hard_balance(root);
}

void Avl::Hard_balance(Nodet * node){

    if(node->Height() > 2){
        Nodet * neo = new Nodet(node->Getinfo());

        Hard_balance(node->Getleft());
        Hard_balance(node->Getright());

        int b = node->Balance();

        Delete_balance(node, b);
        Insert_balance(node, neo, b);
    }

}


void Avl::Delete_balance(Nodet * to_delete, int b){

    Nodet * aux;
    int info;

    switch (b) {
        case -1:
            aux = to_delete->Min_of_max();
            info = aux->Getinfo();
            Delete(aux);
            Hard_balance(to_delete->Getright());
            break;
        case 1:
            aux = to_delete->Max_of_min();
            info = aux->Getinfo();
            Delete(aux);
            Hard_balance(to_delete->Getleft());
            break;
        default:
            return;
    }


    to_delete->Setinfo(info);

}

void Avl::Insert_balance(Nodet * root,Nodet * neo, int b)
{
    Nodet * aux;

    switch (b) {
        case -1:
            aux = root->Max_of_min();
            aux->Setright(neo);
            neo->Setfather(aux);
            Balance_tree(aux);
            Hard_balance(root->Getleft());
            break;
        case 1:
            aux = root->Min_of_max();
            aux->Setleft(neo);
            neo->Setfather(aux);
            Balance_tree(aux);
            Hard_balance(root->Getright());
            break;
        default:
            return;
    }


}

//HMA methods

int Avl::Take(){

    int to_take = root->Min()->Getinfo();

    Delete(to_take);

    return to_take;
}

bool Avl::Is_free()
{
    if(root == NULL) return true;

    else if(root->Getleft() == NULL
            or root->Getright() == NULL) return true;

    else return false;
}

bool Avl::Is_empty()
{
    if(root == NULL) return true;
    else return false;
}

int Avl::Height()
{
    if (root == NULL) return 0;
    else return root->Height();
}
