#include "../cppheaders.h"
#include "../cheaders.h"

int comp_int(const void *, const void *);


struct vector{  
    size_t size_;
    size_t capacity_;
    int *data_;
    //the methods are not inside the obj. there is no ptr to the function.
    vector(){  //default constructor
        size_ = capacity_ = 0;
        data_ = NULL;
    }
    vector(const vector& v){ //copy constructor, deep copy
        puts("Copy constructor");
        size_ = v.size_;
        capacity_ = v.capacity_;
        data_ = (int*)malloc(sizeof(int));
        // for(size_t i = 0; i < size_; ++i){
        //     data_[i] = v.data_[i];
        // }
        memcpy(data_, v.data_, size_);
    }
    vector(const vector& other){
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = (int*)malloc(capacity_*sizeof(int));
        for(size_t i = 0; i < size_; ++i){
            data_[i] = other.data_[i];
        }
    }
    ~vector(){
        free(data_);
        
    }
    void shrink_to_fit(){
        capacity_ = size_;
        data_ = (int*)realloc(data_, capacity_*sizeof(int));
    }
    size_t size() const{
        return size_;
    }

    int *data(){
        return data_;
    }


    void push_back(int val){
        this->size_++;
        if(this->size_ > this->capacity_){
            this->capacity_ = this-> capacity_*2+1;
            this->data_ = (int*)realloc(this->data_, this->capacity_*sizeof(int));
        }
    }
    int at(size_t pos) const;
};

void sort(vector* v){
    qsort(v->data(), v->size(), sizeof(int), comp_int);
}

//this return a ptr to the obj itself becaus in this way we are able to passe this obj to another function.
int vector::at(size_t pos) const {
    assert(pos < this->size_);  //this must be true, if it false the program will be stopped.
    return this->data_[pos];
}


vector* new_vector(void){
    vector* v = (vector*)malloc(sizeof(vector));
    vector(v);
    return v;
}

int comp_int(const void *va, const void  *vb){
    const int *a = (int*)va;
    const int *b = (int*)vb;
    if(*a < *b){
        return -1;
    }
    else if(*a > *b){
        return 1;
    }
    else{return 0;}
    // return(*a > *b) - (*a < *b);
}


bool write(const char* filename,vector *v){
    FILE *fout = fopen(filename,"w");
    if(fout == NULL){
        return false;
    }

    for(size_t i = 0; i < v->size(); ++i){
        fprintf(fout, "%d\n",v->at(i));
    }

    fclose(fout);
    return true;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        return EXIT_FAILURE;
    }

    vector *v = new vector();

    FILE *f = fopen(argv[1], "r");  // 0x0d 0x0a becomes ox0a
    if(f == NULL){
        printf("fail to read");
        return EXIT_FAILURE;
    }

    int *v = NULL;
    size_t size = 0;
    size_t capacity = 0;
    printf("start\n");

    int val;
    while( fscanf(f, "%d", &val) == 1){
        v->push_back(val);     
    }

    fclose(f);
    v->shrink_to_fit();
    sort(v);  //violating encapsulation


    write(argv[2],v);


    delete v;
    return EXIT_SUCCESS;
}