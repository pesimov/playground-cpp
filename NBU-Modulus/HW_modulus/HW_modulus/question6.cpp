//
//  question6.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question6.hpp"

int* hw5_mult_vec_to_one(int n){
    
    //std::vector<int> multipleToOne;
    auto multipleToOneArray = new int [n][2]();
    for(int i=0; i<n; i++){
        multipleToOneArray[i][0]=i;
        multipleToOneArray[i][1]=-1;
    }
    //see https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    
    //https://stackoverflow.com/questions/15013077/arrayn-vs-array10-initializing-array-with-variable-vs-real-number
    // Use of vector-array instead of dynamically sized manually allocated array.
    // permits double-assignment
    for(int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            int modMultiple = (i * j) % n;
            
            if(modMultiple == 1){
                multipleToOneArray[i][0]=i;
                multipleToOneArray[i][1]=j;
                break;
                //multipleToOne.push_back(i);
            }
        }
    }
    
    std::cout << "Print values:: " << "\n";
    for(int i=0; i<n; i++){
        std::cout << multipleToOneArray[i][0] << "\t" << multipleToOneArray[i][1] << "\n";
    }
    
    return (int*) multipleToOneArray;
}

void hw6_reciprocal(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    auto arrComb = hw5_mult_vec_to_one(n);
    // print all elements
    std::cout << "print all elements.";
    for (int r=0; r<n; r++){
        cout << "Reciprochnata stoinost na " <<arrComb[2*r + 0] <<  " e " << arrComb[2*r+ 1];
        cout << "\n" ;
    }
    
    int in_recip = 0 ;
    std::cout << "Input value to find it reciprocal value inside the ring Z_n, where n is: " << n;
    std::cin >> in_recip;
    for (int r=0; r<n; r++){
        if(arrComb[2*r + 0] == in_recip){
            cout << "Reciprochnata stoinost na " <<arrComb[2*r + 0] <<  " e " << arrComb[2*r+ 1];
        }
    }
    cout << "\n" ;
}
