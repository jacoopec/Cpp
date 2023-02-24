
int main(){
           std::vector<std::string> uno = {"io", "tu", "lei", "lei", "lei"};
        std::vector<std::string> due = {"io", "noi", "tu", "egli", "voi", "loro", "lei"};
 
        std::vector<std::string> tre = unique_names(uno, due);
        std::cout << uno.size() << " " << due.size() << std::endl;
        for(std::string g : tre){
            std::cout << g << std::endl;
        } 
}