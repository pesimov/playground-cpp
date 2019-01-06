//
//  question12.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question9.hpp"
#include "question12.hpp"

#include <unordered_set>
#include <set>

bool checkPrimitivenKoren(int value, int n){
    
    std::set<int> setValues;
    //iterate over power
    for(int power=1; power<n; power++){
        //overflow is not detected here
        //int valModulus = int(pow(i, power)) % n;
        
        //raisePowerFirstMethod a^m modulus n
        int valModulus = raisePowerFirstMethod(n, value, power);
        setValues.insert(valModulus);
    }
    
    bool is_i_primitiven_koren = true;
    for(int iter=1; iter<n; iter++){
        if(setValues.count(iter) != 1){
            //the iterated value iter is not primitiven koren
            is_i_primitiven_koren = false;
            break;
        }
    }
    return is_i_primitiven_koren;
}

void hw12_check_set_root(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    std::cout << "Value for the power to check if it is primitive power.\n";
    int value = 0;
    std::cin >> value;
    //for(int i=4; i<5; i++){
    
    bool is_i_primitiven_koren = checkPrimitivenKoren(value, n);

    if(is_i_primitiven_koren){
        std::cout <<" The value " << value << "is primitive power inside ring " << n  << std::endl;
    }else{
        std::cout <<" The value " << value << "is not a primitive power inside ring " << n  << std::endl;
    }
    
    
}
