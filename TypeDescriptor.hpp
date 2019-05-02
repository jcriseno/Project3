//
// Created by smith on 3/18/2019.
//

#ifndef EXPRINTER_TYPEDESCRIPTOR_HPP
#define EXPRINTER_TYPEDESCRIPTOR_HPP

#include <iostream>

class TypeDescriptor {
public:
    enum types { INTEGER, DOUBLE, STRING, BOOL };

    int getIntValue();
    std::string getStringValue();
    double getDoubleValue();
    bool getBoolValue();
    types getTypeValue();
    bool isEqual( int b);

    TypeDescriptor keepTogether(TypeDescriptor a, TypeDescriptor b);
    TypeDescriptor floorDivision(TypeDescriptor a, TypeDescriptor b);

    TypeDescriptor & operator = (const int &d);
    TypeDescriptor & operator = (const double &d);
    TypeDescriptor & operator = (const std::string &d);
    TypeDescriptor & operator = (const bool &d);

    //Operations
    friend std::ostream & operator << (std::ostream &out, const TypeDescriptor &c);
    TypeDescriptor operator - ();
    TypeDescriptor operator + ( TypeDescriptor &d);
    TypeDescriptor operator == ( TypeDescriptor &d);
    TypeDescriptor operator - ( TypeDescriptor &d);
    TypeDescriptor operator * ( TypeDescriptor &d);
    TypeDescriptor operator / ( TypeDescriptor &d);
    TypeDescriptor operator % ( TypeDescriptor &d);
    TypeDescriptor operator > ( TypeDescriptor &d);
    TypeDescriptor operator >= ( TypeDescriptor &d);
    TypeDescriptor operator < ( TypeDescriptor &d);
    TypeDescriptor operator <= ( TypeDescriptor &d);
    TypeDescriptor operator != ( TypeDescriptor &d);
    TypeDescriptor operator || ( TypeDescriptor &d);
    TypeDescriptor operator && ( TypeDescriptor &d);
    TypeDescriptor operator ! ( void );

    TypeDescriptor();
    ~TypeDescriptor();

private:
    int _intValue = 0;
    std::string _stringValue = "";
    double _doubleValue = 0.0;
    bool _boolValue;
    types _type;

};

#endif //EXPRINTER_TYPEDESCRIPTOR_HPP
