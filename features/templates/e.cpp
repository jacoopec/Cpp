#include "../cppHeaders.h"
#include "../CHeaders.h"

template<typename T,size_t S>
class Array{
    T m_Data[S];
    public:
    constexpr int Size() const {return S;} //this function can be evaluated a compile time with the constexpr keyword
    T& operator[](int index){return m_Data[index];}
    T* Data(){return m_Data;}
    const T* Data(){return m_Data;}
};

int main(){
    Array<int, 5> data;
    for(size_t i = 0; i < data.Size(); i++){
        data[i] = 2;
    }
    // memset(data.Data(),0, data.Size()*sizeof(int));
    for(size_t i = 0; i < data.Size(); i++){
        std::cout << data[i] << std::endl;
    }


}