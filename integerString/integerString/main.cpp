//
//  main.cpp
//  integerString
//
//  Created by Peter Simov on 8/11/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <iostream>
#include <string> 
#include <sstream>


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string st = "123";
    int result;
    std::stringstream(st) >> result;
    
    for(const auto& stringDigit: st){
        std::cout << stringDigit << " ";
    }
    return 0;
}
