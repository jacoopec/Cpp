#include "../headers.h"

struct NodeS{
    int _value = 0;
    NodeS* _next = nullptr;
    NodeS(int value) : _value(value){};
    NodeS(){};
};

struct NodeD{
    int _value;
    NodeD* _next;
    NodeD* _previous;
    NodeD(int value, NodeD* next, NodeD* previous) : _value(value), _next(next), _previous(previous){}
    NodeD(){}
};

struct SinglyList{
    int elements = 0;
    NodeS* head = nullptr;
    NodeS* tail = nullptr;


    void appendNode(NodeS& node, int position){
        if(isEmpty()){
            head = tail = &node;  
            node._next = nullptr;
            elements++;
        } else if (position == 0 && !isEmpty()){
            node._next= head;
            head = &node;
            elements++;
        } else if (position == elements){

            tail = &node;
            node._next = nullptr;
        }
            {

            elements++;
        }
    }

    // void clear(){
    //     Node* trav = head;
    //     while(trav != nullptr){
    //         Node* next = trav._next;
    //         trav->_previous
    //     }
        // head = tail = nullptr;
    // }
    const int size() const {
        return elements;
    }

    bool isEmpty() const{
        if(elements == 0){
            return true;
        }
        return false;
    }

};

// struct doublyList{
//     Node list[10];
//     int elements = 0;
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     void addNode(Node node){
//         if(isEmpty()){
//             head = tail = nullptr;
//             list[0] = node;    
//         } else{
//             list[elements] = node;
//             elements++;
//         }
//     }

    // void clear(){
    //     Node* trav = head;
    //     while(trav != nullptr){
    //         Node* next = trav._next;
    //         trav->_previous
    //     }
        // head = tail = nullptr;
    // }
//     const int size() const {
//         return elements;
//     }

//     bool isEmpty() const{
//         if(elements == 0){
//             return true;
//         }
//         return false;
//     }
// };



void listIterator(NodeS* trav){
    while(trav != nullptr){
        std::cout << (*trav)._value << " next:" << (*trav)._next << std::endl;
        trav = (*trav)._next;
    }
}


struct Stack{
    NodeS* head = nullptr;
    int size = 0;
    void push(NodeS& elem){
        head = &elem;
        elem._next = nullptr;
    }
    bool isEmpty(){
        if(size == 0){
            return true;
        }
        return false;
    }
    void pop(){
        if(!isEmpty()){
            NodeS* tmp = head;
            head = (*head)._next;
            tmp = nullptr;
        }
        return;
    }
};


int main(){
    NodeS a(1);
    NodeS b(2);
    NodeS c(3);

    SinglyList list;
    Stack s;
    list.appendNode(a,1);
    list.appendNode(b,2);
    list.appendNode(c,3);
    s.push(a);
    s.push(b);
    s.push(c);
    listIterator(&a);
    s.pop();
    listIterator(&a);
}