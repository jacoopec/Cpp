#include "../headers.h"

struct Node{
    Node* _left = nullptr;
    Node* _right = nullptr;
    int _data = 0;
    Node(Node* left, Node* right, int data) : _left(left), _right(right), _data(data){}
    Node(){}
};


void depthFirstReversalIterative(std::vector<Node> vec){
    std::stack<Node> s;
    Node visited;
    s.push(vec[0]);
    while(!s.empty()){
        visited = s.top();
        s.pop();
        std::cout << visited._data << " visited. Sons: " << std::endl;
        if(visited._right != nullptr){
            s.push(*(visited._right));
        }
        if((visited._left != nullptr )){
            s.push(*(visited._left));
        }
    }
}

void depthFirstReversalRecursive(std::vector<Node> vec){
    std::stack<Node> s;
    Node visited;
    s.push(vec[0]);
    while(!s.empty()){
        visited = s.top();
        s.pop();
        std::cout << visited._data << " visited. Sons: " << std::endl;
        if(visited._right != nullptr){
            s.push(*(visited._right));
        }
        if((visited._left != nullptr )){
            s.push(*(visited._left));
        }
    }
}

void BreathFirstValuesRecursive(Node n, std::queue<Node>& q){
    std::cout << "BreathFirstValues" << std::endl;
    q.emplace(n);
    if(n._left != nullptr){
        BreathFirstValuesRecursive(*(n._left),q);
    }
    if(n._right != nullptr){
        BreathFirstValuesRecursive(*(n._right),q);
    }
    return;
}

void BreathFirstValues(Node n, std::queue<Node>& q){
    std::cout << "BreathFirstValues" << std::endl;
    q.emplace(n);
    Node current;
    while(!q.empty()){
        current = q.front();
        std::cout << "Current: " << current._data << "Popping" << std::endl;
        q.pop();
        if(current._left != nullptr){
            std::cout << "Emplacing: " << (current._left)->_data << std::endl;
            q.emplace(*(current._left));
        }
        if(n._right != nullptr){
            std::cout << "Emplacing: " << (current._right)->_data << std::endl;
            q.emplace(*(current._right));
        }
    }
    return;
}




void something(std::vector<Node>& tree){
    int sum = 0;
    int i = tree.size();
    sum += tree[i]._data;
    i--;
    something(tree);
}

int main(){
    Node g(nullptr, nullptr, 7);
    Node f(nullptr, nullptr, 6);
    Node e(nullptr, nullptr, 5);
    Node d(nullptr, nullptr, 4);
    Node c(&f, &g, 3);
    Node b(&d, &e, 2);
    Node a(&b, &c, 1);
    std::vector<Node> tree = {a,b,c,d,e,f,g};
    std::queue<Node> q;
    // depthFirstReversalIterative(tree);    //funziona
    // BreathFirstValuesRecursive(tree[0], q);
    BreathFirstValues(tree[0], q);


    std::cout << "Size: " <<q.size() << std::endl;
    // q.emplace(a);
    // q.emplace(b);
    while( q.size() != 0){
        std::cout << "back: " << q.back()._data << " front: " << q.front()._data << std::endl;
        q.pop();
    }
}