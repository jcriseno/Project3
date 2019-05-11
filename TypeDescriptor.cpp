//
// Created by smith on 3/20/2019.
//

#include <iostream>
#include <math.h>
#include "TypeDescriptor.hpp"

int TypeDescriptor::getIntValue() {
    return _intValue;
}

std::string TypeDescriptor::getStringValue() {
    return _stringValue;
}

double TypeDescriptor::getDoubleValue() {
    return _doubleValue;
}

bool TypeDescriptor::getBoolValue() {
    return _boolValue;
}


TypeDescriptor::types TypeDescriptor::getTypeValue() {
    return _type;
}

bool TypeDescriptor::isEqual(int b) {

    if(getTypeValue() == TypeDescriptor::INTEGER) {
        if(getIntValue() == b) {
            return true;
        }
    }
    return false;
}

char TypeDescriptor::getSubscript(int i) {
    char subscript = _stringValue[i];
    return subscript;
}

void TypeDescriptor::setIntArray(std::queue<int> a, int i) {
    a.push(i);
    iArray = a;
    _intArray = true;
}

bool TypeDescriptor::isIntArray() {
    return _intArray;
}

std::queue<int> TypeDescriptor::getIntArray() {
    return iArray;
}

void TypeDescriptor::setDoubleArray(std::queue<double> a, double d) {
    a.push(d);
    dArray = a;
    _doubleArray = true;
}

bool TypeDescriptor::isDoubleArray() {
    return _doubleArray;
}

std::queue<double> TypeDescriptor::getDoubleArray() {
    return dArray;
}

void TypeDescriptor::setStringArray(std::queue<std::string> a, std::string s) {
    a.push(s);
    sArray = a;
    _stringArray = true;
}

bool TypeDescriptor::isStringArray() {
    return _stringArray;
}

std::queue<std::string> TypeDescriptor::getStringArray() {
    return sArray;
}

void TypeDescriptor::setBooleanArray(std::queue<bool> a, bool b) {
    a.push(b);
    bArray = a;
    _boolArray = true;
}

bool TypeDescriptor::isBooleanArray() {
    return _boolArray;
}

std::queue<bool> TypeDescriptor::getBooleanArray() {
    return bArray;
}

void TypeDescriptor::setHeterogeneousArray() {
    _heteroArray = true;
    _intArray = false;
    _doubleArray = false;
    _stringArray = false;
    _boolArray = false;
}
bool TypeDescriptor::isHeterogeneousArray() {
    return _heteroArray;
}

int TypeDescriptor::ArrayType() {
    if (_heteroArray)
        return 4;
    else if (_intArray)
        return 0;
    else if (_doubleArray)
        return 1;
    else if (_stringArray)
        return 2;
    else if (_boolArray)
        return 3;
    return -1;
}

void TypeDescriptor::setArrayType(int t) {
    if (t == 0)
        _intArray = true;
    else if (t == 1)
        _doubleArray = true;
    else if (t == 2)
        _stringArray = true;
    else if (t == 3)
        _boolArray = true;
    else if (t == 4)
        _heteroArray = true;
}

TypeDescriptor TypeDescriptor::keepTogether(TypeDescriptor a, TypeDescriptor b) {
    TypeDescriptor result;

    if(a.getTypeValue() == INTEGER) {
        std::string s = std::to_string(a.getIntValue());
        s.append(" ");
        a._stringValue = s;
        a._type = STRING;
    }
    else if(a.getTypeValue() == DOUBLE) {
        std::string s = std::to_string(a.getDoubleValue());
        s.append(" ");
        a._stringValue = s;
        a._type = STRING;
    }
    else if(a.getTypeValue() == BOOL) {
        std::string s = std::to_string(a.getBoolValue());
        s.append(" ");
        a._stringValue = s;
        a._type = STRING;
    }
    else {
        std::string s = a.getStringValue();
        s.append(" ");
        a._stringValue = s;
        a._type = STRING;
    }
    if(b.getTypeValue() == INTEGER) {
        std::string s2 = std::to_string(b.getIntValue());
        b._stringValue = s2;
        b._type = STRING;
    }
    else if(b.getTypeValue() == DOUBLE) {
        std::string s2 = std::to_string(b.getDoubleValue());
        b._stringValue = s2;
        b._type = STRING;
    }
    else if(b.getTypeValue() == BOOL) {
        std::string s2 = std::to_string(b.getBoolValue());
        b._stringValue = s2;
        b._type = STRING;
    }
    else {
        std::string s2 = b.getStringValue();
        b._stringValue = s2;
        b._type = STRING;
    }

    result = a + b;
    return result;
}

