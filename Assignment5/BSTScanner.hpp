//
//  BSTScanner.hpp
//  Assignment5
//
//  Created by Jena Lovejoy on 12/5/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

#ifndef BSTScanner_hpp
#define BSTScanner_hpp

#include "Scanner.hpp"
#include "Product.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

template <class T>
class BSTScanner: public Scanner<T>{
    
    BinarySearchTree<T> database;
    
public:
    BSTScanner(BinarySearchTree<T> _database):database(_database){}
    
    void scan(T& product){
        database.insert(product);
    }
    
    void setDatabase(BinarySearchTree<T> _database){
        database = _database;
    }
    
};

#endif /* BSTScanner_hpp */
