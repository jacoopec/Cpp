

int main(){
            std::optional<std::string> data = readFile("data.txt");
        std::string val = data.value_or("not present");
        std::optional<int> count;

        if(data){
            std::cout << " Read successfully";
        } else {
            std::cout << " Read failed";
        }
}