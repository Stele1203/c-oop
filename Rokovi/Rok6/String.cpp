//
// Created by User on 2/2/2024.
//
#include "iostream"
using namespace std;
#include "String.h"
#include <string.h>
#include "algorithm"
String::String(char *data) {
    this->cap = strlen(data) + 1;
    this->data = new char[cap];
    for (int i = 0; i < cap; i++) {
        this->data[i] = data[i];
    }
    this->data[cap - 1] = '\0';
}

int String::duzina() {
    int i=0;
    int brojac;
    while(this->data[i] != '\0'){
        i++;
    }
    return i;
}

String::String(const String &s1) {
    this->cap = s1.cap;
    this->data = new char[this->cap];
    for (int i = 0; i < this->cap; i++) {
        this->data[i] = s1.data[i];
    }
}

String String::operator+(const String &s1) {
    int capAll = this->cap + s1.cap - 1;
    char *tmp = new char[capAll];
    for (int i = 0; i < this->cap - 1; i++) {
        tmp[i] = this->data[i];
    }

    for (int i = 0; i < s1.cap; i++) {
        tmp[i + this->cap - 1] = s1.data[i];
    }

    String s2(tmp);
    return s2;
}

void String::ispisi() {
    //cout << "Cap: " << this->cap << ", Data: ";
    for (int i = 0; i < this->cap - 1; i++) {
        cout << this->data[i] << " ";
    }
    cout << endl;
}

String &String::operator+=(const char &a) {
    //cout<<cap<<endl;
    if(cap == this->duzina()+1){
        char* tmp= new char[cap+1];
        for(int i=0;i<cap-1;i++){
            tmp[i]=this->data[i];
        }
        delete[] this->data;
        this->data=new char[cap+1];
        for(int i=0;i<cap-1;i++){
            this->data[i]=tmp[i];
        }
        this->cap++;
        delete[] tmp;
    }
    //cout<<cap<<" cap2;"<<endl;
    this->data[cap-2]=a;
    this->data[cap-1]='\0';

    return *this;
}

bool String::operator==(const String &s1) const{
    if(this->cap != s1.cap){
        return false;
    }
    for(int i=0;i<cap-1;i++){
        if(this->data[i] != s1.data[i]){
            return false;
        }
    }
    return true;
}

ostream& operator<<(std::ostream &os, const String &s1) {
    os<<"Cap: "<<s1.cap<<" "<<" Elementi: ";
    for(int i=0;i<s1.cap-1;i++){
        os<<s1.data[i]<<" ";
    }
    os<<endl;
    return os;
}