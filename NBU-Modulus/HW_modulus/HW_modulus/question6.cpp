//
//  question6.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question6.hpp"
#include "question5.hpp"
//will use code from question 5

void hw6_reciprocal(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };

    int arrComb [n][2];
    fillArray(arrComb,n);
    // print all elements
    std::cout << "print all elements.";

    for (int r=0; r<n; r++){
        cout << "Reciprochnata stoinost na " <<arrComb[r][0] <<  " e " << arrComb[r][1];
        ////use *arrComb to get the value of the integer that the pointer arrComb is
        cout << "\n" ;
    }
    
    int in_recip = 0 ;
    std::cout << "\nInput value to find it reciprocal value inside the ring Z_n, with n=" << n << ".\n\n";
    std::cin >> in_recip;
    for (int r=0; r<n; r++){
        if(arrComb[r][0] == in_recip){//use *arrComb to get the value of the integer that the pointer arrComb is pointing at
            cout << "Reciprochnata stoinost na " <<arrComb[r][0] <<  " e " << arrComb[r][1];
        }
    }
    cout << "\n\n" ;
    
    //https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array
    //https://stackoverflow.com/questions/18940175/cannot-delete-stdvector-stdarray

}
