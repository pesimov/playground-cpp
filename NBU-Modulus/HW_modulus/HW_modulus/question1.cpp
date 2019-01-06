//
//  question1.cpp
//  HW_modulus
//
//  Created on 30.12.18.
//

#include "question1.hpp"
//create array of ring
//example: input:3, array is: 0,1,2
//example: input:7, array is 0,1,2,3,4,5,6

std::vector<int> fillRingValues(int n){
    std::vector<int> ringValues(n);
    //https://stackoverflow.com/questions/15013077/arrayn-vs-array10-initializing-array-with-variable-vs-real-number
    // Use of vector-array instead of dynamically sized manually allocated array.
    for(int i=0; i<n; i++){
        ringValues[i] = i;
    }
    return ringValues;
}

void hw1_array(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    std::vector<int> ringValues= fillRingValues(n) ;
    
    //print values
    for(int i=0; i<n; i++){
        std::cout << ringValues[i] << "\n";
    }
    
}
