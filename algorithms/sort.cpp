int main{
             std::vector<int> vals = {1,4,73,5,8,4,426,7,356,234,845,72};
         std::sort(vals.begin(),vals.end(), [](int a, int b){ return a < b;});
         for(int v : vals){
            std::cout << v << " ";
         }
}