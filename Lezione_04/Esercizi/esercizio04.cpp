//c++ -o es4 `root-config --glibs --cflags` esercizio04.cpp
#include <iostream> 
#include "TH1F.h"
#include "TCanvas.h"

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

void rnd(){
    /*
        Updating the seed with LCG algorithm
    */
    seed_ = (A* seed_ + C)%M;
    return;
}

float rand_range(float min, float max){
    /*
        Updating the seed with LCG algorithm and scaling it in the required range [min, max]
    */
    rnd();
    return min + (max - min)*seed_ / static_cast<float> (M);
}

int main(){

    seed_ = 0; //setting global seed of the sequence
    float min = -3;
    float max = 3;
    
    TH1F histo ("histo", "prova", 5, min, max) ;
    
    for(int i =0; i < 10; ++i){
       float rand = rand_range(min, max);
       std::cout << rand << std::endl;
       histo.Fill (rand);
    }   
    
    TCanvas c1 ;
    histo.Draw () ;
    c1.Print ("histo.png", "png") ;


    return 0;
}
