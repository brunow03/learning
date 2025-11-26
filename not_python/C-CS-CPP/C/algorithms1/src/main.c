#include <stdio.h>
#include <string.h>
#include "hashing.h"

int main(int argc, char const *argv[])
{
    char file1[] = "../data/randInt1k.txt";
    char file2[] = "../data/randInt10k.txt";
    char file3[] = "../data/randInt100k.txt";
    char file4[] = "../data/randInt1M.txt";
    int N, R;
    R = 10000;

    // 1k
    N = 1000;
    direct_addressing(N, R, file1);

    // 10k
    N = 10000;
    direct_addressing(N, R, file2);

    // 100k
    N = 100000;
    direct_addressing(N, R, file3);

    // 1M
    N = 1000000;
    direct_addressing(N, R, file4);

    return 0;
}