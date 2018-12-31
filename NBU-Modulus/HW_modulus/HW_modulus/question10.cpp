//
//  question10.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question10.hpp"

void hw10_power_second_method(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    std::cout << "Value to raise, a in HW question 9: \n";
    
    int a = 0;
    std::cin >> a;
    
    std::cout << "The power to raise: m in HW question 9: \n";
    int m = 0;
    std::cin >> m;
    
    //find k - lowest possible power at which a^k mod n = 1 mod n
    std::vector<vector<int>> raisedToBinaryPower;
    
    int k_iter = 0;
    int k_iter_power = 1;
    int k_iter_power_previously_computed_modulus = a % n;
    while(k_iter_power<m){
        k_iter++;
        k_iter_power = pow(2, k_iter);
        int a_to_k_iter_power_modulus = (k_iter_power_previously_computed_modulus * k_iter_power_previously_computed_modulus) % n;
        k_iter_power_previously_computed_modulus = a_to_k_iter_power_modulus;
        std::vector<int> new_combination;
        new_combination.push_back(k_iter_power);
        new_combination.push_back(a_to_k_iter_power_modulus);
        raisedToBinaryPower.push_back(new_combination);
    }
    int diff = m;
    k_iter--;
    int multiple = 1;
    while(diff > 0 && diff != 0){
        if(diff % 2 == 0 && int(pow(2, k_iter)) <= diff){
            int k_iter_power = pow(2, k_iter);
            diff = diff - k_iter_power;
            std::vector<int> get_combination = raisedToBinaryPower.at(k_iter-1);
            multiple = multiple * get_combination.at(1);
        }
        k_iter--;
    }
    
    int multiple_modulus = multiple % n;
    
    cout << "The multiple according to the second method of raising power is: " << multiple_modulus << endl;
    
}
