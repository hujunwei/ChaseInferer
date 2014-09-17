//
//  Chase.h
//  ChaseInferer
//
//  Created by Junwei Hu on 9/17/14.
//  Copyright (c) 2014 Junwei Hu. All rights reserved.
//

#ifndef __ChaseInferer__Chase__
#define __ChaseInferer__Chase__

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Chase {
private:
    /* attribute list */
    std::string attr_list;
    
    
public:
    Chase();
    ~Chase();
    std::unordered_set<string> generateSeed();
    
    
};

#endif /* defined(__ChaseInferer__Chase__) */
