//
//  main.cpp
//  static_functions
//
//  Created by Peter Simov on 8/8/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

/*#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}*/

#include <iostream>

using namespace std; class Base {
public:
    void f() { cout<<"Base\n"; }
};
class Derived:public Base { public:
    void f() { cout<<"Derived\n"; }
};

int main(int argc, const char * argv[]) {
    Derived *obj = new Derived;
    obj->Base::f();
}
