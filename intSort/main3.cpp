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
    //how can we tell the compiler that the obj is dying and save to destroy? R value ref
    vector(vector&& other){   //move constructor
        size_ = other.size_;
        capacity_ = other.capacity_;
        // data_ = (int*)malloc(capacity_*sizeof(int));
        data_ = other.data_; //robbing the data
        other.data_ = nullptr;
    }

    void assign(const vector& rhs){
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        free(data_); //data_ was already pointing at something else we need to free it.
        data_ = (int*)malloc(capacity_*sizeof(int));
        for(size_t i = 0; i < size_; ++i){
            data_[i] = rhs.data_[i];
        }
    }
    vector& operator=(const vector& rhs){
        if(rhs.capacity_ > capacity_){
            capacity_ = rhs.capacity_;
            free(data_);
            data_ = (int*)malloc(capacity_*sizeof(int));
        }
        size_ = rhs.size_;
        for(size_t i = 0; i < size_; ++i){
            data_[i] = rhs.data_[i];
        }
        return *this;
    }

    ~vector(){
        free(data_);    
    }


    vector& operator=(vector&& rhs){  //move assignment operator
        delete[] data_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        data_ = rhs.data_;
        rhs.data_ = nullptr;
        return *this;
    }



    void shrink_to_fit(){
        capacity_ = size_;
        // data_ = (int*)realloc(data_, capacity_*sizeof(int));
        int *tmp = new int[capacity_];
            for(size_t i = 0; i < size_; ++i){
                tmp[i] = data_[i];
            }
        delete[] data_;
        data_ = tmp;
    }

    bool empty() const {

    }
    
    size_t size() const{
        return size_;
    }

    int *data(){
        return data_;
    }


    void push_back(int val){
        size_++;
        if(size_ > capacity_){
            capacity_ = capacity_*2+1;
            // data_ = (int*)realloc(data_, capacity_*sizeof(int));
            int *tmp = new int[capacity_];
            for(size_t i = 0; i < size_ - 1; ++i){
                tmp[i] = data_[i];
            }
            delete[] data_;
            data_ = tmp;
        }
        data_[size_-1] = val;
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

vector read(const char* filename){
    
    vector v;
    FILE *f = fopen(filename, "r");  // 0x0d 0x0a becomes ox0a
    if(f != NULL){
        int val;
        while( fscanf(f, "%d", &val) == 1){
            v.push_back(val);     
        }
        v.shrink_to_fit();
        fclose(f);
    }
    return v;
}

void swap(vector& a, vector& b){
    size_t tmp = a.size_;
    a.size_ = b.size_;
    b.size_ = tmp;
    size_t tmp_cap = a.capacity_;
    a.capacity_ = b.capacity_;
    b.capacity_ = tmp_cap;
    int * tmp_data = a.data_;
    a.data_ = b.data_;
    b.data_ = tmp_data;

}


int main(int argc, char *argv[]){
    if(argc != 3){
        return EXIT_FAILURE;
    }

    vector *v = new vector();
    *v = read(argv[1]);

    if(v->empty()){
        return EXIT_FAILURE;
    }


    sort(v);  //violating encapsulation


    write(argv[2],v);

    int x = 4; //initialization
    x = 9; //assignmetn
    //the equal operator in initialization has a different meaning during assignment

    vector uno;
    vector due;
    uno = due;
    uno = vector(due); //this assign a temporary obj to uno

    uno.assign(due);
    delete v;
    return EXIT_SUCCESS;
}