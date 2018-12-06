//
//  HashTable.hpp
//  Assignment5
//
//  Created by Jena Lovejoy on 12/5/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "LinkedList.hpp"
using namespace std;


template <class T>
class HashTable {
    // friend class LinkedList<T>;
    LinkedList<T>** table;
    int size;
    int itemCount;
    double loadFactor;
    
    public:
    HashTable(int _size = 13){
        table = new LinkedList<T>*[_size];
        size = _size;
        itemCount = 0;
    }

    void makeEmpty(){
        for (int i = 0; i < size; i++){
            table[i].destroyList();
        }
    }
    
    void insert(T& item){
        int index = hash(item);
        // node<T> *hashItem;
        // hashItem->data = item;
        if (table[index] == NULL){
            cout << "LL added" << endl;
            LinkedList<T>* newList = new LinkedList<T>;
            cout << newList -> head;
            table[index] = newList;
        }
        cout << table[index] << endl;
        
        table[index]->insertFirst(item);
        itemCount++;
        loadFactor = ((double) itemCount) / size;
        if (loadFactor > .75){
            rehash();
            loadFactor = ((double) itemCount) / size;
        }
    }
    
    T& search(T& item){
        int index = hash(item);
        return table[index]->search(item);
    }
    
    void remove(T& item){
        int index = hash(item, size);
        table[index].deleteNode(item);
        
    }
    
    void rehash(){
        cout << "hashy boy" << endl;
        int oldSize = size;
        size = size * 3;
        LinkedList<T>** newList = new LinkedList<T>*[size];
        for (int i = 0; i < oldSize; i++){
            if (table[i] != NULL){
                node<T> *temp = table[i]->head;
                while (temp != NULL){
                    int index = hash(temp->data);
                    if (newList[index] == NULL){
                        table[index] = new LinkedList<T>;
                    }
                    newList[index]->insertFirst(temp->data);
                    temp = temp->next;
                }
            }
            
        }
        
        LinkedList<T>** oldList = table;
        table = newList;
        delete[] oldList;
    }
    /*
    int hash(const string &key, int tableSize){
        int sum = 0;
        int length = (int)(key).length();
        for (int i = 0; i < length; i++){
            sum += int(key[i]);
        }
        return sum % tableSize;
    }
    
    int hash(int key, int tableSize){
        return key % tableSize;
    }
    */
    int hash(T& item){
        int hashCode = item();
        return hashCode % size;
    }
    // const HashTable & operator=( const HashTable & rhs );
    
};





#endif /* HashTable_hpp */
