//
//  main.cpp
//  codilityTestA
//
//  Created by Peter Simov on 7/15/17.
//  Copyright © 2017 Peter Simov. All rights reserved.
//

#include <iostream>
#include <vector>

struct multidaySegment{
    int startingDay;
    int endingDay; //sled 7 dni
    int numberUsedDays;
    
};

struct pathCombined{
    int maxValueMonthly = 25;
    int weeklyTickets = 0;
    int dailyTickets = 0;
    int cost = 0;
    ~pathCombined(){};
    
};

std::pair<int,int> scanDaysAhead(std::vector<int> &A, size_t iterInitDay, int daysAhead = 7){
//scan 7-day segments

    int numberTravelingDays7segments = 0;
    int valueInitDay = A[iterInitDay];
    std::vector<int>::size_type lookAhead7d = iterInitDay;
    std::vector<int>::size_type lookAhead7dIndex = iterInitDay;
    for(; (lookAhead7d < iterInitDay+daysAhead) && (lookAhead7d <= A.size()); lookAhead7d++) {
        if(A[lookAhead7d] <=valueInitDay + daysAhead){
            ++numberTravelingDays7segments;
            lookAhead7dIndex = lookAhead7d;
        }
    }//end for
    return std::make_pair(numberTravelingDays7segments,lookAhead7dIndex);
}

int solution(std::vector<int> &A){
    
    if(A.size() == 0) return 0;
    
    //list all available combinations
    //do depth-search analysis
    
    //cost of 7 days: 7
    //cost of a single day: 2
    //cost monthly, max = 25
    int cost = 0;
    pathCombined costTickets;
    //iterate 4 times
    //once: search for 7-day combinations. Second: 6-day combinations. Third:5 day combinations; Forth: 4 day combinations.
    //remove days when each time a combination is found
    
    //rest: are daily tickets
    std::vector<int> B(A);
    
    for(int searchDayCombinations = 7; searchDayCombinations >=4; searchDayCombinations--){
        for(std::vector<int>::size_type iter = 0; iter < B.size(); iter++) {
            if(B.size() == 0) break;
            std::pair<int,int> numberTravelingDays7segments =scanDaysAhead(B,iter, 7);
            std::cout << "Number of traveling days between days:" <<B[iter] << " is: " <<numberTravelingDays7segments.first << std::endl;
            if (numberTravelingDays7segments.first >= searchDayCombinations){
                cost += 7;
                iter = numberTravelingDays7segments.second;
                //find last element within 7 days
                auto lastItrElementwithin7d = B.begin() + 7;
                lastItrElementwithin7d = lastItrElementwithin7d < B.end() ? lastItrElementwithin7d : B.end();
                
                //B.erase(B.begin() + iter, lastItrElementwithin7d);
                B.erase(B.begin() + iter - searchDayCombinations, B.begin() + iter);
                costTickets.cost = costTickets.cost+7;
                costTickets.weeklyTickets = costTickets.weeklyTickets+1;
            }
        }
    }
    std::cout << "Computed cost for weekly tickets is: " << cost << std::endl;
    std::cout << "Leftover days are: " << B.size() << std::endl;
    //std::cout << "add leftover days back to cost " <<
    costTickets.dailyTickets = int( B.size());
    costTickets.cost = costTickets.cost + (costTickets.dailyTickets)*2;
    
    //does it exceed max cost? either use monthly or computed path-cost
    int computedCost = costTickets.cost;
    if(computedCost > costTickets.maxValueMonthly){
        computedCost = costTickets.maxValueMonthly;
    }
    delete costTickets;
    return computedCost;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //std::vector<int>v = {1, 3, 5, 7};
    std::vector<int> A = {1,2,4,5,7, 29,30};
    int val =  solution(A);
        
    return 0;
}
