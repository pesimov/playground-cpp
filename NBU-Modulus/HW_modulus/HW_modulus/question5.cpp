//
//  question5.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question5.hpp"

void fillArray(int multipleToOneArray[][2], int n) {
    for(int i=0; i<n; i++){
        multipleToOneArray[i][0]=i;
        multipleToOneArray[i][1]=-1;
    }
    //see https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    //see https://stackoverflow.com/questions/15013077/arrayn-vs-array10-initializing-array-with-variable-vs-real-number
    
    //Purvo se minava po chislata koito shte im se vzeme modulus-at, iterator i
    for(int i=1; i<n; i++){
        //minava se po chislata koito shte se umnozhavat
        for (int j=1; j<n; j++){
            int modMultiple = (i * j) % n;
            
            if(modMultiple == 1){
                multipleToOneArray[i][0]=i;
                multipleToOneArray[i][1]=j;
                break;
                //multipleToOne.push_back(i); <-- std::vector, not used
            }
        }
    }
    
}
void hw5_mult_array_to_one(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    auto multipleToOneArray = new int [n][2]();
    fillArray(multipleToOneArray,n);
    
    std::cout << "Print values:: " << "\n";

    for(int i=0; i<n; i++){
        std::cout << multipleToOneArray[i][0] << "\t" << multipleToOneArray[i][1] << "\n";
    }
    delete[] multipleToOneArray;
}
