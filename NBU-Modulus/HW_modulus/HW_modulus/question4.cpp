//
//  question4.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question4.hpp"

int multModulus(int n, int x, int y){
    
    //add values before modulus operation;
    int mult = x * y;
    
    //apply modulus operation
    int multMod = mult % n;
    
    return multMod;
}

void hw4_mult(){
    std::cout << "Value for ring's n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    int x, y = 0;
    
    std::cout << "Value for the two values to multiply:\n";
    std::cin >> x;
    std::cin >> y;
    
    int answer = multModulus(n, x, y);
    //print
    std::cout << answer << "\n";
    
}
