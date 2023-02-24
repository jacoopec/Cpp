

void function1(){
    for(int i = 0; i< 100; i++){
        std::cout << "*\n";
    }
}

void function2(){
    for(int i = 0; i< 100; i++){
        std::cout << "#\n";
    }
}
int main(){
    std::thread work1(function1);
    std::thread work2(function2);
    work1.join();
    work2.join();
    system("pause>nul");
}