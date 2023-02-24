 int main(){

 
        std::cout << "Playing with lambdas" << std::endl;
        std::cout << [](int a, int b){ return a + b;} << std::endl;
        std::cout << f3([](){return 1;}) << std::endl;
 }