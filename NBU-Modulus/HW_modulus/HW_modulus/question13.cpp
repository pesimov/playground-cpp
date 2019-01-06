//
//  question13.cpp
//  HW_modulus
//
//  Created  on 30.12.18.
//

#include "question13.hpp"
#include "question12.hpp"

#include <unordered_set>
#include <set>

void hw13_find_all_primitive_roots(){
    std::cout << "Value for n\n";
    
    int n = 0;
    std::cin >> n;
    
    while(n < 1){
        std::cout << "The value has to be positive for n. Enter a new value.";
        std::cin >> n;
    };
    std::unordered_set<int> setOfPrimitivenKoren;
    
    for(int value=1; value<n; value++){
        bool is_i_primitiven_koren = checkPrimitivenKoren(value, n); //from question 12
        if(is_i_primitiven_koren){
            setOfPrimitivenKoren.insert(value);
        }
    }
    
    //print value
    //https://stackoverflow.com/questions/27847288/is-there-a-way-to-get-all-values-out-of-an-stdunordered-map
    for (auto const& element : setOfPrimitivenKoren)
    {
        std::cout << element << "\t";  // Write to file or whatever you want to do
    }
    
    std::cout << "\n";
}
