#include <cmath>
#include <vector>

#define GREEN "\033[92m"
#define CYAN "\033[96m"
#define RESET "\033[0m"

class Human {
public:
    bool gender;
    double age;

    Human(bool gender, double age) {
        this->gender = gender;
        this->age = age;
    }
};

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

//std::vector<int> RangePrime(int start, int end, std::vector<std::vector<int>>& output, int subsection) {
//    std::vector<int> test;
//    for (int i = start; i < end; i++) {
//        if (IsPrime(i)) {
//            test.push_back(i);
//        }
//    }
//    output[subsection] = test;
//    return test;
//}

void show_help() {
    std::cout << CYAN << "Prime Checker: " << std::endl << "Available arguments:" << RESET << std::endl
         << GREEN << "-t N\tRuns program with N threads" << std::endl
         << "-r START STOP\tChecks primes from START to STOP" << RESET << std::endl;
}