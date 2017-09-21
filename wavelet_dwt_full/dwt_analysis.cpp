//
//  dwt_analysis.cpp
//  wavelet_dwt_full
//
//  Created by Peter Simov on 6/11/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include "dwt_analysis.hpp"
#include <iostream>
#include <cassert>

//from http://wavelets.pybytes.com/wavelet/db1/
std::vector<double> db1_coef_decom_low_pass = {0.7071067811865476,0.7071067811865476}; //approximation coef
std::vector<double> db1_coef_decom_high_pass = {0.7071067811865476,-0.7071067811865476}; //detailed coef


std::vector<double> db1_coef_recon_low_pass = {0.7071067811865476,0.7071067811865476}; //approximation recon coef
std::vector<double> db1_coef_recon_high_pass = {-0.7071067811865476,0.7071067811865476}; //detailed recon coef



void display_values_pair(std::pair<std::vector<double>,std::vector<double>> curr_pair){
    //display results of current level
    for(size_t iterlen = 0; iterlen<curr_pair.first.size(); iterlen++){
        std::cout << " appx " << curr_pair.first[iterlen] << std::endl;
    }
    for(size_t iterlen=0; iterlen<curr_pair.first.size(); iterlen++){
        std::cout << "  det " << curr_pair.second[iterlen] << std::endl;
    }
}

void display_values_vector_pair(std::vector<std::pair<std::vector<double>,std::vector<double>>> curr_vec_pair){
    for(size_t at_level_vertical = 0; at_level_vertical < curr_vec_pair.size(); at_level_vertical++){
        std::cout << "\n\nIDWT FINAL results pairs: " << " " << at_level_vertical << std::endl;
        std::pair<std::vector<double>,std::vector<double>> pair_a_d = curr_vec_pair[at_level_vertical];
        display_values_pair(pair_a_d);
    }
}

std::pair<std::vector<double>,std::vector<double>> calc_res_level(std::vector<double> list_doubles_level)
{
    size_t size_wavelet_coef = db1_coef_decom_low_pass.size();
    
    std::pair<std::vector<double>,std::vector<double>> results_of_current_level;
    
    std::vector<double> app_coef_level(list_doubles_level.size()/2 );
    std::vector<double> det_coef_level(list_doubles_level.size()/2 );
    
    if(list_doubles_level.size() == 2){
        app_coef_level[0] = db1_coef_decom_low_pass[0] * list_doubles_level[0] + db1_coef_decom_low_pass[1] * list_doubles_level[1];
        det_coef_level[0] = db1_coef_decom_high_pass[0] * list_doubles_level[0] + db1_coef_decom_high_pass[1] * list_doubles_level[1];
    }else{
    
    for(size_t it_input_list = 0; it_input_list < list_doubles_level.size() - 3; it_input_list +=  2) //no overlap
    {
        std::vector<double> app_coef(size_wavelet_coef);
        std::vector<double> det_coef(size_wavelet_coef);
        std::cout << "\nit_input_list" << it_input_list;
        
        app_coef[0] = double(db1_coef_decom_low_pass[0] * list_doubles_level[it_input_list] + db1_coef_decom_low_pass[1] * list_doubles_level[it_input_list+1]);
        app_coef[1] = double(db1_coef_decom_low_pass[0] * list_doubles_level[it_input_list+2] + db1_coef_decom_low_pass[1] * list_doubles_level[it_input_list+3]);
        
        det_coef[0] = double(db1_coef_decom_high_pass[0] * list_doubles_level[it_input_list]   + db1_coef_decom_high_pass[1] * list_doubles_level[it_input_list+1]);
        det_coef[1] = double(db1_coef_decom_high_pass[0] * list_doubles_level[it_input_list+2] + db1_coef_decom_high_pass[1] * list_doubles_level[it_input_list+3]);
        
        app_coef_level[it_input_list/2]    = app_coef[0];
        app_coef_level[it_input_list/2 +1] = app_coef[1];
        det_coef_level[it_input_list/2]    = det_coef[0];
        det_coef_level[it_input_list/2 +1] = det_coef[1];
    }
    }//end if-else
        //results_of_current_level.push_back(make_pair(app_coef_level, det_coef_level));
    
        /*std::cout << "\n\nResults in progress display values pair: " << std::endl;
        for(size_t i=0; i<results_of_current_level.size(); i++){
            std::pair<std::vector<double>,std::vector<double>> pair_a_d = results_of_current_level[i];
            display_values_pair(pair_a_d);
        }*/
    return make_pair(app_coef_level, det_coef_level);
}
/*
std::pair<std::vector<double>,std::vector<double>> recon_calc_up_level(std::pair<std::vector<double>,std::vector<double>> pair_one, std::pair<std::vector<double>,std::vector<double>> pair_two)
{
    assert(pair_one.first.size() == pair_two.first.size());
    size_t size_wavelet_coef = db1_coef_recon_low_pass.size();
    
    std::vector<double> recon_results_of_current_level_app(size_wavelet_coef);
    std::vector<double> recon_results_of_current_level_det(size_wavelet_coef);
    
    for(size_t it_coef_list = 0; it_coef_list < size_wavelet_coef; it_coef_list +=  size_wavelet_coef)
    {
        for(size_t it_recon_list = 0; it_recon_list < size_wavelet_coef; it_recon_list +=  1)
            {
                    recon_results_of_current_level_app[it_recon_list] = db1_coef_recon_low_pass[it_recon_list] * pair_one.first[it_recon_list] + db1_coef_recon_low_pass[it_recon_list] * pair_two.first[it_recon_list];
                
                    recon_results_of_current_level_det[it_recon_list] = db1_coef_recon_high_pass[it_recon_list] * pair_one.second[it_recon_list] + db1_coef_recon_high_pass[it_recon_list] * pair_one.second[it_recon_list];
            }
    }
    
    return make_pair(recon_results_of_current_level_app, recon_results_of_current_level_det);
}*/


