#include "cppHeaders.h"

//se il file 
std::optional<std::string> readFilAsString(const std::string& filePath, bool& outSuccess){
    std::ifstream stream(filePath);
    if(stream){
        std::string result;
        stream.close();
        outSuccess = true;
        return result;
    }
    outSuccess = false;
    return {};  //returning empty optional
}

int main(){
    bool fileOpenedSuccessfully;
    std::optional<std::string> data = readFilAsString("data.txt", fileOpenedSuccessfully);
    std::string val = data.value_or("not present");
    if(data){
        std::cout << "File read.\n";
    }
}