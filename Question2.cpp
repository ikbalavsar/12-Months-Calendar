// Name : Gülsüm İkbal Avşar - 64180006
// Course : Programming for Engineers - Fall 2021-2022
//           Question-2
// Purpose : The question wants from us to find the prime number
//           from an array basically. This array will be created with result of
//           a mathematical expression which is 3^k - 2^k. k will be
//           between 0 and 32.

#include <iostream>

using namespace std;

int powerResult(int power); // to calculate the power values.

int main() {

    for(int k = 0; k < 32 ; k++){
        int pn2 = 1;
        int check = 0; // to specify the result is prime or not
        pn2 = powerResult(k);
        // After we calculated the result of subtraction, we should check whether the result is prime or not.
        for(int i = 2; i < pn2 ; i++){
            if(pn2 % i == 0){
                check = 0; // if the result is able to divide for a value between 2 and itself, it is not prime. So, loop will finish.
                break;
            }else{
                check = 1; // if result is not prime, check will be 1.
            }
        }
        if(check == 1){ // to determine the prime values, we look at the check value and display it.
            cout << pn2 << endl;
        }
    }
    return 0;
}

// Calculating 3^k and 2^k will be performed by this function.
// The parameter power is k which came from main module above.
// Also, after we calculated the 3^k and 2^k, the next operation which is subtraction
// is calculated in this function. We returned the integer result to main module.
int powerResult(int power){
    int pn = 0;
    int value3 = 1 ;
    int value2 = 1;

    for(int i = 0; i < power ; i++){
        value3 *= 3;
        value2 *= 2;
    }
    pn = value3 - value2;
    return pn;
}