std::vector<double> recon_calc_up_level_to_vector(std::pair<std::vector<double>,std::vector<double>> pair_one)
{
    size_t size_wavelet_coef = db1_coef_recon_low_pass.size();
    size_t size_level_up = pair_one.first.size();
    
    std::vector<double> recon_coef_up(size_wavelet_coef);
    
    std::vector<double> recon_results_of_current_level_app(2*size_level_up);
    
    for(size_t it_coef_list = 0; it_coef_list < size_level_up; it_coef_list +=  1)
    {
        recon_coef_up[0] = db1_coef_recon_low_pass[0] * pair_one.first[it_coef_list] + db1_coef_recon_high_pass[0] * pair_one.second[it_coef_list];
        recon_coef_up[1] = db1_coef_recon_low_pass[1] * pair_one.first[it_coef_list] + db1_coef_recon_high_pass[1] * pair_one.second[it_coef_list];
        
        recon_results_of_current_level_app[2*it_coef_list]   = recon_coef_up[0];
        recon_results_of_current_level_app[2*it_coef_list+1] = recon_coef_up[1];
    }
    
    return recon_results_of_current_level_app;
}


std::pair<std::vector<double>,std::vector<double>> recon_calc_up_level_revised(std::pair<std::vector<double>,std::vector<double>> pair_one, std::pair<std::vector<double>,std::vector<double>> pair_two)
{
    assert(pair_one.first.size() == pair_two.first.size());
    size_t size_wavelet_coef = db1_coef_recon_low_pass.size();
    size_t size_level_up = pair_one.first.size();
    
    std::vector<double> recon_coef_up(size_wavelet_coef);
    std::vector<double> recon_coef_up_det(size_wavelet_coef);
    
    std::vector<double> recon_results_of_current_level_app(2*size_level_up);
    std::vector<double> recon_results_of_current_level_det(2*size_level_up);
    
    for(size_t it_coef_list = 0; it_coef_list < size_level_up; it_coef_list +=  1)
    {
        recon_coef_up[0] = db1_coef_recon_low_pass[0] * pair_one.first[it_coef_list] + db1_coef_recon_high_pass[0] * pair_one.second[it_coef_list];
        recon_coef_up[1] = db1_coef_recon_low_pass[1] * pair_one.first[it_coef_list] + db1_coef_recon_high_pass[1] * pair_one.second[it_coef_list];

        recon_coef_up_det[0] = db1_coef_recon_low_pass[0] * pair_two.first[it_coef_list] + db1_coef_recon_high_pass[0] * pair_two.second[it_coef_list];
        recon_coef_up_det[1] = db1_coef_recon_low_pass[1] * pair_two.first[it_coef_list] + db1_coef_recon_high_pass[1] * pair_two.second[it_coef_list];
        
        recon_results_of_current_level_app[2*it_coef_list]   = recon_coef_up[0];
        recon_results_of_current_level_app[2*it_coef_list+1] = recon_coef_up[1];
        
        recon_results_of_current_level_det[2*it_coef_list]   = recon_coef_up_det[0];
        recon_results_of_current_level_det[2*it_coef_list+1] = recon_coef_up_det[1];
    }
    
    return make_pair(recon_results_of_current_level_app, recon_results_of_current_level_det);
}
std::vector<std::pair<std::vector<double>,std::vector<double>>> wavelet_dwt_1d(std::vector<double> input_list_doubles, size_t max_levels){
//compute number of levels
    std::cout << "wavelet_dwt_1d" << std::endl;
    std::vector<std::pair<std::vector<double>,std::vector<double>>>  res_levels_at_levels;
    std::vector<std::vector<std::pair<std::vector<double>,std::vector<double>>>> res_levels_for_all_levels;
    std::vector<std::vector<std::pair<std::vector<double>,std::vector<double>>>>  recon_levels_all;
    
    std::pair<std::vector<double>,std::vector<double>>  res_per_level;
    std::pair<std::vector<double>,std::vector<double>>  res_per_level_from_det;
    std::pair<std::vector<double>,std::vector<double>>  res_per_level_from_appr;
    std::vector<double> to_comp_list_doubles(input_list_doubles);
    std::cout <<"\n\n";
    for(size_t i =0; i<to_comp_list_doubles.size(); i++){
        std::cout << to_comp_list_doubles[i] << ":";
    }

    
    
    res_per_level = calc_res_level(to_comp_list_doubles);
    res_levels_at_levels.push_back(res_per_level);
    res_levels_for_all_levels.push_back(res_levels_at_levels);
    
    
    
    for(size_t level_iteration = 1; level_iteration < max_levels; level_iteration++){
        std::cout << "\nDeconstruction: New vertical iteration. Current sizes are: " << res_levels_at_levels.size() << ".";
        res_levels_at_levels.clear(); //TODO MEMORY ISSUE: overwriting vectors; over the same ... actually I used to send this variable...
        for(size_t at_level_vertical = 0; at_level_vertical < res_levels_for_all_levels[level_iteration-1].size(); at_level_vertical++){
            //std::cout << "\nPre-size: " << res_levels_at_levels.size() << ".";
            res_per_level_from_appr = calc_res_level(res_levels_for_all_levels[level_iteration-1][at_level_vertical].first);
            res_per_level_from_det  = calc_res_level(res_levels_for_all_levels[level_iteration-1][at_level_vertical].second);
            res_levels_at_levels.push_back(res_per_level_from_appr);
            res_levels_at_levels.push_back(res_per_level_from_det);
            
            std::cout << "\nPost-size: " << res_levels_at_levels.size() << ".";
        }
        res_levels_for_all_levels.push_back(res_levels_at_levels);
    }
    /*
    for(size_t level_iteration = 0; level_iteration < 1; level_iteration++){
        for(size_t at_level_vertical = 0; at_level_vertical < res_levels_at_levels.size(); at_level_vertical++){
            std::cout << "\n\nFinal final Results final results pairs: " << level_iteration << " " << at_level_vertical << std::endl;
            std::pair<std::vector<double>,std::vector<double>> pair_a_d = res_levels_at_levels[at_level_vertical];
            display_values_pair(pair_a_d);
        }
    }*/
    
    return res_levels_at_levels;
}

