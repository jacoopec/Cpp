//con i vectors si può usare l'index operator ma con altre data structures come i sets no perchp non contengono gli elementi in ordine
//gli iterator vengono usati per iterare una collezione di elementi,


#include <iostream>
#include <vector>
#include <unordered_map>

int main(){
    std::vector<int> vals = {1,2,3,4};
    int a;
    std::cin >> a;

    if(a == 1){
    //per stampare i valori si può usare un for loop
    for(int i = 0; i < vals.size(); i++){
        std::cout << vals[i] << std::endl;
    }

//range based for loops:
    for (int val: vals){
        std::cout << vals[val] << std::endl;
    }
//come lavora questo? usa un iterator, la classe vector fornisce due funzioni: begin e end, che restituiscono un iterator
//in una specifica posizione.
    for(std::vector<int>::iterator it = vals.begin(); it != vals.end(); it++){
        std::cout << *it << std::endl;
    }

//per alcuni data type gli iterators sono obbligatori, perchè non c'è un sistema di indexing semplice, perchè
//non sono dei semplici array ordinati. ad esempio in una map unordered per poter stampare i valori contenuti occorrerebbe conoscere tutte le chiavi.
//questo può essere evitato con gli iterators.
    }
    if(a == 2){
        std::unordered_map<std::string, int> map;
        map["babbeo"] = 5;
        map["babbuino"] = 2;
        map["babbino"] = 1;

    //const iterator non modifica i valori
        for(std::unordered_map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++){
            auto& key = it->first;
            auto& value = it->second;
            std::cout << key << " = " << value << std::endl;
        }

        for(auto kv : map){
            auto& key = kv.first;
            auto& value = kv.second;
            std::cout << key << " = " << value << std::endl;
        }
        //structure binding
        for(auto [key, value] : map){
            std::cout << key << " = " << value << std::endl;
        }

    }
}