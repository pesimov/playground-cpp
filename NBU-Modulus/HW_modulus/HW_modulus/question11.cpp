//
//  question11.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question11.hpp"

void hw11_check_prime(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    if(n == 1){
        std::cout << "The of 1 is a special case. It is not prime. ";
        return;
    }

    std::cout << "Check if "<< n << " is prime." << endl;
    // brute-force approach
    // Use a for loop, divide by every number until sqrt (n) is reached.
    // if there is no remainder for at at least one value, n is not prime
    //e.g. 15 % 3 is 0, 15 is not prime
    // if for every value there is a remainder, n is not prime
    
    //https://stackoverflow.com/questions/45655671/check-if-prime-big-o
    
    bool isPrime = true;
    int i_sqrtVal = ceil(sqrt(n));
    for(int i=2; i<i_sqrtVal; i++){
        int remainder = n % i;
        if(remainder == 0){
            std::cout << "the input is not prime: " << n << endl;
            isPrime = false;
            break;
        }
    }
    
    //for(int i=2; i<n; i++){
    //    int remainder = n % i;
    //    if(remainder == 0){
    //        std::cout << "the input is not prime: " << n << endl;
    //        isPrime = false;
    //        break;
    //    }
    //}
    if (isPrime == true){
        std::cout << "The ring is a field for value of n of: " << n;
    }
    if (isPrime == false){
        std::cout << "The ring is not a field for value of n of: " << n;
    }
    
}
