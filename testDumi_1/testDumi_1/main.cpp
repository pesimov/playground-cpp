//
//  main.cpp
//  testDumi_1
//
//  Created by Peter Simov on 8/2/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//≠=

#include <iostream>
#include <vector>
#include <string>
#include <random>

#define lengthMemory 1024
//char* ptr = new char[lengthMemory]; or malloc

std::vector<std::string> inputWords = {"this","second"};

class placementWord{
public:
    char ptr[lengthMemory];
    bool ptrPlacement[lengthMemory];

    
    placementWord(){
        for(int i =0; i<lengthMemory; i++ ){
            ptr[i] = '-';
            ptrPlacement[i] = false;
            
        }
        
    }
    int addNewWord(std::string const wordToAdd ){
        int lengthWord = wordToAdd.length();
        //std::random_device rd;
        std::mt19937 gen(std::time(0));
        std::uniform_int_distribution<> dis(0,lengthMemory - 1 - lengthWord);
        if(possibleToAddWord(wordToAdd)){
            bool placeNewWord = false;
            int valueCheckNewLocation = 0;
            while(!placeNewWord){
            //pick new randomly distrubuted location among 0 to lengthMemory minus size word
            //uniform distribution
            
            
            valueCheckNewLocation = dis(gen);
            placeNewWord = isNextLengthEmpty(valueCheckNewLocation,lengthWord);
            }//end while
            
            //place new word: add string and set the boolean to 'true' at the same locations
            placeWord(wordToAdd, valueCheckNewLocation);
        }else{
            return -1;
        }
        
        return 0;
    }
    
    void placeWord(std::string const wordToAdd, int valueCheckNewLocation){
        size_t lengthWord = wordToAdd.length();
        for(size_t wordIter = 0; wordIter < lengthWord; wordIter++){
            size_t placementIter = size_t(valueCheckNewLocation + wordIter);
            
            ptr[placementIter] = wordToAdd.at(wordIter);
            ptrPlacement[placementIter] = true;
        }
    }
    
    void printBuffer(){
        std::cout << std::endl;
        for(size_t j = 0; j<lengthMemory; j++){
            std::cout << ptr[j];
        }
        std::cout << std::endl;
    }
    
    bool isNextLengthEmpty(int indexStart, size_t lengthWord){
        for(int j = indexStart; j<lengthWord; j++){
            if(ptrPlacement[j] == true){
                return false;
            }
        }
        return true;
    }
    
    bool possibleToAddWord(std::string const wordToAdd){
        size_t lengthWord = wordToAdd.length();
        for(int i =0; i<lengthMemory-lengthWord;i++){
            for(int j = i; j<lengthWord; j++){
                if(ptrPlacement[j] == true){
                    return false;
                }
            }
        }
        
        return true;
    }

    ~placementWord(){
        
    }
};

void printVecStrings (std::vector<std::string> wordsToPrint)
{
    for(auto a:wordsToPrint){
        std::cout << a << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    //printVecStrings(inputWords);
    placementWord wordsAdder;// = *new placementWord();
    //wordsAdder.addNewWord(inputWords.at(0));
    
    for(auto iterOverWords:inputWords){
        int returnVal = wordsAdder.addNewWord(iterOverWords);
        if(returnVal == 1){
            wordsAdder.printBuffer();
            //stop processing???
            return 0;
        }
    }
    
    wordsAdder.printBuffer();
    
    
    return 0;
}
