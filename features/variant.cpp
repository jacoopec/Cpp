        std::variant<std::string, int> data;
        data = "jioj";
        data = 2;
        if(auto value = std::get_if<std::string>(&data)){
            std::string& v = *value;
        } else {

        }
        data = 2;
        std::cout << std::get<std::string>(data) << std::get<int>(data);