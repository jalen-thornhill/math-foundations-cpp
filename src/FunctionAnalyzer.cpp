#include "FunctionAnalyzer.hpp"
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// I am building the range by keeping only the first occurrence of each output value.
void FunctionAnalyzer::printRange(){
    vector<char> range;


    for(auto& output : outputs){
        if(find(range.begin(), range.end(), output) == range.end()){
            range.push_back(output);
        }
    }

    for(auto& idx : range){
        cout << idx << "  \n\n";
    }
}


bool FunctionAnalyzer::isInjective(){
   // I am checking for repeated outputs to determine whether the function is one-to-one.
   set<char> seen;

   for (auto& output : outputs){
    if(seen.find(output) != seen.end()) return false;

    seen.insert(output);
   
    }
    return true;
}

bool FunctionAnalyzer::isSurjective(){
  // I am checking whether every value in the codomain appears in the function's outputs.
  int cnt = 0;
        for(auto& idx : codomain){
            if(find(outputs.begin(), outputs.end(), idx) != outputs.end()) 
                cnt++;
            }
       return cnt == codomain.size();
}

bool FunctionAnalyzer::isBijective(){
    // I am checking both properties because a bijective function must be one-to-one and onto.
    return isInjective() && isSurjective();
}
