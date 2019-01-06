//
//  question8.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question8.hpp"
#include "question5.hpp"
//will use code from question 5

/*int* hw5_mult_vec_to_one_q8(int n){
    
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

int hw6_reciprocal_int_q8(int n, int m_recip){

    auto arrComb = hw5_mult_vec_to_one_q8(n);
    // print all elements
    std::cout << "print all elements.";
    for (int r=0; r<n; r++){
        cout << "Reciprochnata stoinost na " <<arrComb[2*r + 0] <<  " e " << arrComb[2*r+ 1];
        cout << "\n" ;
    }
    
    int in_recip = m_recip ;

    for (int r=0; r<n; r++){
        if(arrComb[2*r + 0] == in_recip){
            cout << "Reciprochnata stoinost na " <<arrComb[2*r + 0] <<  " e " << arrComb[2*r+ 1];
            return arrComb[2*r+ 1];
        }
    }
    cout << "\n" ;
    return -1;
}*/


void hw8_delenie(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };

    std::cout << "Value to divide by \n";
    
    int m = 0;
    std::cin >> m;

    int arrComb [n][2];
    fillArray(arrComb,n);
    int m_recip = -1;
    for (int r=0; r<n; r++){
        if(arrComb[r][0] == m){
            cout << "Reciprochnata stoinost na " <<arrComb[r][0] <<  " e " << arrComb[r][1];
            m_recip = arrComb[r][1];
        }
    }
    if(m_recip == -1){
        std::cout << "Does not have reciprocal value. Exit function. \n";
    }else{
        
        std::cout << "Value to divide from \n";
        
        int to_divide = 0;
        std::cin >> to_divide;
        
        int mult = (to_divide * m_recip) % n;
        
        cout << "\n The division in ring " << n << "of value "<< to_divide << " by " << m << " is " << mult;
    }
    
    //int m_recip = hw6_reciprocal_int_q8(n, m);
}
