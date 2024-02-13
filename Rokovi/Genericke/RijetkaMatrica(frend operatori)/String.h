//
// Created by User on 2/13/2024.
//

#ifndef ROK3_STRING_H
#define ROK3_STRING_H
#include "string"
#include "iostream"
using namespace std;

class String {
private:
    char* data;
    int cap;
public:
    String(char* data);
    String(const String& a);
    String operator+(String a) const;

    String& operator+=(char a);
    bool operator=(String& s) const;

    friend ostream& operator<<(ostream& os, String& s);
};


#endif //ROK3_STRING_H
