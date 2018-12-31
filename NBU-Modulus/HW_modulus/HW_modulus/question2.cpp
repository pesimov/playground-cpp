//
//  question2.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question2.hpp"


int addModulus(int n, int x, int y){
    
    //add values before modulus operation;
    int add = x + y;
    
    //apply modulus operation
    int addMod = add % n;
    
    return addMod;
}

void hw2_add(){
    std::cout << "Value for ring's n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    int x, y = 0;
    
    std::cout << "Value for the two values to add:\n";
    std::cin >> x;
    std::cin >> y;
    
    int answer = addModulus(n, x, y);
    //print
    std::cout << answer << "\n";
    
}

