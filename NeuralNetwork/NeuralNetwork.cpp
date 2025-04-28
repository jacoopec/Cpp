#include "NeuralNetwork.h"

double output[2]={2,10};

double sumE(double * input, double weights[], int size){
    double res = 0;
    double diff = 0;
    for(int j = 0; j < size; j++){
        diff = output[j]-linearNeuron(input,weights,size);
        res = res + (diff*diff);
    }
    return res;
}

double learningRate = 0.1;
double dw = learningRate * output[j]-linearNeuron(input,weights,size) * input[j];

double linearNeuron(double input[],double weights[], int size){
    double res;
    for(int i = 0; i < size; i++){
        res += input[i]*weights[i];
    }
    return res;
}

void train(double *input, int size, double weights[]){
    double error = 0.5 * sumE(input, size);
}

int main(){
    double weights[2]={1,1};
    double input[2]= {7,3};
    int size = 2;
    train(input, size,weights);


}