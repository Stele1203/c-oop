//
// Created by User on 2/13/2024.
//

#include "String.h"
#include <string.h>



String::String(char *data) {
    int a= strlen(data);
    this->cap=a;
    this->data= new char[a+1];
    for(int i=0;i<a;i++){
        this->data[i]=data[i];
    }
    this->data[a]='\0';
}

String::String(const String& a) {
    this->data= new char[a.cap];
    for(int i=0;i<a.cap;i++){
        this->data[i]=a.data[i];
    }
    this->cap=a.cap;
}

String String::operator+(String a) const {
    char* tmp= new char[a.cap+this->cap+1];
    for(int i=0;i<this->cap;i++){
        tmp[i]=this->data[i];
    }

    for(int i=0;i<a.cap;i++){
        tmp[i+cap]=a.data[i];
    }
    tmp[a.cap+this->cap]='\0';
    String tmpString(tmp);
    return tmpString;
}

String &String::operator+=(char a) {
    cout<<endl<<"AAAAAAAAAAAAAAAAAAAAAAAA "<<strlen(this->data) <<" "<< this->cap<<endl;
    if(strlen(this->data)== this->cap){
        char* tmp= new char[cap+1];
        for(int i=0;i<cap;i++){
            tmp[i]=this->data[i];
        }
        tmp[cap]='\0';
        delete[] this->data;
        this->data=new char[cap+2];
        for(int i=0;i<cap;i++){
            this->data[i]=tmp[i];
        }
        delete[] tmp;
    }

    this->data[cap]=a;
    this->data[cap+1]='\0';
    //cap++;
    return *this;
}

bool String::operator=(String &s) const {
    if(this->cap != s.cap){
        return false;
    }
    for(int i=0;i<this->cap;i++){
        if(this->data[i] != s.data[i]){
            return false;
        }
    }
    return true;
}


ostream& operator<<(ostream& os, String& s){
    os<<s.data<<" "<<s.cap<<endl;
    return os;
}