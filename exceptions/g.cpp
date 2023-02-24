#include "../IOSTREAM/includes.h"
//ncjodijsoi

class House{
    int doors;
    std::string name;
};

int main(){
    std::cout<< "1.string\n" << "2.int\n" << "3.double\n" << "4.char\n" << "5.house\n"; 
    int vaar;
    std::cin >> vaar;
    try{
        if(vaar == 1){
            std::string str{"sijo"};
            throw str;
        }
        else if(vaar == 2){
            throw 1;
        }
        else if(vaar == 3){
            throw 5.6;
        }
        else if(vaar == 4){
            throw 'i';
        }
        else if(vaar == 5){
            House h;
            throw h;
        }
    } catch (std::string str){
        std::cerr <<" string exception";
    }catch (int i){
        std::cerr <<" int exception";
    }catch (double d){
        std::cerr <<" double exception";
    }catch (char c){
        std::cerr <<" char exception";
    }catch (const House&){
        std::cerr <<" House exception";
    }
}