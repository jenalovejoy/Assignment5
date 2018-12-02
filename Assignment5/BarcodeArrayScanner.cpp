//  CS 300 Assignment 4 due 11/21
//  Jena Lovejoy
//  BarcodeArrayScanner.cpp builds an array of Barcodes, given a text file,
//  and then performs search on them and shows the speed of the search

#include "Barcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;

// NOTE: const currently commented out as only one main() can run at a time
// const double timeScale = 1000.0 / CLOCKS_PER_SEC; // translates to milliseconds

// Parses the file, then builds an array of Barcodes
int buildArray(Barcode *codeArray, const char * fileName){
    
    ifstream fileStream;
    fileStream.open(fileName);
    string inputString;
    string code;
    string info;
    int index = 0;
    
    while (getline(fileStream, inputString)){
        // input string up to new line
        int split = (int) inputString.find(",");
        code = inputString.substr(0, split);
        info = inputString.substr(split + 1);
        
        // Once info is obtained -> build
        Barcode *newBarcode = new Barcode(code, info);
        codeArray[index] = *newBarcode;
        index++;
    }
    
    return index - 1;
}

// Given a dummy Barcode, returns the full Barcode if found, and the dummy if not
Barcode& search(Barcode *codeArray, int size, Barcode &code){
    
    for (int i = 0; i <= size; i++){
        if (codeArray[i] == code) {
            return codeArray[i];
        }
    }
    return code;
}
/*
 // Runs tests and calculates the time required for searches within this tree
int main(int argc, const char * argv[]) {
 
    const char * fileName = argv[1];
    Barcode *codeArray = new Barcode[1050000];
  
    int size = buildArray(codeArray, fileName);
 
    string exampleCodes[] = {"8717644525098", "71000", "459136", "41570059012", "60410047613", "00000", "725177540363"};
    // Item numbers 680, 76407, 660896, 67170, 1035244, non-existant, and 1
    int iterations = 100;
    int numExamples = 7;
    clock_t timeSum = 0;
 
    // Outside loop tests the example code cases 100 times, then finds the average length of the searches performed
    // Inside success cout statements kept as an additional option in testing
    for (int i = 0; i < iterations; i++){
 
        for (string code : exampleCodes){
            Barcode *searchCode = new Barcode(code, "");
            clock_t start;
            clock_t finalTime;
            
            start = clock();
            Barcode result(search(codeArray, size, *searchCode));
            finalTime = clock() - start;
            
            // Without the iterations * numExamples number of searches,
            // with a smaller set information can be displayed with this
            if (searchCode != result){
                // cout << "Item found: \n" << *result;
            } else {
                // cout << "Item not found: ";
            }
            // cout << "search took: " << (double) finalTime * timeScale << " milliseconds" << endl;

            timeSum += finalTime;
        }
    }
 
    double average = ((double) timeSum / (numExamples * iterations)) * timeScale;
    cout << "average search time: " << average << " milliseconds." << endl;
   
}
*/
