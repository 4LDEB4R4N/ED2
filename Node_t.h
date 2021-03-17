#ifndef NODE_T_H
#define NODE_T_H


class Node_t
{
 private:
        Node_t * father;
        Node_t * left;
        Node_t * right;
 public:
        Node_t();
        virtual ~Node_t();

        Node_t * Getfather() { return father; }
        void Setfather(Node_t * node) { father = node; }
        Node_t * Getleft() { return left; }
        void Setleft(Node_t * node) { left = node; }
        Node_t * Getright() { return right; }
        void Setright(Node_t * node) { right = node; }


};

#endif // NODE_T_H
