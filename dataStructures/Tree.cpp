#include "headers.h"

struct Node{
    char value;
    Node* left;
    Node* right;
    Node(){};
    Node( char value, Node* left, Node* right): value(value), left(left), right(right){}
};


int main(){
    Node n7('g',nullptr, nullptr);
    Node n6('f',nullptr, nullptr);
    Node n4('d',nullptr, nullptr);
    Node n5('e',nullptr, nullptr);
    Node n2('b', &n4, &n5);
    Node n3('c', &n6, &n7);
    Node n1('a', &n2, &n3);
    Node tree[7] = {n1,n2,n3,n4,n5,n6,n7};

    Node current;
    std::stack<Node> s; 
    s.push(tree[0]);
    for(int i = 0; i < 8; i++){
        if(i > 0 && ((current.right != nullptr) || (current.left != nullptr))){
            s.push(*current.right);
            s.push(*current.left);
        }
        if(!s.empty()){
            current = s.top();
            s.pop();
            std::cout << "visited " << current.value << std::endl;
        }

    }
}