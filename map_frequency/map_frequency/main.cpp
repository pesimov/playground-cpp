#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

struct Counter
{
    std::map<std::string, int> wordCount;
    void operator()(const std::string & item) { ++wordCount[item]; }
    operator std::map<std::string, int>() { return wordCount; }
};

int main()
{
    //std::ifstream input;
    //input.imbue(std::locale(std::locale(), new letter_only())); //enable reading only letters!
    //input.open("filename.txt");
    //istream_iterator<string> start(input);
    //istream_iterator<string> end;
    std::vector<std::string> input{"word1", "word2", "word1"};
    std::map<std::string, int> wordCount = std::for_each(input.begin(), input.end(), Counter());
    for (std::map<std::string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
    {
        std::cout << it->first <<" : "<< it->second << std::endl;
    }
    
    std::map<std::string, int> nextWordCount;
    for(const auto& iter: input){
        ++nextWordCount[iter];
    }
    for(const auto& iter: nextWordCount){
        std::cout << iter.first << ":" << iter.second << std::endl;
    }
    
    return 0;
}
