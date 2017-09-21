//
//  main.cpp
//  testVirtualClass
//
//  Created by Peter Simov on 7/12/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <iostream>

class Parent {
public:
    void virtual vsay() {
        std::cout << "parent vsay\n";
    }
};

class Child : public Parent {
public:
    void virtual vsay()
    {
        std::cout << "child vsay\n";
    }
};

int main()
{
    
    Parent *a = new Parent();
    Parent *b = new Child();
    
    a->vsay();
    b->vsay();
    Child *c = new Child();
    c->vsay();
    
    return 0;
}
