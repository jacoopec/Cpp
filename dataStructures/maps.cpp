//hashmap, hastable, associative array are data structures that allow to associate some key to a value
//con l'id si possono trovare i dati a vector uses an integer indexing system.
//quindi hanno un ordine, all'interno di questo array
//con le map si può definire la key
//nella maps sorted tuttu gli elementi sono in ordine,  self balancing binary search tree
//unordered map è un hash table, usa una hash function per hashare la key
//cercare un elemento all'interno di un vector può richiedere molto tempo, perchè il valore cercato
//potrebbe essere anche l'ultimo.
//qualsiasi cosa si utilizzi come key, deve essere hasable nel caso dell'unordered map 
//C++ non sa come hashare un tipo custom come CityRecord, occorre fornire una hash function



#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

struct CityRecord{
    std::string name;
    uint64_t Population;
    double Lat, Lon;
};
//template specialization fro the hash class that is specialized with the type that is our key.
namespace std{
    template<>
    struct hash<CityRecord>{
        size_t operator()(const CityRecord& key){
            return hash<std::string>()(key.name);
        }
    };
};


int main(){
    // std::vector<CityRecord> cities;
    // cities.emplace_back("Parma", 3200239, 3.4, 4.2);
    // cities.emplace_back("Bologna", 437458, 5.3, 5.3);
    // cities.emplace_back("Piacenza", 37246, 9.5, 8.3);
    // cities.emplace_back("Modena", 54453, 3.7, 3.4);

    // for (const auto& city : cities)
    // {
    //     if(city.name == "Parma"){
    //         std::cout << (city.Population) << std::endl;
    //     }
    // }

    std::map<std::string, CityRecord> cityMap;
    cityMap["Parma"] =    CityRecord{"Parma", 3200239, 3.4, 4.2 };
    cityMap["Piacenza"] = CityRecord{"Piacenza", 37246, 9.5, 8.3};
    cityMap["Modena"] =   CityRecord{"Modena", 54453, 3.7, 3.4  };
    cityMap["Bologna"] =  CityRecord{"Bologna", 437458, 5.3, 5.3};

    //invece del ciclo for, qui semplicemente si può scrivere:
    CityRecord& berlindata = cityMap["Berlin"];

    ////////////////////////////////////////////////
    std::unordered_map<CityRecord, uint32_t> foundedMap;


}