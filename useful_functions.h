#include <cmath>
#include <vector>

#define GREEN "\033[92m"
#define CYAN "\033[96m"
#define RESET "\033[0m"

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