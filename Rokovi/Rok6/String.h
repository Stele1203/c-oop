//
// Created by User on 2/2/2024.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H


class String {
private:
    char* data;
    int cap;
public:


    String(const String& s1);
    String(char* data);

    String operator+(const String& s1);
    String& operator+=(const char& a);

    bool operator==(const String& s1) const;
    int duzina();
    void ispisi();

    friend ostream& operator<<(ostream& os, const String& s1);
};


#endif //STRING_STRING_H
