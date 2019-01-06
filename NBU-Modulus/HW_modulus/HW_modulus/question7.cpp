//
//  question7.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question7.hpp"
void hw7_bezout_inverser_solution(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    
    std::cout << "Value for m, whose inverse will be computed according to the Bezout's identity.\n";
    // Bezout's identity: s*m + t*n = 1
    // Bezout's identity, rewritten: n*t + m*s = 1
    // reference: https://wikivividly.com/wiki/Extended_Euclidean_algorithm
    
    int m = 0;
    std::cin >> m;

    //function
    double s = 0.0;
    double r = (double) n;
    double new_s = 1.0;
    double new_r = m;
    
    int new_r_int = (int) new_r;
    int counter = 0;
    
    while ((abs(new_s) > 0.01 ) && (new_r > 0 ) && counter < 1000){
        cout << "Counter value is:" << counter << endl;
        ++counter;
        //new_r = (double) new_r_int;
        int quotient = int(((double) n) / new_r);
        //double tmp_new_s = new_s;
        new_s = s - quotient * new_s;
        s = new_s;
        
        //double tmp_new_r = new_r;
        new_r = r - ( quotient) * new_r;
        new_r_int = (int) r - quotient * (int) new_r;
        r = new_r;
    }
    
    if (s > 1 ){
        cout << "The value is not invertible" << endl;
    }
    if (r < 0.0 ){
        cout << "The reciprocal element of s is " << r << " or in modulus, it is: " << ((int(r) + n)%n) << endl;
    }
    
    cout << "\n" ;
}
