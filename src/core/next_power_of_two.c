#include"c_algorithms.h"

/*
    Algorithm from:
    https://graphics.stanford.edu/%7Eseander/bithacks.html#RoundUpPowerOf2
    Credited to Sean Anderson, Pete Hart, and William Lewis
*/
unsigned int nextPowerOfTwo(unsigned int a){
    a--;
    a |= a >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    a++;
    return a;
}