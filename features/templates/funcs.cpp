#include "funcs.h"

std::tuple<std::string, int> createPerson(){
    return {"idjoc", 32};
}

std::optional<std::string> readFile(const std::string& filepath) {
    std::ifstream stream(filepath);
    if(stream){
        std::string result;
        stream.close();
        return result;
    }
    return {};
}

std::vector<std::string> unique_names(std::vector<std::string> uno,std::vector<std::string> due){
    std::vector<std::string> res;
    bool presence;
    int copies = 0;
    

    for(std::vector<std::string>::iterator it = uno.begin(); it != uno.end(); it++ ){
        for(std::vector<std::string>::iterator itr = res.begin(); itr != res.end(); itr++){
            if(*it == *itr){ presence = true;  break;}
            else continue;
        }
        if(presence){presence = false; copies++; std::cout << " copy: " << *it; continue;}
        else{ res.emplace_back(*it); }
    }
    for(std::vector<std::string>::iterator it = due.begin(); it != due.end(); it++){
        for(std::vector<std::string>::iterator itr = res.begin(); itr != res.end(); itr++){
            if(*it == *itr){ presence = true; break;}
            else continue;
        }
        if(presence){presence = false; copies++; continue;}
        else{ res.emplace_back(*it); }
    }
    std::cout << "Copies " << copies << std::endl;
    return res;
}


std::pair<double,double> findRoots(double a, double b, double c){
    std::pair<double, double> roots;
    double d = -b/(2*a);
    double e = sqrt(((b*b)-(4*a*c)));
    roots.first = (d + e)/(2*a);
    roots.second = (d - e)/(2*a);
    return roots;

}


void frienFunctionCat(Cat& c){
    std::cout << "This is a friend function that prints private cat informations: " << c.year << " " << c.name  << std::endl;
}

template<class T>
T add(T a, T b){
    return a+b;
}

template<class U, class I>
U smaller(U a, I b){
    return (a<b?a:b);
}


//littlechange
