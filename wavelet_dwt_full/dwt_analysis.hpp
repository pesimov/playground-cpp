//
//  dwt_analysis.hpp
//  wavelet_dwt_full
//
//  Created by Peter Simov on 6/11/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#ifndef dwt_analysis_hpp
#define dwt_analysis_hpp

#include <stdio.h>
#include <vector>



std::vector<std::pair<std::vector<double>,std::vector<double>>> wavelet_dwt_1d(std::vector<double> input_list_doubles, size_t max_levels);
std::vector<double> wavelet_idwt_1d(std::vector<std::pair<std::vector<double>,std::vector<double>>>);
#endif /* dwt_analysis_hpp */
