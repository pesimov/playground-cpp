//
//  question14.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question14.hpp"
#include "question12.hpp"

int discrete_log_modN(int powerG, int n, int b){
    bool isPowerGroot = checkPrimitivenKoren(powerG, n);
    
    if(isPowerGroot == false){
        return -1;
    }
    
    for(int x = 0; x<n; x++){
        int g_to_powerX_modN = int(pow(powerG, x)) % n;
        if( g_to_powerX_modN == b){
            return g_to_powerX_modN;
        }
    }
    return 0;
}

void hw14_discrete_logarithm(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    std::cout << "Value for power to raise (i.e. g in question 14) \n";
    int powerG = 0;
    std::cin >> powerG;
    
    std::cout << "Value for log's value (i.e. b in question 14) \n";
    int b = 0;
    std::cin >> b;
    
    
    int ans = discrete_log_modN(powerG, n, b);
    if(ans == -1){
        std::cout <<"powerG is not primitive root, no solution exist." << std::endl;
    }else{
        std::cout <<"powerG is primitive root, and the solution is: " << ans << std::endl;
    }
    
}
