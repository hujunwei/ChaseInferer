//
//  main.cpp
//  ChaseInferer
//
//  Created by Junwei Hu on 9/17/14.
//  Copyright (c) 2014 Junwei Hu. All rights reserved.
//

#include <iostream>
#include "Chase.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;


bool readFileContent(vector<string>& fileContent) {
    ifstream infile;
    infile.open("/Users/junweihu/Github/MacbookGitRepo/ChaseInferer/ChaseInferer/ChaseInferer/ChaseInferer/input.txt");

    if (!infile) {
        cerr << "Invalid input file! " << endl;
        return false;
    }
    char buffer[500];
    while (!infile.eof()) {
        infile.getline(buffer, 200);
        string Str = string(buffer);
        fileContent.push_back(Str);
    }
    infile.close();
    return true;
}


void printFileContent(vector<string>& fileContent) {
    cout << "--File content begin--" << endl;
    for (int i = 0 ; i < fileContent.size(); i++) {
        cout << fileContent[i] << endl;
    }
    cout << "--File content end--" << endl;
}






int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    Chase* chaseManager = new Chase();
    /* read file to a fileContent */
    vector<string> fileContent;
    bool isReadSuccess = readFileContent(fileContent);
    printFileContent(fileContent);
    /* parse file to Chase object */
    chaseManager->readAttrString(fileContent[0]);
    chaseManager->parseFdAndMvd(fileContent);
    chaseManager->printChase();
    
    
    return isReadSuccess ? EXIT_SUCCESS : EXIT_FAILURE;
}

