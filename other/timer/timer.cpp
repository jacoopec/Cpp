class Timer{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;
    public:
        Timer(){ 
            std::time_t now = time(0);
            const char* dt = std::ctime(&now);
            std::cout << "Local time: " <<  dt;
            start = std::chrono::high_resolution_clock::now();
        }   
        ~Timer(){ 
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "Duration: " << duration.count();
        }
};