#include "cppHeaders.h"
//iterators are used to iterate over a collection of elements. Iterating over data structures.

int main(){
    std::vector<int> vals = {0,1,2,3,4,5,6,7,8,9};
    for(std::vector<int>::iterator i = vals.end()-1; i != vals.begin(); i--){
        std::cout << *i << std::endl;
    }

    std::unordered_map<std::string,int> map;
    map["albero"] = 1;
    map["ccasa"] = 2;

    for(std::unordered_map<std::string,int>::const_iterator c = map.begin(); c != map.end(); c++){
        auto& key = c->first;
        auto& value = c->second;
        std::cout << key << " = " << value << std::endl; 
    }

    //using structure bindings
    for(auto [key, value] : map){
        std::cout << key << " = " << value << std::endl; 
    }

}