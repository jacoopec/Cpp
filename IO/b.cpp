#include "../CHeaders.h"



int main(){
    int result;
    const char* path = "text3.txt";
    char *phrase = "mit skifahren";
    FILE *f = fopen(path, "w");
    int c, i =0;
    printf("writing:\n");
    printf("%c",fputs(phrase,f));
 
    fclose(f);
}