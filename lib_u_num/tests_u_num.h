#ifndef tests_u_num_h
#define tests_u_num_h

#include "u_num.h"
#include <stdexcept>
#include <cassert>

void test_UNum() {
    try {
        UNum a("9a9");
        assert(false);
    } catch (std::logic_error& e) {
        assert(true);
    } catch(std::exception& e) {
        assert(false);
    }
}

void tests_u_num() {
    test_UNum();
}

#endif