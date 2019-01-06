//
//  question12.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question12.hpp"

#include <unordered_set>
#include <set>

void hw12_check_set_root(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    for(int i=1; i<n; i++){
        std::set<int> setValues;
        //iterate over power
        for(int power=1; power<n; power++){
            //overflow is not detected here
            int valModulus = int(pow(i, power)) % n;
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
        
        
    }
    
}
