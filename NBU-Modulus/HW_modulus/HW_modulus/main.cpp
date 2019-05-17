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
#include "question7.hpp"
#include "question8.hpp"
#include "question9.hpp"
#include "question10.hpp"
#include "question11.hpp"
#include "question12.hpp"
#include "question13.hpp"
#include "question14.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello. This is modulus HW command line options. Select choice for HW option or type 'e' to exit.\n";
    char hwOption = '0';
    
    do{
        std::cout << "\n\n. Select choice for HW option or type 'e' to exit.\n";
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
            
        case '7':
        hw7_bezout_inverser_solution();
        break;
            
        case '8':
        hw8_delenie();
        break;
            
        case '9':
        hw9_power_first_method();
        break;
            
        case 'q'://10
        hw10_power_second_method();
        break;
            
        case 'w'://11
        hw11_check_prime();
        break;
            
        case 'r'://12
        hw12_check_set_root();
        break;
            
        case 't'://13
        hw13_find_all_primitive_roots();
        break;
            
        case 'y'://14
        hw14_discrete_logarithm();
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
