#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>

using namespace std;


const int THREADS = 12;
const int STARTING = 1;
const int ENDING = 1000000;

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
        return false; // even numbers (excluding 2) are composite
    }
}

vector<int> RangePrime(int start, int end, vector<vector<int>> &output, int subsection) {
    vector<int> test;
    for (int i = start; i < end; i++) {
        if (IsPrime(i)) {
            test.push_back(i);
            //cout << i << endl;
        }
    }
    output[subsection] = test;
    return test;
}


int main(int argc, char **argv) {
#ifdef __INTEL_COMPILER
    cout << "intel mode\n";
#elif defined(__GNUC__)
    cout << "gcc mode\n";
#endif
#pragma
    auto start = chrono::system_clock::now();
//    for (int i = 0; i < argc; i++) {
//        char *arg =
//    }
//    int input_start = 0;
//    int input_end = 0;
//    int end_val = 0;
//    int interval = (ENDING - STARTING) / THREADS;
//    for (int i = 0; i < THREADS; i++) {
//        input_start += end_val + STARTING;
//        input_end += end_val + interval;
//
//        printf("RangePrime(%d, %d)\n", input_start, input_end);
//
//        input_start = input_end;
//    }

    //vector<vector<int>> testvec;
//    std::thread p1(RangePrime, 1, 250000, testvec);
//    std::thread p2(RangePrime, 250000, 500000);
//    std::thread p3(RangePrime, 500000, 750000);
//    std::thread p4(RangePrime, 750000, 1000000);

//    p1.join();
//    p2.join();
//    p3.join();
//    p4.join();

//    vector<vector<int>> all_primes = vector<vector<int>>(THREADS);
    vector<int> all_primes[THREADS];
//    RangePrime(1, 250000, my_range, 0);
//    RangePrime(250000, 500000, my_range, 1);
//    RangePrime(500000, 750000, my_range, 2);
//    RangePrime(750000, 1000000, my_range, 4);
    auto testfn = [&](int start, int stop, int idx) {
//        vector<int> test;
        for (int i = start; i <= stop; i++) {
            if (IsPrime(i)) {
                all_primes[idx].push_back(i);
                //cout << i << endl;
            }
        }
    };
//    testfn(1, 1000000, 2);

//    thread p1(testfn, 1, 100000, 0);
//    thread p2(testfn, 100000, 200000, 1);
//    thread p3(testfn, 200000, 300000, 2);
//    thread p4(testfn, 300000, 400000, 3);
//    thread p5(testfn, 400000, 500000, 4);
//    thread p6(testfn, 500000, 600000, 5);
//    thread p7(testfn, 600000, 700000, 6);
//    thread p8(testfn, 700000, 800000, 7);
//    thread p9(testfn, 800000, 900000, 8);
//    thread p10(testfn, 900000, 1000000, 9);
//    p1.join();
//    p2.join();
//    p3.join();
//    p4.join();
//    p5.join();
//    p6.join();
//    p7.join();
//    p8.join();
//    p9.join();
//    p10.join();
    vector<thread> ThreadVector;
    int input_start = 0;
    int input_end = 0;
    int end_val = 0;
    int interval = (ENDING - STARTING) / THREADS;
    for (int i = 0; i < THREADS; i++) {
        input_start += end_val + STARTING;
        input_end += end_val + interval;

        if (i == THREADS - 1) input_end = ENDING;
        printf("RangePrime(%d, %d)\n", input_start, input_end);
        ThreadVector.emplace_back(thread(testfn, input_start, input_end, i));

        input_start = input_end;
    }

    for (auto& t : ThreadVector) {
        t.join();
    }

    int numeros_of_primes = 0;
    int index = 0;
    for (const auto& section : all_primes) {
        cout << endl << "index " << index << " -> ";
        numeros_of_primes += section.size();
        for (const auto prime : section) {
            cout << prime << ' ';
        }
        index++;
    }

//    cout << endl << "Global variable storing number of primes: " << num_of_primes << endl;
    cout << "Local variable storing number of primes: " << numeros_of_primes << endl;
    cout << endl << "There are " << numeros_of_primes << " primes in between " << STARTING << " and " << ENDING << ".";
    cout << endl << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "ms\n";
    return 0;
}
