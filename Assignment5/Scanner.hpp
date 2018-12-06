//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy

#ifndef Scanner_hpp
#define Scanner_hpp
#include <stdio.h>
using namespace std;

template <class T>
class Scanner{
    
public:
    virtual void scan(T& product) = 0;
    virtual ~Scanner(){}
};


#endif /* Scanner_hpp */
