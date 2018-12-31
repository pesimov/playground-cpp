//
//  main.cpp
//  HW_modulus
//
//  Created on 30.12.18.
//

#include <iostream>
#include <vector>

#include "question1.hpp"
#include "question2.hpp"
#include "question3.hpp"
#include "question4.hpp"
#include "question5.hpp"
#include "question6.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello. This is modulus HW command line options. Select choice for HW option or type 'e' to exit.\n";
    char hwOption = 0;
    
    do{

    std:cin >> hwOption;
    
    switch(hwOption){
        case '1':
        hw1_array();
        break;
            
        case '2':
        hw2_add();
        break;

        case '3':
        hw3_sub();
        break;
            
        case '4':
        hw4_mult();
        break;

        case '5':
        hw5_mult_array_to_one();
        break;

        case '6':
        hw6_reciprocal();
        break;
            
        case 'e':
        std::cout << "Exiting";
        exit(0);
        break;
            
        default:
            std::cout <<"Incorrect option. ";
    }
    }while (hwOption != 'e');
    
    return 0;
}
