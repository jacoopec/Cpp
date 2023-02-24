int main(){
    
        char* buffer = new char[8];
        *buffer = 'e';
        char** dptr = &buffer;
        std::cout << "dptr" << *dptr << **dptr << std::endl;
        std::cout << "Allocated 8 bytes at: " << &buffer << "  " << &buffer + 1 << "  " << &buffer + 2 << "  " << &buffer + 3 <<  std::endl;
        memset(buffer, 'r', 8);
        std::cout << buffer;
        std::cout << "Deleting buffer" << std::endl;

        delete[] buffer;
        std::cout << "Buffer address: " << &buffer << "  " << buffer << std::endl;
}