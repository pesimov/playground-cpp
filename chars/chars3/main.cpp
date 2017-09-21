//
//  main.cpp
//
//  Created by Peter Simov on 8/9/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <iostream>



struct sResult{
    sResult(int m_count_, char* m_content_){
        m_count = m_count_;
        m_content = m_content_;
    };
    void increment(){
        m_count++;
    }
    
    void copySegment(const char* valPtrToIter, size_t lenChar){
        const char * valIterFwd = valPtrToIter;
        char* m_content_add = m_content + m_count*lenChar;
        while( *valIterFwd != '\0'){
            *m_content_add = *valIterFwd;
            valIterFwd++;
        }
        *(m_content_add+1) = '\0';
    }
    
    int m_count;
    char* m_content; //null terminted
};

sResult* findCountCustom(const char* data, const char* val){
    //TODO: use shared_ptr
    sResult * findCountResult = new sResult(0,nullptr);
    size_t iter = 0;
    while( *data != '\0'){
        std::cout << iter++;
        if(*data == *val){//enter loop: compare with val values
            bool isMatch = true;
            const char * dataIterFwd = data;
            const char * valIterFwd = val;
            size_t lenChar = 0;
            while( *valIterFwd != '\0'){
                lenChar++;
                if(*dataIterFwd != *valIterFwd){
                    isMatch = false;
                    break;
                }
                valIterFwd++;
                dataIterFwd++;
            }
            // if isMatch == false: do nothing
            // if isMatch == true: copy characters into the sResults' m_content
            // and increment m_count by one
            
            if(isMatch == true){
                findCountResult->increment();
                findCountResult->copySegment(valIterFwd, lenChar);
            }
        }
    }
    
    return findCountResult;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    const char* A = "power";
    const char* B = "Flower power. Flower power. Flower power.";
    
    sResult* result = findCountCustom(A,B);
    
    
    return 0;
}
