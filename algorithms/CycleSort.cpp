#include "../cppHeaders.h"


void cycleSort(std::array<int,22> array){
    int currentElement; //element that we are writign to its correct position index.
    int position; //correct position for the element in the sorted list
    int outerIndex = 0;
    while(currentElement != outerIndex){
        for(outerIndex = 0; outerIndex < array.size() - 2; outerIndex++){
            currentElement = array.at(outerIndex);
            position = outerIndex;
            for(int i = outerIndex+1;  i < array.size()-1; i++){
                if( array.at(i) < currentElement){
                    position++;
                }
            }
        }
        int temp = array.at(position);
        array.at(position) = currentElement;
        
    }
}
//FUNZIONA
void cycleSort2(size_t size,int array[]){
    bool ordered = false;
    int posShould = 0;
    int f = 0;
    int current = f;
    int tmp = 0;
    for(; f < size; f++){
        printf("f %i\n", f);
        ordered = false;
        while(!ordered){
            posShould = 0;
            for(int i = 0; i< size; i++){
                printf("array[i] %i <? %i\n", array[i], array[f]);
                if(array[i]< array[f]){
                    posShould++;
                }
            }
            printf("posShould %i \n", posShould);
            tmp = array[posShould];
            array[posShould] = array[f];
            array[f] = tmp;
            if( posShould == f){
                ordered = true;
                printf("Ciclo finito\n");
            }
            for(int i = 0; i < size; i++){
                printf("%i \n",array[i]);
            }
            printf("\n");
        }
    }
}
