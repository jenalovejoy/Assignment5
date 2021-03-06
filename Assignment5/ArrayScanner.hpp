//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy
//  ArrayScanner.hpp creates a scanner to be used to populate the Array database


#ifndef ArrayScanner_hpp
#define ArrayScanner_hpp

#include <stdio.h>
#include "Scanner.hpp"
#include "Product.hpp"

template <class T>
class ArrayScanner: public Scanner<T>{
    
    T* database;
    int index;
    
public:
    ArrayScanner(T* _database){
        database = _database;
        index = 0;
    }
    
    void scan(T& product){
        database[index] = product;
        index++; // keep track of the end
    }
    
    void setDatabase(T* _database){
        database = _database;
    }
    
    ~ArrayScanner(){
        delete database;
    }
    
    int getSize(){
        return index;
    }
};


#endif /* ArrayScanner_hpp */
