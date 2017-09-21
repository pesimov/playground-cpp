//
//  main.cpp
//  wavelet_dwt_full
//
//  Created by Peter Simov on 6/11/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>

#include <ctime>
#include <ratio>
#include <chrono>

#include "date.h"

#include "dwt_analysis.hpp"
constexpr bool is_powerof2(size_t v) {
    return v && ((v & (v - 1)) == 0);
}

//TODO: make check for wrong input
size_t find_power(size_t v) {
    size_t level = 0;
    while (level <= 12){
        v /= 2; //delete by 2
        level++;
        if(v==1)
        {
            break;
        }
    }
    return level;
}

struct entry {
    std::string text;
    date::year_month_day date;
    bool finished;
};


int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    std::cout << "Reading data from input_list.txt:\n";
    std::cout << "Arguments sent include" << argv[1] << " " << argv[2] << " " << argv[3] << std::endl;
    
    entry e = {"here is some text", date::day(15)/10/2017, false};
    auto t = std::chrono::system_clock::now();
    auto date1 = date::sys_days{e.date};
    auto date2 = t;
    if (date2 > date1)
        std::cout << "It is past " << e.date << '\n';
    else
        std::cout << "It is not past " << e.date << '\n';
    
    
    
    std::ifstream inputfile("/Users/pesimov/Documents/FMI/Computer Vision Object Detection/project_wavelet/wavelet_dwt_full/wavelet_dwt_full/input_list.txt");
    std::ofstream outputFile("/Users/pesimov/Documents/FMI/Computer Vision Object Detection/project_wavelet/wavelet_dwt_full/wavelet_dwt_full/output_list_dwt.txt");
    std::ofstream outputFileReconstruction(argv[3]);
    
    std::vector<double> input_list_doubles_forloop;
    
    /*for (double a; inputfile >> a;) {
        input_list_doubles_forloop.push_back(a);
        std::cout << "for loop:" << a << std::endl;
    }*/
    
    std::vector<double> input_list_doubles{(std::istream_iterator<double>(inputfile)),
        std::istream_iterator<double>()};
    
    //input_list_doubles.push_back(16.0);
    //for (std::vector<double>::const_iterator i = input_list_doubles.begin(); i != input_list_doubles.end(); ++i)
    //std::cout << *i << " " << "\n";

    std::cout << "Assert data's length is 2 ** k. Confirm what k (number of levels is.";
    std::cout << "Length of input data is: " << input_list_doubles.size() << " which is " << is_powerof2(input_list_doubles.size()) << std::endl;
    
    assert(is_powerof2(input_list_doubles.size()));
    //check which power 2**k is the size of the input array
    
    size_t max_levels = find_power(input_list_doubles.size());
    assert(max_levels <= 10);
    std::cout << "Number of max levels " << max_levels << std::endl;
    
    //Call to FFT - optinonal depending on parameters
    const size_t fftSize = input_list_doubles.size(); // Needs to be power of 2!
    
    //call full_wavelet analysis with input list
    std::vector<std::pair<std::vector<double>,std::vector<double>>>res_levels_final_level=wavelet_dwt_1d(input_list_doubles, max_levels);
    
    
    //save results
    if(outputFile){
        for(size_t level_iteration = 0; level_iteration < 1; level_iteration++){
            for(size_t at_level_vertical = 0; at_level_vertical < res_levels_final_level.size(); at_level_vertical++){
                std::pair<std::vector<double>,std::vector<double>> pair_a_d = res_levels_final_level[at_level_vertical];
                for(size_t iterlen = 0; iterlen < pair_a_d.first.size(); iterlen++){
                    //std::cout << " appx " << pair_a_d.first[iterlen] << std::endl;
                    //std::cout << " det " << pair_a_d.second[iterlen] << std::endl;
                    outputFile << pair_a_d.first[iterlen] << "\n" << pair_a_d.second[iterlen];
                }
                outputFile <<"\n";
            }
        }
    }

    //call inverse wavelet analysis
   std::vector<double> output_list_doubles = wavelet_idwt_1d(res_levels_final_level);
    
    //save results
    if(outputFileReconstruction){
        for(int iter_results = int(output_list_doubles.size() - 1); iter_results >= 0; iter_results--){
            outputFileReconstruction << output_list_doubles[iter_results];
            outputFileReconstruction <<"\n";
        }
    }
    return 0;
}

