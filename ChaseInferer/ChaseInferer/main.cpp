//
//  main.cpp
//  ChaseInferer
//
//  Created by Junwei Hu on 9/17/14.
//  Copyright (c) 2014 Junwei Hu. All rights reserved.
//

#include <iostream>
#include "Chase.cpp"
#include <fstream>
using namespace std;













int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    //Chase* chaseManager = new Chase();
    ifstream file;
    auto x = NULL;
    file.open("input.txt");
    if (!file) {
        perror("Invalid input file!\n");
        return EXIT_FAILURE;
    }
    file >> x;
    cout << x << endl;
    file.close();
    
    return EXIT_SUCCESS;
}

