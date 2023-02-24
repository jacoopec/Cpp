#include "../cppHeaders.h"

void mergeSort( int right, int left, std::array<int,22> array){
    if(right > left){
        int middle = (left + right)/2;
        mergeSort(left, middle, array);
        mergeSort(middle+1, right, array);
        std::array<int,11> lefty;
        std::array<int,11> righty;
        int iMain = 0;
        int iLeft = 0;
        int iRight = 0;
        while(iMain < array.size()/2){
            lefty[iMain]  = array[iMain];
            righty[iMain]  = array[iMain+ array.size()/2];
            iMain++;
    }
    }
}

std::vector<int> mergeSort(int right, int left, std::vector<int> v){
    while(v.size() != 1){
        std::vector<int> lefty[v.size()/2];
        std::vector<int> righty[v.size()/2];
        int iMain = 0;
        int iLeft = 0;
        int iRight = 0;

        while(iMain < v.size()/2){
            lefty->emplace_back(v[iMain]);
            righty->emplace_back(v[iMain+ v.size()/2]);
            iMain++;
        }
        iMain = 0;
        v.shrink_to_fit();
        for(; iMain < v.size() || iLeft < lefty->size() || iRight < righty->size(); iMain++){
            if(lefty[iLeft] < righty[iRight]){
                array[iMain] = lefty[iLeft];
                iLeft++;
                iMain++; 
            } else {
                array[iMain] = righty[iRight];
                iRight++;
                iMain++;
            }
        }
    }
}

void merge(int left, int middle, int right,std::vector<int> array){
    std::array<int,11> lefty;
    std::array<int,11> righty;
    int iMain = 0;
    int iLeft = 0;
    int iRight = 0;
    while(iMain < array.size()/2){
        lefty[iMain]  = array[iMain];
        righty[iMain]  = array[iMain+ array.size()/2];
        iMain++;
    }
    // for(int i = 0; i < array.size()/2; i++){
    //     printf("%i \n", lefty[i]);
    // }
    // printf("\n");
    // for(int i = 0; i < array.size()/2; i++){
    //     printf("%i \n", righty[i]);
    // }
    // printf("\n");
    iMain = 0;
    for(; iMain < array.size() || iLeft < lefty.size() || iRight < righty.size(); iMain++){
        if(lefty[iLeft] < righty[iRight]){
            array[iMain] = lefty[iLeft];
            iLeft++;
            iMain++;
        } else {
            array[iMain] = righty[iRight];
            iRight++;
            iMain++;
        }
    }
}