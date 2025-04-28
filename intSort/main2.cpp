#include "../cppheaders.h"


struct vector{  
    size_t size_;
    size_t capacity_;
    int *data_;
    vector(){  //default constructor
        size_ = capacity_ = 0;
        data_ = NULL;
    }
    vector(const vector& v){ //copy constructor, deep copy
        puts("Copy constructor");
        size_ = v.size_;
        capacity_ = v.capacity_;
        data_ = new int[capacity_];
        // for(size_t i = 0; i < size_; ++i){
        //     data_[i] = v.data_[i];
        // }
        memcpy(data_, v.data_, size_);
    }
    vector& operator=(const vector& rhs){
        if(rhs.capacity_ > capacity_){
            capacity_ = rhs.capacity_;
            delete[] data_;
            data_ = new int[capacity_];
        }
        size_ = rhs.size_;
        for(size_t i = 0; i < size_; ++i){
            data_[i] = rhs.data_[i];
        }
    }
    ~vector(){
        free(data_);
        
    }
    void vector_shrink_to_fit(){
        capacity_ = size_;
        int *tmp = new int[capacity_];
        for(size_t i = 0; i < size_ -1; ++i){
            tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = tmp;
    }

    size_t size(const vector* this) const{
        return size_;
    }

    int at(const vector* this, size_t pos) const {
        assert(pos < this->size_);  //this must be true, if it false the program will be stopped.
        return this->data_[pos];
    }

    void sort(vector* v){
        qsort(v->data(), (v), v->size(int), comp_int);
    }

    void vector_push_back(int val){
        size_++;
        if(size_ > capacity_){
            capacity_ = capacity_*2+1;
            // this->data_ = (int*)realloc(this->data_, this->capacity_*sizeof(int));
            int *tmp = new int[capacity_];
            for(size_t i = 0; i < size_ -1; ++i){
                tmp[i] = data_[i];
            }
            delete[] data_;
            data_ = tmp;
        }
    }
};

//this return a ptr to the obj itself becaus in this way we are able to passe this obj to another function.


vector* new_vector(void){
    vector* v = malloc(sizeof(vector));
    vector_constructor(v);
    return v;
}



//delete destructs and deallocate the obj, the destructor only deallocate
void delete_vector(vector* this){
    vector_destructor(v);
    free(this);
    //or free(vector_destructor(this))
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


bool write(const char* filename, const vector& v){
    FILE *fout = fopen(argv[2],"w");
    if(fout == NULL){
        return false;
    }

    for(size_t i = 0; i < v->size(); ++i){
        fprintf(fout, "%d\n",v->at(i));
    }

    fclose(fout);
    return true;
}

vector read(const char *filename){
     
    vector v;
    FILE *f = fopen(filename, "r");  // 0x0d 0x0a becomes ox0a
    if(f == NULL){
            while( fscanf(f, "%d", &val) == 1){
            //Read
            int val;
            //cheak if succefful
            //  %d is the specifier
            //fscanf returns the number of bytes read
            if(res != 1 ){
                break;
            }

            v->push_back(val);
            
            ++size;
            //use what read
            if(size > capacity){
                capacity*=(2+1);
                v = (int*)realloc(v, capacity*sizeof(int)); //reallocate space
            }
            printf("%i\n",*v);
            v[size-1] = val;
        }

        fclose(f);
        v->shrink_to_fit();
    }
    return v;

    int *v = NULL;
    size_t size = 0;
    size_t capacity = 0;
    printf("start\n");

   
}

int main(int argc, char *argv[]){
    if(argc != 3){
        return EXIT_FAILURE;
    }

    vector *v = new vector();
    v = read(argv[1]);


   
    qsort(v.data_, v.size, sizeof(int), comp_int);  //violating encapsulation

    write(argv[2], v);

    return EXIT_SUCCESS;
}