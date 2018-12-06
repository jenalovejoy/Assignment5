//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy
//  HashTable implementes a hash data structure with separate chaining

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
using namespace std;

template <class T>
struct hashNode { // individual nodes in the chain
    T data;
    hashNode<T> *next;
};

template <class T>
class HashTable {
    hashNode<T>** table;
    
private:
    int size;
    int itemCount;
    double loadFactor;
    
    public:
    
    // Constructs a new HashTable and initializes all head nodes to 0
    HashTable(int _size = 13){
        table = new hashNode<T>*[_size];
        size = _size;
        itemCount = 0;
        
        for (int i = 0; i < size; i++){
            table[i] = NULL;
        }
    }
    
    // Destructor
    ~HashTable(){}
    
    // Assignment operator
    const HashTable & operator=( const HashTable & rhs ){
        makeEmpty();
        for (int i = 0; i < rhs.size; i++){
            hashNode<T> *p = rhs.table[i];
            while (p != NULL){
                table[i] = rhs.table[i];
                p = p->next;
            }
        }
        return *this;
    }
    
    // Copy Constructor
    HashTable(HashTable<T> &table){
        HashTable(table.size);
    }

    // Clears the HashTable
    void makeEmpty(){
        for (int i = 0; i < size; i++){
            hashNode<T> *p = table[i];
            while (table[i] != NULL){
                p = table[i];
                table[i] = table[i]->next;
                delete p;
            }
        }
    }
    
    // inserts a new node first in the list
    void insert(T& item){
        int index = hash(item);
        hashNode<T> *newNode = new hashNode<T>;
        newNode->data = item;
        
        if (table[index] == NULL){
            table[index] = newNode;
            newNode->next = NULL;
        } else {
            hashNode<T> *temp = table[index];
            table[index] = newNode;
            newNode->next = temp;
        }
        
        itemCount++;
        loadFactor = ((double) itemCount) / size;
        if (loadFactor > .75){
            rehash();
            loadFactor = ((double) itemCount) / size;
        }
    }
    
    // Searches for a given item, returning the original if not found
    T& search(T& item){
        int index = hash(item);
        hashNode<T> *temp = table[index];
        while (temp != NULL){
            if (temp->data == item){
                return temp->data;
            }
            temp = temp->next;
        }
        return item;
    }
    
    // Deletes an item from the HashTable
    void remove(T& item){
        int index = hash(item);
        if (table[index] == NULL){
            cout << "Item could not be deleted" << endl;
            return;
        } else if (table[index]->data == item){ // first item
            hashNode<T> *temp = table[index];
            table[index] = table[index]->next;
            delete temp;
            itemCount--;
            
        } else {
            hashNode<T> *curr = table[index];
            hashNode<T> *prev = NULL;
            while (curr != NULL){
                if(curr->data == item){
                    if (curr->next == NULL){ // last item
                        prev = NULL;
                    } else { // middle item
                        prev = curr->next;
                    }
                    
                    delete curr;
                    itemCount--;
                    return;
        
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
            cout << "Item could not be deleted" << endl; // if it is not deleted inside the loop
        }
    }
    
    // Resizes the HashTable and repopulates it with the re-distributed nodes
    void rehash(){
        int oldSize = size;
        size *= 3;
        
        // Creates a new table, initializes it all to null
        hashNode<T>** newTable;
        newTable = new hashNode<T>*[size];
        for (int i = 0; i < size; i++){
            newTable[i] = NULL;
        }
        hashNode<T>** oldTable = table;
        table = newTable; // switches old with new
        itemCount = 0; // resets item count to be updates when re-populating
        
        // Repopulates the new table, rehashing the items
        for (int i = 0; i < oldSize; i++){
            hashNode<T> *temp = oldTable[i];
            while (temp != NULL){
                insert(temp->data);
                temp = temp->next;
            }
        }

        delete[] oldTable;
    }

    // returns a hash code for a given item
    int hash(T& item){
        int hashCode = item();
        return hashCode % size;
    }
    
};

#endif /* HashTable_hpp */
