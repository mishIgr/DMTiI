#ifndef num_cpp
#define num_cpp

#include "num.h"
#include <stdexcept>
#include <algorithm>

Num::Num() : is_negative(false), size(0), num(nullptr) {}

Num::Num(const std::string const_num_str) : Num() {
    std::string num_str(const_num_str);
    if (num_str[0] == '-') {
        num_str = num_str.substr(1);
        this->is_negative = true;
    }

    for (char c : num_str)
        if (!std::isdigit(c))
            throw std::logic_error("Object Num exept a string of numbers");

    this->size = (num_str.size() + 1) / 2;
    this->num = new char[this->size];

    for (unsigned long long i = 0; i < this->size; ++i) {
        std::string tmp = num_str.substr((num_str.size() - 2) < num_str.size() ? (num_str.size() - 2) : 0, num_str.size());
        num_str = num_str.substr(0, num_str.size() - 2);
        this->num[i] = std::stoi(tmp);
    }
}

Num::Num(const Num& other) : is_negative(other.is_negative), size(other.size) {
    this->num = new char[this->size];
    std::copy(other.num, other.num + other.size, this->num);
}

Num::Num(Num&& other) : is_negative(false), size(0), num(nullptr) { this->swap(other); }

Num::~Num() { delete [] this->num; }

Num& Num::operator=(const Num& other) {
    if (this == &other)
        return *this;
    
    Num tmp(other);
    this->swap(tmp);
    return *this;
}

Num& Num::operator=(Num&& other) {
    if (this == &other)
        return *this;
    
    this->swap(other);
    return *this;
}

void Num::swap(Num& other) {
    std::swap(this->num, other.num);
    std::swap(this->size, other.size);
    std::swap(this->is_negative, other.is_negative);
}

Num Num::operator-() const {
    Num negative_num(*this);
    negative_num.is_negative = !negative_num.is_negative;
    return negative_num;
}

Num Num::operator+(const Num& other) const {
    Num sum_num;
    sum_num.num = new char[std::max(this->size, other.size) + 1];

    int tmp_sum = 0;
    int next_discharge = 0;
    for (unsigned long long i = 0; i < std::max(this->size, other.size); ++i) {
        sum_num.size++;
        tmp_sum = next_discharge;
        if (i < this->size)
            tmp_sum += (other.is_negative && this->size < other.size ? -1 : 1) * (this->is_negative && this->size < other.size ? -1 : 1) * this->num[i];
        if (i < other.size)
            tmp_sum += (other.is_negative && this->size > other.size ? -1 : 1) * (this->is_negative && this->size > other.size ? -1 : 1) * other.num[i];
        sum_num.num[i] = (tmp_sum + 200) % 100;
        next_discharge = (tmp_sum - sum_num.num[i]) / 100;
    }

    sum_num.is_negative = (this->size < other.size ? other.is_negative : false) | (this->size > other.size ? this->is_negative : false);

    if (next_discharge)
        sum_num.num[sum_num.size++] = abs(next_discharge);

    while (sum_num.num[sum_num.size - 1] == 0 && sum_num.size > 1)
        sum_num.size--;

    return sum_num;
}

Num Num::operator-(const Num& other) const { return *this + (-other); }

std::string Num::str_num() const {
    std::string str_num = "";
    for (unsigned long long i = 0; i < this->size; ++i) {
        str_num = std::to_string(this->num[i]) + str_num;
        if (str_num.size() % 2)
            str_num = '0' + str_num;
    }

    if (str_num[0] == '0') 
        str_num = str_num.substr(1);

    if (this->is_negative)
        str_num = "-" + str_num;
    return str_num;
}

std::ostream& operator<<(std::ostream& os, const Num& num) {
    os << num.str_num() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Num& num) {
    std::string num_str;
    std::getline(is, num_str, ' ');
    Num tmp_num(num_str);
    num = tmp_num;
    return is;
}

#endif