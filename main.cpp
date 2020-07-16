#include <QApplication>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "useful_functions.h"
#include "qt_parts.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define RED "\033[31m"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MyWidget widget;

    int threads = widget.inputBox.threads;
    int starting = widget.inputBox.start;
    int ending = widget.inputBox.end;

    auto start = chrono::system_clock::now();


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
        for (const auto prime : section) {
            cout << prime << "," << endl;
            widget.outputBox.addItem(prime);
        }
        numeros_of_primes += section.size();
        index++;
    }


    cout << endl << endl << "Number of threads used: " << threads << endl;
    cout << "There are " << RED << numeros_of_primes << RESET << " primes between " << starting << " and " << ending << "." << endl;
    cout << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "ms" << endl;

    widget.outputBox.outputPrimes.setWindowTitle(QString::fromStdString("There are " + to_string(numeros_of_primes) + " primes between " + to_string(starting) + " and " + to_string(ending) + "."));
    widget.outputBox.outputPrimes.show();

    return QApplication::exec();
}