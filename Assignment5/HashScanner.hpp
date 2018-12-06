//
//  BSTScanner.hpp
//  Assignment5
//
//  Created by Jena Lovejoy on 12/5/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

#ifndef HashScanner_hpp
#define HashScanner_hpp

#include "Scanner.hpp"
#include "HashTable.hpp"

using namespace std;

template <class T>
class HashScanner: public Scanner<T>{
    
     HashTable<T> database; // database of T pointers
    
public:
    HashScanner(HashTable<T> _database){
        database = _database;
    }
    
    void scan(T& product){
        database.insert(product);
    }
    
    void setDatabase(BinarySearchTree<T> _database){
        database = _database;
    }
    
};

#endif /* HashScanner_hpp */
