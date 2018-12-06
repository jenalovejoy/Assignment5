//  CS 300 Assignment 5 due 12/5
//  Jena Lovejoy
//  Product.hpp represents an inidividual unit of a UPC code and its description

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Product {
protected:
    string UPCCode;
    string info;
    
public:
    Product(){
        Product("", "");
    }
    
    Product(const string &_UPC, const string &_info){
        UPCCode = _UPC;
        info = _info;
    }
    
    ~Product(){
    }
    
    Product(Product &other){
        Product(other.UPCCode, other.info);
    }
    
    Product& operator=(Product &other){
        UPCCode = other.UPCCode;
        info = other.info;
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, Product &code){
        os << "UPC Code: " << code.UPCCode << endl;
        os << "Info: " << code.info << endl;
        
        return os;
    }
    
    friend bool operator==(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) == 0;
        // less than, under 0
    }
    friend bool operator!=(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) != 0;
    }
    friend bool operator>(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) > 0;
    }
    friend bool operator<(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) < 0;
    }
    friend bool operator>=(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) >= 0;
    }
    friend bool operator<=(const Product &A, const Product &B){
        return (A.UPCCode).compare(B.UPCCode) <= 0;
    }
    
    int operator()(){
        int sum = 0;
        int length = (int)(UPCCode).length();
        for (int i = 0; i < length; i++){
            sum += int(UPCCode[i]);
        }
        return sum;
    }
    
};

#endif /* Product_hpp */
