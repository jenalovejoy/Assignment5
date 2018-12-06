//
//  Scanner.hpp
//  Assignment5
//
//  Created by Jena Lovejoy on 12/5/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

#ifndef Scanner_hpp
#define Scanner_hpp
#include <stdio.h>
using namespace std;

template <class T>
class Scanner{
    
public:
    virtual void scan(T& product) = 0;
    virtual ~Scanner(){}
};


#endif /* Scanner_hpp */