std::vector<std::pair<std::vector<double>,std::vector<double>>> idwt_1d_level_up(std::vector<std::pair<std::vector<double>,std::vector<double>>> resCurrLevel){
    std::vector<std::pair<std::vector<double>,std::vector<double>>> resUpLevel;
    //if(resCurrLevel.size() == 2){
    //
    //} else {
     for(size_t at_level_vertical = 0; at_level_vertical < resCurrLevel.size()-1; at_level_vertical += 2){
         std::cout << "\n\nIDWT intermediate: start" << " " << at_level_vertical << " out of available:" << resCurrLevel.size() << std::endl;
         std::pair<std::vector<double>,std::vector<double>> pair_a_d_one = resCurrLevel[at_level_vertical];
         std::pair<std::vector<double>,std::vector<double>> pair_a_d_two = resCurrLevel[at_level_vertical+1];
         std::pair<std::vector<double>,std::vector<double>> pair_a_d_up = recon_calc_up_level_revised(pair_a_d_one,pair_a_d_two);
         
         std::cout << "\n\nIDWT pair_a_d_one " << std::endl;
         display_values_pair(pair_a_d_one);
         std::cout << "\n\nIDWT pair_a_d_two " << std::endl;
         display_values_pair(pair_a_d_two);
         std::cout << "\n\nIDWT intermediate: up " << std::endl;
         display_values_pair(pair_a_d_up);
         resUpLevel.push_back(pair_a_d_up);
         //std::cout << "\n\nIDWT intermediate: end " << std::endl;
     }//end for
    //}//end if
    return resUpLevel;
}

std::vector<double>  wavelet_idwt_1d(std::vector<std::pair<std::vector<double>,std::vector<double>>> result_last_level){

    std::cout << "wavelet_idwt_1d" << std::endl;
    std::vector<std::pair<std::vector<double>,std::vector<double>>>  levels_up_res;
    std::vector<std::pair<std::vector<double>,std::vector<double>>>  levels_up_init(result_last_level);
    std::vector<std::pair<std::vector<double>,std::vector<double>>>  levels_up_to_upp(result_last_level);
    
    
    for(size_t level_iteration = 0; levels_up_to_upp.size() != 1; level_iteration++){
        levels_up_res.clear();
        levels_up_res = idwt_1d_level_up(levels_up_to_upp);
        levels_up_to_upp = levels_up_res;
    }

    std::vector<double> last_level(levels_up_to_upp[0].first.size() * 2);
    if(levels_up_to_upp.size() == 1){
        last_level = recon_calc_up_level_to_vector(levels_up_to_upp[0]);
        for(int i = 0; i< last_level.size(); i++){
            std::cout << last_level[i] << " ";
        }
    }
    return last_level;
}
