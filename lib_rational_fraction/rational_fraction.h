#ifndef rational_fraction_h
#define rational_fraction_h

#include "../lib_u_num/u_num.h"
#include "../lib_num/num.h"
#include <string>

class RatFraction {

    Num numer;
    UNum denomin;

    bool is_rational_fraction(std::string);

    void swap(RatFraction&);

public:

    RatFraction();
    RatFraction(const std::string);
    RatFraction(const RatFraction&);
    RatFraction(RatFraction&&);

    RatFraction& operator=(const RatFraction&);
    RatFraction& operator=(RatFraction&&);

    std::string str_frac() const;

};

#endif