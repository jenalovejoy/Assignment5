//
//  ArrayScanner.hpp
//  Assignment5
//
//  Created by Jena Lovejoy on 12/5/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

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
        database[index] = product; // find the end
        index++;
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
