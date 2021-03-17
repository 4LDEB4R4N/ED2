#ifndef NODE_H
#define NODE_H


class Node
{
    private:
        int info;
        Node * next;

    public:
        Node(int info);
        virtual ~Node();

        int Getinfo() { return this->info; }
        void Setinfo(int neo_info) { this->info = neo_info; }
        Node * Getnext() { return this->next; }
        void Setnext(Node * neo_next) { this->next = neo_next; }

};

#endif // NODE_H
