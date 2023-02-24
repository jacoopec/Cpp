#include <iostream>
#include <array>

template<typename T, size_t S>
class Array{
    int* m_Data;
    T m_Data2[S];
    public:
        int Size() const {return S;}
        Array(int size){
            m_Data = (int*)alloca(size);
        }

        T& operator[](int index){ return m_Data[index];}
};


int main(){
    int array[5];
    int* heapArray = new int[5];
    delete[] heapArray;
    std::array<int, 10> collection;
    std::cout << "Size: "  << collection.size() << std::endl;

    for(int arr : collection){
        std::cout << data[arr] << std::endl;
    }
}