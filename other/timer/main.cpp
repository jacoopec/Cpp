int main(){
    Timer t1;
        //1D
        int* ad = new int[3];
        ad[0] = 1;
        ad[1] = 2;
        ad[2] = 3;
        //
        int** a2d = new int*[3];  
        for(int i = 0; i< 3; i++){
            a2d[i] =  new int[3];
            for(int j = 0; j < 3; j++){
                
            }
        }
        a2d[0] = new int[3];
        a2d[1] = new int[3];
        a2d[2] = new int[3];
            //
            a2d[0][0] = 1;
            a2d[0][1] = 2;
            a2d[0][2] = 3;
            //
            a2d[1][0] = 4;
            a2d[1][1] = 5;
            a2d[1][2] = 6;
            //
            a2d[2][0] = 7;
            a2d[2][1] = 8;
            a2d[2][2] = 9;
}