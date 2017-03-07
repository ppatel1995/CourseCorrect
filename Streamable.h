//
//  Streamable.h
//  ms3
//
//  Created by Parth Patel on 2016-08-09.
//  Copyright © 2016 Parth Patel. All rights reserved.
//

#ifndef Streamable_h
#define Streamable_h
#include <fstream>
#include <iostream>

using namespace std;


class Streamable
{
public:
    
    virtual fstream& store(fstream& file, bool addNewLine = true) const = 0;
    virtual fstream& load(std::fstream& file) = 0;
    virtual ostream& display(ostream& os) const = 0;
    virtual istream& read(istream& is) = 0;
};

#endif /* Streamable_h */
