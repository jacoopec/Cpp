//iterators in custom data structure
//the data is heap allocated, ad un certo punto si raggiunge un limite nel poter allocare nuova memoria.
//
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

struct Timer{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << duration.count() << std::endl;
    }
};

void tryTimer(){
    Timer timer;
    double result = 0;
    for(int i = 0; i< 100000; i++){
        result = result + i + i*100 + i/ 4;
    }
}

template<typename T>
class Vector{
    T* m_Data = nullptr;
    size_t m_size = 0;
    size_t m_Capacity = 0;

    void ReAlloc(size_t nexCapacity){
        T* newBlock = new T[newCapacity];

        size_t size = m_size;
        if(newCapacity < size)
            size = newCapacity;

        for (size_t i = 0; i < m_size; i++){
            newBlock[i] = m_Data[i];
        }
        delete[] = m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }


    public:
        Vector(){}
        
        Vector(float scalar)
            : x(scalar), y(scalar), z(scalar) {}

        Vector(float x, float y, float z)
            : x(x), y(y), z(z) {}

        Vector(const Vector& other)
            : x(other.x), y(other.y), z(other.z){std::cout << "Copy";}

        Vector(Vector&& other)
            : x(other.x), y(other.y), z(other.z) {std::cout << "Move";}

        ~Vector(){
            Clear();
        }

        void PushBack(const T& value){
            if(m_size >= m_Capacity){
                ReAlloc(m_Capacity + m_Capacity/2 );
            }
            m_Data[m_size] = value;
            m_size++;
        }

        const T& operator[](size_t index) const{
            if(index >= m_size)
            return m_data[index];
        }

        T& operator[](size_t index) const{
            if(index >= m_size)
            return m_data[index];
        }

        size_t Size() const {return m_Size;}

        void Print(const Vector<T>& vector){
            for(size_t i = 0; i < vector.Size(); i++){
                std::cout << vector[i] << std::endl;
            }
            std::cout << "---------------\n";
        }
};



int main(){
    /////////////////////////
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count();
    ///////////////////////
    Vector<std::string> vector;
    vector.PushBack("io");
    vector.PushBack("tu");
    vector.PushBack("lei");
}