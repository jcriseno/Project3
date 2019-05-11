//
// Created by smith on 3/18/2019.
//

#ifndef EXPRINTER_TYPEDESCRIPTOR_HPP
#define EXPRINTER_TYPEDESCRIPTOR_HPP

#include <iostream>
#include <queue>

class TypeDescriptor {
public:
    enum types { INTEGER, DOUBLE, STRING, BOOL };

    int getIntValue();
    std::string getStringValue();
    double getDoubleValue();
    bool getBoolValue();
    types getTypeValue();
    bool isEqual( int b);

    char getSubscript(int i);

    void setIntArray(std::queue<int> a, int i);
    bool isIntArray();
    std::queue<int> getIntArray();
    void setDoubleArray(std::queue<double> a, double d);
    bool isDoubleArray();
    std::queue<double> getDoubleArray();
    void setStringArray(std::queue<std::string> a, std::string s);
    bool isStringArray();
    std::queue<std::string> getStringArray();
    void setBooleanArray(std::queue<bool> a, bool b);
    bool isBooleanArray();
    std::queue<bool> getBooleanArray();
    void setHeterogeneousArray();
    bool isHeterogeneousArray();
    int ArrayType();
    void setArrayType(int t);

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
    bool _intArray = false;
    bool _doubleArray = false;
    bool _stringArray = false;
    bool _boolArray = false;
    bool _heteroArray = false;
    std::queue<int> iArray;
    std::queue<double> dArray;
    std::queue<std::string> sArray;
    std::queue<bool> bArray;
};

#endif //EXPRINTER_TYPEDESCRIPTOR_HPP
