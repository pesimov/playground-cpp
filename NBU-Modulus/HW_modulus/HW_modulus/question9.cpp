//
//  question9.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question9.hpp"

void hw9_power_first_method(){
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
    int k_iter = 0;
    int a_power_to_k_iter_mod = 0;
    do{
        k_iter++;
        long a_power_to_k_iter = pow(a,k_iter);
        a_power_to_k_iter_mod = a_power_to_k_iter % n;
        cout << "a_power_to_k_iter_mod " << a_power_to_k_iter_mod << endl;
    }while(a_power_to_k_iter_mod != 1);
    
    int m_modulus_k = m % k_iter;
    int a_raised_to_power = pow(a, m_modulus_k);
    //int a_raised_to_power = 0;
    int a_raised_to_power_modulus = a_raised_to_power % n;
    cout << "The raised a to the power m in ring n is:" << a_raised_to_power_modulus << endl;
}
