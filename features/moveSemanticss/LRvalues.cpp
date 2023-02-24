#include "../cppHeaders.h"

//you can't take an L value ref from an R value, only of an L value
int getRVal(){
    return 10;  //questa funzione ritorna un R value, un temporary value, non ha location o storage.
}

int& getLVal(){
    static int val = 10;
    return val;  //questa funzione ritorna un L value reference
}

void setVal(int val){
    return;
}

void Print(std::string s){
    std::cout << s << std::endl;
}

//const references are compatible both with R and L values
void Print2(const std::string& s){
    std::cout << s << std::endl;
}

//questa funzione accetta solo temporary objects
// && è una r value reference
void Print3(const std::string&& s){
    std::cout << s << std::endl;
}

//temporary objects provide different advantages, we don't have to keep them alive, copy it.

int main(){
    int y = 10; // 10 è R value non ha storage o location, y, L è un value e ha una location, uno storage
    //un R value può essere assegnato ad un L value perchè L value 
    int u = getRVal();
    getLVal() = 3;
    setVal(y); //viene chiamata con un L value
    setVal(4); //viene chiamata con un R value
    std::string first = "nome";
    std::string last = "cognome";
    std::string nomeCompleto = first + last;
    Print(first);         //l'argomento apssato è un L value
    Print2(first + last); //l'argomento passato è un R value
    Print3(first + last);


}