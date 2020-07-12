#ifndef CPPFASTPRIME_USEFUL_FUNCTIONS_H
#define CPPFASTPRIME_USEFUL_FUNCTIONS_H
#include <cmath>
#include <vector>

bool IsPrime(int ToCheck) {
    if (ToCheck == 2) {
        return true;
    }
    if (ToCheck < 2) {
        return false;
    }

    if (ToCheck % 2 != 0) {
        for (int i = 3; i <= sqrt(ToCheck); i += 2) {
            if (ToCheck % i == 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

std::vector<int> RangePrime(int start, int end, std::vector<std::vector<int>>& output, int subsection) {
    std::vector<int> test;
    for (int i = start; i < end; i++) {
        if (IsPrime(i)) {
            test.push_back(i);
        }
    }
    output[subsection] = test;
    return test;
}

#endif //CPPFASTPRIME_USEFUL_FUNCTIONS_H
