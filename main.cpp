#include <iostream>

// used for returning two variables from one method.
struct Fraction {
    int numerator;
    int denominator;
    std::string to_string() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};

bool recursiveIsPowerOf2(int num) {
    // base case
    if (num <= 0) return false;
    if (num == 1) return true;
    if (num % 2 != 0) return false;
    return recursiveIsPowerOf2(num / 2);
}

bool result_is_power_of_2(int num) {
    if (num <= 0) return false;
    return (num & (num - 1)) == 0; // Got help from a friend.
    // Would like further help explaining how bitwise functions work.
}

void power_of_two_test() {
    /*
    for (int i = 0; i < 50; i++) {
        bool iterativeResult = result_is_power_of_2(i);
        bool recursiveResult = recursiveIsPowerOf2(i);

        if (iterativeResult && recursiveResult) {
            printf("%d is a power of 2\n", i);
        }
        else if (!iterativeResult && !recursiveResult) {
            printf("%d is not a power of 2\n", i);
        }
        else {
            printf("ERROR: Mismatch for %d! Iterative: %d, Recursive: %d\n",
                   i, iterativeResult, recursiveResult);
        }
    }
    */

    if (result_is_power_of_2(32) && result_is_power_of_2(16) && result_is_power_of_2(8) &&
        recursiveIsPowerOf2(32) && recursiveIsPowerOf2(16) && recursiveIsPowerOf2(8)) {
        std::cout << "PASS" << std::endl;
        }
    else {
        std::cout << "FAIL" << std::endl;
    }
}

bool isPrime(int num) {
    if (num <= 1) return false;
    else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

void isPrimeTest() {
    if (isPrime(2) && isPrime(3) && isPrime(11) && isPrime(101) && !isPrime(4)) {
        std::cout<<"PASS"<< std::endl;
    }
    else {
        std::cout<<"FAIL"<<std::endl;
    }
}

int findGCD(int nu, int de) {
    int num1 = nu;
    int num2 = de;
    if (num1 < 0) {
        num1 = -num1;
    }
    if (num2 < 0) {
        num2 = -num2;
    }
    int minVal;
    if (num1 > num2) {
        minVal = num2;
    } else {
        minVal = num1;
    }
    for (int i = minVal; i >= 1; i--) {
        if (num1 % i == 0 && num2 % i == 0) {
            return i;
        }
    }
    return 1;
}
// Created a struct to be able to output two outputs (nu and de) to be used for tests.
Fraction fractionSimplifier(int nu, int  de) {
    if (de == 0) {
        std::cout<<"Denominator 0 error"<<std::endl;
    }
    if (nu == 0) {
        std::cout<<"Simplified fraction: 0/1"<<std::endl;
    }
    else {
        if (de < 0) {
            nu = -nu;
            de = -de;
        }
        const int gcd = findGCD(nu,de);
        return {nu / gcd, de / gcd};
    }
}

void fractionSimplifierTest() {
    if (fractionSimplifier(2,4).numerator == 1 && fractionSimplifier(2,4).denominator == 2
        && fractionSimplifier(2,3).numerator == 2 && fractionSimplifier(2,3).denominator == 3
        && fractionSimplifier(3,2).numerator == 3 && fractionSimplifier(3,2).denominator == 2
        && fractionSimplifier(12,14).numerator == 6 && fractionSimplifier(12,14).denominator == 7
        && fractionSimplifier(12,18).numerator == 2 && fractionSimplifier(12,18).denominator == 3) {
        std::cout<<"PASS"<<std::endl;
    }
    else {
        std::cout<<"FAIL"<<std::endl;
    }
}


int main() {
    power_of_two_test();
    isPrimeTest();
    fractionSimplifierTest();
    return 0;
}

