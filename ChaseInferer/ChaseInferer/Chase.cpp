//
//  Chase.cpp
//  ChaseInferer
//
//  Created by Junwei Hu on 9/17/14.
//  Copyright (c) 2014 Junwei Hu. All rights reserved.
//

#include "Chase.h"


/* attribute list */
//string attr_list;
//unordered_set<string> seed;


/* generate the seed for start of chase */
Chase::Chase() {
    //attr_list = "";
}
Chase::~Chase() {
}
/*
unordered_set<string> Chase::generateSeed() {
    int attr_num = this->attr_list.length();
    
}*/


/* read the first line of the file */
void Chase::readAttrString(string attrbutes) {
    for (int i = 0; i < attrbutes.length(); i++) {
        if (isalpha(attrbutes[i]) ) {
            attr_list += attrbutes[i];
        }
    }
}

/* remove the format ','*/
string Chase::removeFormat(string s) {
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]) || s[i] == ':' ) {
            ans += s[i];
        }
    }
    return ans;
}

/* parse file to Chase object */
void Chase::parseFdAndMvd(vector<string>& fileContent) {
    for (int i = 1; i < fileContent.size(); i++) {
        if (fileContent[i].substr(0, 3) == "fd:") {
            this->fd_strings.push_back(removeFormat(fileContent[i]).substr(3, fileContent[i].length()));
        }
        else if (fileContent[i].substr(0, 4) == "mvd:"){
            this->mvd_strings.push_back(removeFormat(fileContent[i]).substr(4, fileContent[i].length()));
        }
        else if (fileContent[i].substr(0, 6) == "chase:") {
            this->chase_strings.push_back(removeFormat(fileContent[i]).substr(6, fileContent[i].length()));
        }
        else {
            cerr <<  "File content not match!" << endl;
            break;
        }
    }
        
}

/* print chase object */
void Chase::printChase() {
    cout << "-- Chase Object --" << endl;
    cout << this->attr_list << endl;
    for (int i = 0; i < this->fd_strings.size(); i++) {
        cout << fd_strings[i] << endl;
    }
    for (int i = 0; i < this->mvd_strings.size(); i++) {
        cout << mvd_strings[i] << endl;
    }
    for (int i = 0; i < this->chase_strings.size(); i++) {
        cout << chase_strings[i] << endl;
    }
    cout <<  "-- End of Chase Object" << endl;
}




