// Copyright (C) 2016 Amir Baserinia

// Computing pi at compile time.

// The output of the program is:
//  pi<10> = 3.14110602160138
//  pi<20> = 3.14159229874034
//  pi<30> = 3.14159265330116
//  pi<40> = 3.14159265358955
//  pi<50> = 3.14159265358979
//  M_PI   = 3.14159265358979

#include <cstdio> // printf
#include <cmath> // M_PI

template<unsigned n> struct pi {
    constexpr static double r = (double)n*pi<n-1>::r/(double)(2*n+1);
    constexpr static double p = pi<n-1>::p + pi<n>::r;
};

template<> struct pi<0> {
    constexpr static double r = 2.0, p = 2.0;
};

int main()
{
    printf("pi<10> = %.15g\n", pi<10>::p);
    printf("pi<20> = %.15g\n", pi<20>::p);
    printf("pi<30> = %.15g\n", pi<30>::p);
    printf("pi<40> = %.15g\n", pi<40>::p);
    printf("pi<50> = %.15g\n", pi<50>::p);
    printf("M_PI   = %.15g\n", M_PI);
    return 0;
}

