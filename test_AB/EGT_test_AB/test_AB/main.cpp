//
//  main.cpp
//  Comparator
//
//  Created by Peter Simov on 8/2/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool compareInitTargetBinary(std::string & initial, std::string&  target){

    //convert to binary
    //keep track of index length
    
    uint16_t initialBinary = 0, targetBinary = 0;
    //convert initial and target strings to binary
    //http://en.cppreference.com/w/cpp/language/integer_literal
    std::string binaryliteralInitial = "";
    //std::string s("hello");
    std::transform(initial.begin(), initial.end(), initial.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });
    
    
    //    iter ? 'A'
    //}
    
    return true;
}

bool compareInitTarget(std::string & initial, std::string&  target){
//start with target string. Reverse and -un-add-it.
    //at each step
    //if the length of the modified string (derived from target is less than initial, return false
    //if the length of teh modified and initial strings are the same compare. If the two match, then return true.
    std::string modified = target;
    
    while(modified.length() >= initial.length()){
        if (modified.length()==initial.length()){
            
            if(modified.compare(initial) == 0){
                return true; //there is a path initial-target
            } else {;
                return false; //there is not a path initia-target
            }
        }
        size_t length = modified.length() - 1;
        if(modified.at(length) == 'A'){
            modified.pop_back();
        }else{
            modified.pop_back();
            std::reverse(modified.begin(), modified.end());
        }
        
    }//end loop
    
    return false; //no matching path initial-target is found
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::string initial = "AB";
    std::string target = "ABB";
    bool isTherePath = compareInitTarget(initial, target);
    if(isTherePath){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    //for easier debugging, still work with strings
    //TODO: check input. only A and B's

    bool isTherePathBinary = compareInitTargetBinary(initial, target);
    if(isTherePathBinary){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
