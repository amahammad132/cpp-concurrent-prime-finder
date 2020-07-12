#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <valarray>
#include "useful_functions.h"

#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD_RED "\033[1m\033[31m"
#define RESET "\033[0m"

using namespace std;

// these are deprecated constants
const int THREADS = 12;
const int STARTING = 1;
const int ENDING = 1000000;

int main(int argc, char **argv) {
#ifdef __INTEL_COMPILER
    cout << BLUE << "intel compiler used" << RESET << endl;
#elif defined(__GNUC__)
    cout << BLUE << "gcc compiler used" << BLUE << endl;
#endif
    auto start = chrono::system_clock::now();

    int starting = 1;
    int ending = 1000000;
    int threads = 12;

    if (argc == 1) {
        cout << BOLD_RED << "Example usage: ./program_name -t 48 -r 1 1000000" << RESET << endl;
    } else {
        for (int i = 0; i < argc; i++) {
            string arg = static_cast<string>(argv[i]);
            switch (argv[i][1]) {
                case 'r':
                    sscanf(argv[i + 1], "%d", &starting);
                    sscanf(argv[i + 2], "%d", &ending);
                    break;
                case 't':
                    sscanf(argv[i + 1], "%d", &threads);
            }
//            if (arg == "-r") {
//                sscanf(argv[i + 1], "%d", &starting);
//                sscanf(argv[i + 2], "%d", &ending);
//            } else if (arg == "-t") {
//                sscanf(argv[i + 1], "%d", &threads);
//            }
        }

    }

    vector<int> all_primes[threads];
    auto testfn = [&](int start, int stop, int idx) {
        for (int i = start; i <= stop; i++) {
            if (IsPrime(i)) {
                all_primes[idx].push_back(i);
            }
        }
    };

    vector<thread> ThreadVector;
//    int input_start = 0;
//    int input_end = 0;
//    int end_val = 0;
//    int interval = (ending - starting) / threads;
    /*for (int i = 0; i < threads; i++) {
        input_start += end_val + starting;
        input_end += end_val + interval;

        if (i == threads - 1) input_end = ending;
        cout << YELLOW << "RangePrime(" << input_start << ", " << input_end << ")" << RESET << endl;
        ThreadVector.emplace_back(thread(testfn, input_start, input_end, i));

        input_start = input_end;
    }*/
    int input_start = starting;
    int input_end;
    int interval = (ending - starting) / threads;
    for (int i = 0; i < threads; i++) {
        input_end = input_start + interval;

        if (i == threads - 1) input_end = ending;
        cout << YELLOW << "RangePrime(" << input_start << ", " << input_end << ")" << RESET << endl;
        ThreadVector.emplace_back(thread(testfn, input_start, input_end, i));

        input_start = input_end;
    }

    for (auto& t : ThreadVector) {
        t.join();
    }

    int numeros_of_primes = 0;
    int index = 0;
    for (const auto& section : all_primes) {
        cout << endl << "thread #" << index + 1 << " -> ";
        numeros_of_primes += section.size();
        for (const auto prime : section) {
            cout << prime << ", ";
        }
        index++;
    }

//    cout << endl << "Global variable storing number of primes: " << num_of_primes << endl;
//    cout << endl << "Local variable storing number of primes: " << numeros_of_primes << endl;
    cout << endl << endl << "Number of threads used: " << threads << endl;
    cout << "There are " << numeros_of_primes << " primes in between " << starting << " and " << ending << ".";
    cout << endl << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "ms\n";
    return 0;
}