TypeDescriptor TypeDescriptor::floorDivision(TypeDescriptor a, TypeDescriptor b) {
    TypeDescriptor result;
    if(a.getTypeValue() == TypeDescriptor::INTEGER &&
    b.getTypeValue() == TypeDescriptor::INTEGER) {
        int value = a.getIntValue() / b.getIntValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::DOUBLE &&
       b.getTypeValue() == TypeDescriptor::INTEGER) {
        double value = a.getDoubleValue() / b.getIntValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::INTEGER &&
            b.getTypeValue() == TypeDescriptor::DOUBLE) {
        double value = a.getIntValue() / b.getDoubleValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::DOUBLE &&
            b.getTypeValue() == TypeDescriptor::DOUBLE) {
        double value = a.getDoubleValue() / b.getDoubleValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::BOOL &&
            b.getTypeValue() == TypeDescriptor::BOOL) {
        int value = a.getBoolValue() / b.getBoolValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::BOOL &&
            b.getTypeValue() == TypeDescriptor::INTEGER) {
        int value = a.getBoolValue() / b.getIntValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::INTEGER &&
            b.getTypeValue() == TypeDescriptor::BOOL) {
        int value = a.getIntValue() / b.getBoolValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::DOUBLE &&
            b.getTypeValue() == TypeDescriptor::BOOL) {
        double value = a.getDoubleValue() / b.getBoolValue();
        result = floor(value);
    }
    else if(a.getTypeValue() == TypeDescriptor::BOOL &&
            b.getTypeValue() == TypeDescriptor::DOUBLE) {
        double value = a.getBoolValue() / b.getDoubleValue();
        result = floor(value);
    }

    else {
        std::cout << "ERROR, Invalid Division! Exiting..." << std::endl;
        exit(802);
    }
    return result;
}

TypeDescriptor::TypeDescriptor(void) {
    //std::cout << "Created" << std::endl;
}

TypeDescriptor::~TypeDescriptor(void) {
    //std::cout << "Destroyed" << std::endl;
}

TypeDescriptor & TypeDescriptor::operator = (const int &d) {
    _intValue = d;
    _doubleValue = d;
    _type = INTEGER;
    return *this;
}

TypeDescriptor & TypeDescriptor::operator = (const std::string &d) {
    _stringValue = d;
    _type = STRING;
    return *this;
}

TypeDescriptor & TypeDescriptor::operator = (const double &d) {
    _doubleValue = d;
    _type = DOUBLE;
    return *this;
}

TypeDescriptor & TypeDescriptor::operator = (const bool &d) {
    _boolValue = d;
    _type = BOOL;
    return *this;
}

std::ostream & operator << (std::ostream &out, const TypeDescriptor &c) {
    if(c._type == TypeDescriptor::INTEGER)
        out << c._intValue;
    else if(c._type == TypeDescriptor::STRING)
        out << c._stringValue;
    else if(c._type == TypeDescriptor::DOUBLE)
        out << c._doubleValue;
    else if(c._type == TypeDescriptor::BOOL)
        out << c._boolValue;
    else
        out << "Empty";
    return out;
}

