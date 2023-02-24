 
 
int main(){

   std::unordered_map<std::string, int>map;
        map["casa"] = 0;
        map["finestra"] = 3;
        map["porta"] = 2;
        map["cancello"] = 1;
        for(std::unordered_map<std::string, int>::const_iterator it = map.begin();
            it != map.end(); it++){
            auto& key = it->first;
            auto& value = it->second;

            std::cout << key << " = " << value << std::endl;
        }

        for(auto kv : map){
            auto& key = kv.first;
            auto& value = kv.second;
        }

        for(auto [key, value] : map){
            std::cout << key << " = " << value << std::endl;
        }

} 