int main(){

     std::ifstream f("datain.txt");
        int vin[3];
        for(int i = 0;i < 7; i++){
            f >> vin[0] >> vin[1] >> vin[2];
            std::cout << vin[0] << " " << vin[1] << " " << vin[2] << "\n" << std::endl;
        }
}