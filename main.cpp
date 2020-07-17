#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <sstream>
#include "useful_functions.h"

#define YELLOW "\033[33m"
#define BOLD_RED "\033[1m\033[31m"
#define GREEN "\033[92m"
#define CYAN "\033[96m"
#define RESET "\033[0m"
#define RED "\033[31m"

using namespace std;

int main(int argc, char **argv) {
    auto starting_time = chrono::high_resolution_clock::now();

    int starting = 1;
    int ending = 1000000;
    int threads = 12;

    if (argc == 1) {
        cout << BOLD_RED << "Example usage: ./program_name -t 48 -r 1 1000000" << RESET << endl;
    } else {
        for (int i = 0; i < argc; i++) {
            stringstream arg;
            switch (argv[i][1]) {
                case 'r':
                    sscanf(argv[i + 1], "%d", &starting);
                    sscanf(argv[i + 2], "%d", &ending);
                    break;
                case 't':
                    sscanf(argv[i + 1], "%d", &threads);
                    break;
                case 'h':
                    show_help();
                    break;
            }
        }

    }

    vector<int> all_primes[threads];
    auto RangePrime = [&](int start, int stop, int idx) {
        for (int i = start; i <= stop; i++) {
            if (IsPrime(i)) {
                all_primes[idx].push_back(i);
            }
        }
    };

    vector<thread> ThreadVector;
    int input_start = starting;
    int input_end;
    int interval = (ending - starting) / threads;
    for (int i = 0; i < threads; i++) {
        input_end = input_start + interval;
        if (i == threads - 1) input_end = ending;

        cout << YELLOW << "RangePrime(" << input_start << ", " << input_end << ")" << RESET << endl;
        ThreadVector.emplace_back(thread(RangePrime, input_start, input_end, i));

        input_start = input_end + 1;
    }

    for (auto &t : ThreadVector) {
        t.join();
    }

    int numeros_of_primes = 0;
    int index = 0;
    for (const auto &section : all_primes) {
        cout << endl << "thread #" << index + 1 << " -> ";
        numeros_of_primes += section.size();
        for (const auto prime : section) {
            cout << prime << ", ";
        }
        index++;
    }


    auto ending_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double, milli>(ending_time - starting_time).count();
    cout << endl << endl << "Number of threads used: " << threads << endl;
    cout << "There are " << RED << numeros_of_primes << RESET << " primes between " << starting << " and " << ending << "." << endl;
    cout << "elapsed time: " << duration << "ms" << endl;
    return 0;
}