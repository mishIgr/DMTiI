#ifndef num_h
#define num_h

#include <string>
#include <iostream>

class Num {

    char* num;
    unsigned long long size;
    bool is_negative;

    void swap(Num&);

public:

    Num();
    Num(const std::string);
    Num(const Num&);
    Num(Num&&);
    ~Num();

    Num& operator=(const Num&);
    Num& operator=(Num&&);

    Num operator-() const;
    Num operator+(const Num&) const;
    Num operator-(const Num&) const;

    std::string str_num() const;

    friend std::ostream& operator<<(std::ostream&, const Num&);
    friend std::istream& operator>>(std::istream&, Num&);

};

#endif