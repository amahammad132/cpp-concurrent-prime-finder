#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>
#define THREADS_D 12
#define STARTING_D 1
#define ENDING_D 1000000

using namespace std;

vector<int> RangePrime(int start, int end);

const int THREADS = 4;
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
        for (int i = 3; i <= floor(sqrt(ToCheck)); i += 2) {
            if (ToCheck % i == 0) {
                return false;
            }
        }
        return true;
    } else {
        return false; // even numbers(excluding 2) are composite
    }
}

vector<int> RangePrime(int start, int end, vector<vector<int>>& output, int subsection) {
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


int main() {
    auto start = chrono::system_clock::now();

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

    vector<vector<int>> my_range = vector<vector<int>>(5);

    RangePrime(1, 250000, my_range, 0);
    RangePrime(250000, 500000, my_range, 1);
    RangePrime(500000, 750000, my_range, 2);
    RangePrime(750000, 1000000, my_range, 4);
    int index = 0;
    for (auto & i : my_range) {
        cout << endl << "index " << index << " -> ";
        for (auto & j : i) {
            cout << j << ' ';
        }
        index++;
    }


    cout << endl << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "ms\n";
    return 0;
}
