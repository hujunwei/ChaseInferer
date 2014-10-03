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
#include <vector>
using namespace std;
class Chase {
private:
    /* attribute list */
    string attr_list;
    vector<string> fd_strings;
    vector<string> mvd_strings;
    vector<string> chase_strings;
    /* how many attributes */
    int attr_size;
    
public:
    Chase();
    ~Chase();
    unordered_set<string> generateSeed();
    void readAttrString(string attrbutes);
    void parseFdAndMvd(vector<string>& fileContent);
    void printChase();
    string removeFormat(string s);
    
};

#endif /* defined(__ChaseInferer__Chase__) */