TypeDescriptor TypeDescriptor::operator - () {
    TypeDescriptor result;
    if(_type == INTEGER) {
        result._intValue = _intValue * -1;
        result._type = _type;
    }
    else if(_type == DOUBLE) {
        result._doubleValue = _doubleValue * -1;
        result._type = _type;
    }
    else {
        std::cout << "ERROR, Invalid Negative! Exiting..." << std::endl;
        exit(799);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator + ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        result._intValue = _intValue + d._intValue;
        result._type = _type;
    }
    else if(_type == STRING && d._type == STRING) {
        result._stringValue = _stringValue + d._stringValue;
        result._type = _type;
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        result._doubleValue = _doubleValue + d._doubleValue;
        result._type = _type;
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        result._doubleValue = _intValue + d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        result._doubleValue = _doubleValue + d._intValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == BOOL) {
        result._intValue = _boolValue + d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == BOOL && d._type == INTEGER) {
        result._intValue = _boolValue + d._intValue;
        result._type = INTEGER;
    }
    else if(_type == INTEGER && d._type == BOOL) {
        result._intValue = _intValue + d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == DOUBLE && d._type == BOOL) {
        result._doubleValue = _doubleValue + d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == DOUBLE) {
        result._doubleValue = _boolValue + d._doubleValue;
        result._type = DOUBLE;
    }
    else {
        std::cout << "ERROR, Invalid Addition! Exiting..." << std::endl;
        exit(800);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator == ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue == d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue == d._stringValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue == d._doubleValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue == d._intValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue == d._doubleValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue == d._boolValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) {
        if(_boolValue == d._intValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) {
        if(_intValue == d._boolValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) {
        if(_boolValue == d._doubleValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) {
        if(_doubleValue == d._boolValue){
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator - ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        result._intValue = _intValue - d._intValue;
        result._type = INTEGER;
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        result._doubleValue = _doubleValue - d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        result._doubleValue = _intValue - d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        result._doubleValue = _doubleValue - d._intValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == BOOL) {
        result._intValue = _boolValue - d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == BOOL && d._type == INTEGER) {
        result._intValue = _boolValue - d._intValue;
        result._type = INTEGER;
    }
    else if(_type == INTEGER && d._type == BOOL) {
        result._intValue = _intValue - d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == DOUBLE && d._type == BOOL) {
        result._doubleValue = _doubleValue - d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == DOUBLE) {
        result._doubleValue = _boolValue - d._doubleValue;
        result._type = DOUBLE;
    }
    else {
        std::cout << "ERROR, Invalid Subtraction! Exiting..." << std::endl;
        exit(801);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator * ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        result._intValue = _intValue * d._intValue;
        result._type = _type;
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        result._doubleValue = _doubleValue * d._doubleValue;
        result._type = _type;
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        result._doubleValue = _intValue * d._doubleValue;
        result._type = d._type;
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        result._doubleValue = _doubleValue * d._intValue;
        result._type = _type;
    }
    else if(_type == BOOL && d._type == BOOL) {
        result._intValue = _boolValue * d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == BOOL && d._type == INTEGER) {
        result._intValue = _boolValue * d._intValue;
        result._type = INTEGER;
    }
    else if(_type == INTEGER && d._type == BOOL) {
        result._intValue = _intValue * d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == DOUBLE && d._type == BOOL) {
        result._doubleValue = _doubleValue * d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == DOUBLE) {
        result._doubleValue = _boolValue * d._doubleValue;
        result._type = DOUBLE;
    }
    else {
        std::cout << "ERROR, Invalid Multiplication! Exiting..." << std::endl;
        exit(802);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator / ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        result._doubleValue = _doubleValue / d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        result._doubleValue = _doubleValue / d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        result._doubleValue = _intValue / d._doubleValue;
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        result._doubleValue = _doubleValue / d._intValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == BOOL) {
        result._doubleValue = _boolValue / d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == INTEGER) {
        result._doubleValue = _boolValue / d._intValue;
        result._type = DOUBLE;
    }
    else if(_type == INTEGER && d._type == BOOL) {
        result._doubleValue = _intValue / d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == BOOL) {
        result._doubleValue = _doubleValue / d._boolValue;
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == DOUBLE) {
        result._doubleValue = _boolValue / d._doubleValue;
        result._type = DOUBLE;
    }
    else {
        std::cout << "ERROR, Invalid Division! Exiting..." << std::endl;
        exit(802);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator % ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        result._intValue = _intValue % d._intValue;
        result._type = INTEGER;
    }
    else if(_type == BOOL && d._type == INTEGER) {
        result._intValue = _boolValue % d._intValue;
        result._type = INTEGER;
    }
    else if(_type == INTEGER && d._type == BOOL) {
        result._intValue = _intValue % d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == BOOL && d._type == BOOL) {
        result._intValue = _boolValue % d._boolValue;
        result._type = INTEGER;
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {

        if(_doubleValue < 0)
            _doubleValue = -_doubleValue;
        if(d._doubleValue < 0)
            d._doubleValue = -d._doubleValue;

        double mod = _doubleValue;
        while (mod >= d._doubleValue)
            mod = mod - d._doubleValue;

        if(_doubleValue < 0) {
            result._doubleValue = -mod;
        }
        else {
            result._doubleValue = mod;
        }
        result._type = DOUBLE;
    }
    else if(_type == INTEGER && d._type == DOUBLE) {

        if(_doubleValue < 0)
            _doubleValue = -_doubleValue;
        if(d._doubleValue < 0)
            d._doubleValue = -d._doubleValue;

        double mod = _doubleValue;
        while (mod >= d._doubleValue)
            mod = mod - d._doubleValue;

        if(_doubleValue < 0) {
            result._doubleValue = -mod;
        }
        else {
            result._doubleValue = mod;
        }
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == INTEGER) {

        if(_doubleValue < 0)
            _doubleValue = -_doubleValue;
        if(d._doubleValue < 0)
            d._doubleValue = -d._doubleValue;

        double mod = _doubleValue;
        while (mod >= d._doubleValue)
            mod = mod - d._doubleValue;

        if(_doubleValue < 0) {
            result._doubleValue = -mod;
        }
        else {
            result._doubleValue = mod;
        }
        result._type = DOUBLE;
    }
    else if(_type == DOUBLE && d._type == BOOL) {

        d._doubleValue = d._boolValue;

        if(_doubleValue < 0)
            _doubleValue = -_doubleValue;
        if(d._doubleValue < 0)
            d._doubleValue = -d._doubleValue;

        double mod = _doubleValue;
        while (mod >= d._doubleValue)
            mod = mod - d._doubleValue;

        if(_doubleValue < 0) {
            result._doubleValue = -mod;
        }
        else {
            result._doubleValue = mod;
        }
        result._type = DOUBLE;
    }
    else if(_type == BOOL && d._type == DOUBLE) {

        _doubleValue = _boolValue;

        if(_doubleValue < 0)
            _doubleValue = -_doubleValue;
        if(d._doubleValue < 0)
            d._doubleValue = -d._doubleValue;

        double mod = _doubleValue;
        while (mod >= d._doubleValue)
            mod = mod - d._doubleValue;

        if(_doubleValue < 0) {
            result._doubleValue = -mod;
        }
        else {
            result._doubleValue = mod;
        }
        result._type = DOUBLE;
    }
    else {
        std::cout << "ERROR, Invalid Mod! Exiting..." << std::endl;
        exit(802);
    }
    return result;
}

TypeDescriptor TypeDescriptor::operator > ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue > d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue > d._stringValue) {
            std::cout << _stringValue << ">" << d._stringValue << std::endl;
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue > d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue > d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue > d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue > d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue > d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue > d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue > d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue > d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator >= ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue >= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue >= d._stringValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue >= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue >= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue >= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue >= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue >= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue >= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue >= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue >= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator < ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue < d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue < d._stringValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue < d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue < d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue < d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue < d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue < d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue < d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue < d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue < d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator <= ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue <= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue <= d._stringValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue <= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue <= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue <= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue <= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue <= d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue <= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue <= d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue <= d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator != ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue != d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        if(_stringValue != d._stringValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue != d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue != d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue != d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue != d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue != d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue != d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue != d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue != d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator || ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) {
        if(_intValue || d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) {
        std::cout << "Error!, cannot use 'or' on strings" << std::endl;
        exit(969);
    }
    else if(_type == DOUBLE && d._type == DOUBLE) {
        if(_doubleValue || d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue || d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue || d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) {
        if(_boolValue || d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue || d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue || d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue || d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue || d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator && ( TypeDescriptor &d) {
    TypeDescriptor result;
    if(_type == INTEGER && d._type == INTEGER) { // int && int
        if(_intValue && d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == STRING && d._type == STRING) { // string, string
        std::cout << "Error!, cannot use 'and' on strings" << std::endl;
        exit(970);
    }
    else if(_type == DOUBLE && d._type == DOUBLE) { // double && double
        if(_doubleValue && d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == INTEGER) {
        if(_doubleValue && d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == DOUBLE) {
        if(_intValue && d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == BOOL) { // bool && bool
        if(_boolValue && d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == INTEGER) { // bool, int
        if(_boolValue && d._intValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == INTEGER && d._type == BOOL) { // int, bool
        if(_intValue && d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == BOOL && d._type == DOUBLE) { // bool, double
        if(_boolValue && d._doubleValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    else if(_type == DOUBLE && d._type == BOOL) { // double, bool
        if(_doubleValue && d._boolValue) {
            result._boolValue = true;
            result._type = BOOL;
            return result;
        }
    }
    result._boolValue = false;
    result._type = BOOL;
    return result;
}

TypeDescriptor TypeDescriptor::operator ! ( void ) {

    TypeDescriptor result;
    if(_type == INTEGER) {
        if(_intValue == 0)
            result._boolValue = true;
        else
            result._boolValue = false;
    }
    else if(_type == STRING) {
        result._boolValue = false;
    }
    else if(_type == DOUBLE) {
        if(_doubleValue == 0)
            result._boolValue = true;
        else
            result._boolValue = false;
    }
    else if(_type == BOOL) {
        if(_boolValue == false)
            result._boolValue = true;
        else
            result._boolValue = false;
    }
    result._type = BOOL;
    return result;

}
