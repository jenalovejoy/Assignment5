//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy

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
