#ifndef FUNCS
#define FUNCS
#include <tuple>
#include <fstream>
#include <optional>
#include <variant>
#include <vector>
#include <iostream>
#include <any>
#include <map>
#include <string>
#include <unordered_map>
#include <math.h>
#include "Cat.h"

std::tuple<std::string, int> createPerson();
std::optional<std::string> readFile(const std::string& filepath);
std::vector<std::string> unique_names(std::vector<std::string> uno,std::vector<std::string> due);
std::pair<double,double> findRoots(double a, double b, double c);

template<class T>
T add(T a, T b);

template<class U, class I>
U smaller(U a, I b);


template <class T>
class Buck{
    T first, second;
    public:
        Buck(T a, T b){
            first = a;
            second = b;
        }
        T bigger();
};

template <class T>
T Buck<T>::bigger(){
    return(first>second?first:second);
}


template<class V>
class Cassetta{
    public:
        Cassetta(V x){
            std::cout << "Questa è una cassetta." << std::endl;
        }
};

template<>
class Cassetta<char>{
    public:
        Cassetta(char c){
            std::cout << "This is template specialization" << c << std::endl;
        }
}; 

//secondarychange
#endif