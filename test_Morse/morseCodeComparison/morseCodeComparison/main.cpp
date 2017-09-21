//
//  main.cpp
//  morseCodeComparison
//
//  Created by Peter Simov on 8/2/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector> 
#include <algorithm>

//......-...-..---.-----.-..-..-.. 5 HELL HELLO OWORLD WORLD TEST


const std::map<char, std::string> morse = {
    {'A', ".-"}, {'B', "-..."},{'C', "-.-."},{'D', "-.."},
    {'E', "."},  {'F', "..-."},{'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"},{'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."},  {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."},{'S', "..."},{'T', "-"},
    {'U', "..-"}, {'V', "...-"},{'W', ".--"},{'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
};

struct dictionaryMorseConversion{
//std::vector<std::string> dictionaryWords{"HELL", "HELLO", "OWORLD", "WORLD", "TEST"};
    std::vector<std::string> dictionaryWords;
    std::vector<std::string> dictionaryMorseConverted;
    dictionaryMorseConversion(std::vector<std::string> dictionaryWords_){
        dictionaryWords = dictionaryWords_;
        for(auto it: dictionaryWords){
            dictionaryMorseConverted.push_back(convertWordToMorse(it));
        }
        std::string inputSignaltest = "......-...-..---.-----.-..-..-..";
        std::cout << inputSignaltest << std::endl;
        for(auto it: dictionaryMorseConverted){
            std::cout << it << std::endl;
        }
    }
    
    size_t countInMorseDict(std::string const inputWordMorse){
        size_t countHistogram = 0;
        for(auto i = dictionaryMorseConverted.begin(); i != dictionaryMorseConverted.end(); ++i){
            if(*i == inputWordMorse) {
                ++countHistogram;
            }
        }
        //auto it = std::find(dictionaryMorseConverted.begin(),dictionaryMorseConverted.end(), inputWordMorse);
        //if(it != dictionaryMorseConverted.end()){
        //    return true;
        ///}else{
        //    return false;
        //}
        return countHistogram;
    }
    
    
    std::string convertWordToMorse(std::string const inputWord){
        std::string morseEncodedString = "";
        for(auto it: inputWord){
            auto search = morse.find(it);
            if(search != morse.end()){
                std::string secondVal = search->second;
                morseEncodedString.append(secondVal);
            }
        }
        return morseEncodedString;
    }
};

int matchSignalToMorseRecusiveStep(std::string modifiedSignalMorse, dictionaryMorseConversion& morseDictR){
    if(modifiedSignalMorse.length() == 0) {return 0;}
    
    for(size_t i=1; i<modifiedSignalMorse.length(); i++){
        std::string subModifiedSignalMorse = modifiedSignalMorse.substr(0,i);
        size_t checkExistanceOfWordMorse = morseDictR.countInMorseDict(subModifiedSignalMorse);
        if(checkExistanceOfWordMorse >= 1){//possible combination of word; needs to re-split the string again
            std::string subModifiedSignalMorse = modifiedSignalMorse.substr(i,modifiedSignalMorse.length()-i);
            
            int retVal = matchSignalToMorseRecusiveStep(subModifiedSignalMorse, morseDictR);
            //if(retVal>0){//there exists a combination later in the string of Morse characters
                return int(checkExistanceOfWordMorse) + retVal;
        //}
            //}else{ //no possible combination exists i nteh string of Morse characters
            //    return 0;
            //}

        }
        if(checkExistanceOfWordMorse == 0 && i == modifiedSignalMorse.length()){//end of string, but no match has been found in this combination
            return 0;
        }
    }
    
    return 0;
}


size_t matchSignalToMorse(std::string const inputSignalMorse){
//iterate signal, trying to match per word
    //iterate over all words in the dictionary. If match, iterate over signal
    //std::vector<std::string> input_dictionaryWords{"HELL", "HELLO", "OWORLD", "WORLD", "TEST"};
    std::vector<std::string> input_dictionaryWords{"OWORLD"};
    dictionaryMorseConversion morseDict(input_dictionaryWords);
    
    std::string modifiedSignalMorse = inputSignalMorse;
    //while(modifiedSignalMorse.length() != 0){
     size_t numCounts = matchSignalToMorseRecusiveStep(modifiedSignalMorse, morseDict);
    //}
    
    return numCounts;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //TODO: use argv to initialize data
    //std::string inputSignal = "......-...-..---.-----.-..-..-..";
    //std::string inputSignal = "......-...-..---.-----.-..-..-..";
    //std::string check = "---.-----.-..-..-..";
    std::string inputSignal = "---.-----.-..-..-..";
    size_t value = matchSignalToMorse(inputSignal);
    std::cout << "value:" << value << std::endl;
    
    return 0;
}
