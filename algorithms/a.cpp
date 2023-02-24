#include <iostream>
#include <chrono>
#include <vector>
#include <string>


std::vector<int> bubbleSort(std::vector<int> vec1){
    std::cout << "Bubble sort"  << std::endl;

    std::vector<int> vec2;
    bool found = false;
    int i = 0;
    int store = 0;
    int counter = 0;

    while(!found){
        counter++;
        if(vec1[i] > vec1[i+1]){
            std::cout << "vec[i]: " << vec1[i] << " vec[i+1]: " << vec1[i+1] << " i: " << i << std::endl;
            int store = vec1[i];
            vec1[i] = vec1[i+1];
            vec1[i+1] = store;
            std::cout << "Swappity swap." << std::endl;
            if(i > 0){
            i = 0;
            }
        } else if(i == vec1.size()){
            found = true;
            std::cout << "Ops number:" << counter << std::endl;
        } else {
            i++;
        }
    }
    return vec1;
}


std::vector<int> selectionSort(std::vector<int> vec1){
    std::cout << "Selection sort"  << std::endl;

    std::vector<int> vec2;

    for(int counter = 0; counter < vec1.size(); counter++){
        int minIndex = counter;
        std::cout << "Counter: "  << counter << " Minimo: " << minIndex << std::endl;
        for(int travIndex = counter + 1; travIndex < (vec1.size()-1); travIndex++){
            std::cout << "Traversing: "  << travIndex << " Minimo: " << minIndex << std::endl;
            if(vec1[minIndex] > vec1[travIndex]){
                std::cout << "Swapping" << std::endl;
                minIndex = travIndex;
            } else { 
                std::cout << "Continue" << std::endl;
            }
        }
        std::cout << std::endl;
        vec2.emplace_back(vec1[minIndex]); 
    }

    return vec2;
}


int binarySearch(std::vector<int> vec1, int elem){
    std::cout << "Binary search"  << std::endl;
    int store;
    int i = vec1.size()/2, counter = 0;
    bool found = false;

    while(found == false){
        counter++;
  
        if(vec1[i] > elem){
            i = i/2;
            std::cout << "Too small: " << i << " " << vec1[i] << std::endl;
        } else if (vec1[i] < elem){
            i = (vec1.size()-i)/2;
            std::cout << "Too big" << i << " " << vec1[i] << std::endl;
        } else if(vec1[i] == elem){ 
            found = true;
            std::cout << "Finish, number of operations: " << counter << "Fuond at: " << i << " "<< vec1[i] << std::endl;}
    }

    return i;
}


int main(){
    std::vector<int> vec1 = {54,73,45,24,66,42,1,6,5,73,3};
    std::vector<int> vec2 = {1,2,3,4,5,6,7,8,9,10,11};
    std::vector<int> vec3;
    std::chrono::duration<double> durInserTime(0);

    auto tp1 = std::chrono::high_resolution_clock::now();

    int y = binarySearch(vec2, 3);
    vec3 = selectionSort(vec1);

    for(auto& elem : vec3){
        std::cout << elem << std::endl;
    }

    vec3 = bubbleSort(vec1);

    for(auto& elem : vec3){
        std::cout << elem << std::endl;
    }
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInserTime = tp1 - tp2;
    std::cout << "Duration: "  << std::chrono::duration_cast<std::chrono::microseconds>(durInserTime).count() << std::endl;

}