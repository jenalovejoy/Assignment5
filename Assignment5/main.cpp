//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy
//  This client searches three forms of data structures and outputs the search times

#include "Product.hpp"
#include "BSTScanner.hpp"
#include "ArrayScanner.hpp"
#include "HashScanner.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;

const double timeScale = 1000.0 / CLOCKS_PER_SEC;

int itemCount;
bool counted = false;

void scan(Scanner<Product>* scanner, const char * fileName) { //polymorphic function

    ifstream fileStream;
    fileStream.open(fileName);
    string inputString;
    string code;
    string info;

    while (getline(fileStream, inputString)){
        // input string up to new line
        int split = (int) inputString.find(",");
        code = inputString.substr(0, split);
        info = inputString.substr(split + 1);
        
        // Once info is obtained -> build
        Product *item = new Product(code, info);
        scanner->scan(*item);
        
        if (!counted){
            itemCount++;
        }
    }
    if (!counted){
        counted = true;
    }
}

// Given a dummy Product, returns the full Product if found, and the dummy if not
Product& search(Product *codeArray, Product &code){
    
    for (int i = 0; i <= itemCount; i++){
        if (codeArray[i] == code) {
            return codeArray[i];
        }
    }
    return code;
}

int main(int argc, const char * argv[]) {
    const char * fileName = argv[1];
    
    BinarySearchTree<Product> bst;
    Scanner<Product> *scanner = new BSTScanner<Product>(bst);
    scan(scanner, fileName);
    
    Product *array = new Product[1050000];
    scanner = new ArrayScanner<Product>(array);
    scan(scanner, fileName);
    
    HashTable<Product> hashTable;
    scanner = new HashScanner<Product>(hashTable);
    scan(scanner, fileName);
    
    string exampleCodes[] = {"8717644525098", "71000", "459136", "41570059012", "60410047613", "00000", "725177540363"};
    // Item numbers 680, 76407, 660896, 67170, 1035244, non-existant, and 1
    int iterations = 100;
    int numExamples = 7;
    clock_t arrayTimeSum = 0;
    clock_t bstTimeSum = 0;
    clock_t hashTimeSum = 0;

    // Outside loop tests the example code cases 100 times, then finds the average length of the searches performed
    // Inside success cout statements kept as an additional option in testing
    for (int i = 0; i < iterations; i++){
        
        for (string code : exampleCodes){
            Product *searchCode = new Product(code, "");
            clock_t start;
            clock_t finalTime;
            
            start = clock();
            // Product arrayResult(search(array, *searchCode));
            search(array, *searchCode);
            finalTime = clock() - start;
            arrayTimeSum += finalTime;
            
            start = clock();
            // Product *bstResult(&bst.search(*searchCode));
            bst.search(*searchCode);
            finalTime = clock() - start;
            bstTimeSum += finalTime;

            start = clock();
            // Product *hashResult(&hashTable.search(*searchCode));
            hashTable.search(*searchCode);
            finalTime = clock() - start;
            hashTimeSum += finalTime;

        }
    }
    
    double arrayAverage = ((double) arrayTimeSum / (numExamples * iterations)) * timeScale;
    double bstAverage = ((double) bstTimeSum / (numExamples * iterations)) * timeScale;
    double hashAverage = ((double) hashTimeSum / (numExamples * iterations)) * timeScale;

    cout << "average search times: " << endl;
    cout << "array: " << arrayAverage << endl;
    cout << "bst: " << bstAverage << endl;
    cout << "hash table: " << hashAverage << endl;
 }
