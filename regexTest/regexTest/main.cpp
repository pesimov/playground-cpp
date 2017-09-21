//
//  main.cpp
//  regexTest
//
//  Created by Peter Simov on 7/12/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>

int main()
{
    std::string text = "Quick--brown fox  sc.";
    // tokenization (non-matched fragments)
    // Note that regex is matched only two times: when the third value is obtained
    // the iterator is a suffix iterator.
    std::regex ws_re("[\\s]+|[-+]"); // whitespace
    std::copy( std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
    
    // Simple regular expression matching
    std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg", "345.txt"};
    std::regex txt_regex("[0-9]+\\.txt");
    
    for (const auto &fname : fnames) {
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
    }
    
    std::string inputPhone = "(123) x456-7890";
    std::regex ws_dig("[\\D]+"); // any non digit character
    bool match1 = regex_search(inputPhone, ws_dig);
    
    inputPhone.erase(std::remove(inputPhone.begin(), inputPhone.end(), '-'), inputPhone.end());
    inputPhone.erase(std::remove(inputPhone.begin(), inputPhone.end(), ' '), inputPhone.end());
    inputPhone.erase(std::remove(inputPhone.begin(), inputPhone.end(), '('), inputPhone.end());
    inputPhone.erase(std::remove(inputPhone.begin(), inputPhone.end(), ')'), inputPhone.end());
    
    
    std::cout << inputPhone << std::endl << " isdigit:" << std::all_of(inputPhone.begin(), inputPhone.end(), ::isdigit); // C++11;
    
    //std::regex ws_dig("[[:digit:]][[:digit:]]\\..*"); // digits
    bool match = regex_search(inputPhone, ws_dig);
    std::cout << "match1: " << match1 << " " << match;
    
    std::regex ws_onlydig("[\\d]+"); // any non digit character
    bool match_only_dig = regex_match(inputPhone, ws_onlydig);
    
    /*
    // iterating the first submatches
    std::string html = "<p><a href=\"http://google.com\">google</a> "
    "< a HREF =\"http://cppreference.com\">cppreference</a>\n</p>";
    std::regex url_re("<\\s*A\\s+[^>]*href\\s*=\\s*\"([^\"]*)\"", std::regex::icase);
    std::copy( std::sregex_token_iterator(html.begin(), html.end(), url_re, 1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n"));

     */
    
}
