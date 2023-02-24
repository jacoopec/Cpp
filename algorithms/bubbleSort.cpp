#include "../cppHeaders.h"

void bubbleSort(std::array<int,22> array){

    bool swapped = true; 
    int nop = 0;
    int traversing = 0;

    while(swapped){ 
        swapped = false;
        traversing = 0;
        for(;traversing< array.size(); traversing++){
            if(array[traversing] > array[traversing+1]){
                nop++;
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing + 1] = temp;
                swapped =true;
            }
        }



    }
        printf("Print\n");
        for(int i = 0; i < array.size(); i++){
            printf("%i \n", array[i]);
        }
        printf("\n");
    printf("Number of op %i",nop);
}

