//
// Created by smith on 3/20/2019.
//

#ifndef EXPRINTER_SYMTAB_HPP
#define EXPRINTER_SYMTAB_HPP

#include <string>
#include <map>

#include <queue>

#include <stack>
#include <vector>

#include "TypeDescriptor.hpp"


// This is a flat and integer-based symbol table. It allows for variables to be
// initialized, determines if a give variable has been defined or not, and if
// a variable has been defined, it returns its value.

class Function_def;

class SymTab {
public:
    void setValueFor(std::string vName, TypeDescriptor value);
    bool isDefined(std::string vName);
    TypeDescriptor getValueFor(std::string vName);
    void setIntArray(std::string vName, std::queue<int> iArray);
    int getIntArrayIndex(std::string vName, int i);
    void setDoubleArray(std::string vName, std::queue<double> dArray);
    double getDoubleArrayIndex(std::string vName, int i);
    void setStringArray(std::string vName, std::queue<std::string> sArray);
    std::string getStringArrayIndex(std::string vName, int i);
    void setBooleanArray(std::string vName, std::queue<bool> bArray);
    bool getBooleanArrayIndex(std::string vName, int i);
    bool isArray(std::string vName);
    void setArraySize(std::string vName, int arrLen);
    int getArrayLength(std::string vName);
    void setArrayType(std::string vName, int type);
    int getArrayType(std::string vName);
    bool isSubscript(std::string vName);
    void setSubscript(std::string vName, int i);
    int getSubscript(std::string vName);
    void setIndex(std::string vName, int i, TypeDescriptor value);
    void arrayPush(std::string vName, int type, TypeDescriptor value);
    void arrayPop(std::string vName, int type);

    // For forward declaration
    /* This is when i thought functionsList was a part of symTab
    Function_def *function_def;
    void addFunction(std::string fName, Function_def* function);
    */


    void openScope();
    void storeReturnValue(TypeDescriptor* returnValue);
    TypeDescriptor getReturnValue();
    void closeScope();
    void passScope(std::map<std::string, TypeDescriptor> item);

    const std::vector<std::map<std::string, TypeDescriptor>> &getSymTab() const;


private:


    std::map<std::string, int> arraySize;
    std::map<std::string, int> arrayType;
    std::map<std::string, std::queue<int>> intArray;
    std::map<std::string, std::queue<double>> doubleArray;
    std::map<std::string, std::queue<std::string>> stringArray;
    std::map<std::string, std::queue<bool>> boolArray;
    std::map<std::string, int> Subscript;

    //std::map<std::string, TypeDescriptor> symTab;
    std::vector< std::map <std::string, TypeDescriptor> > symTab;
    //std::map<std::string, Function_def*> functionsList;
    //std::stack <SymTab> symTabStack;

};

#endif //EXPRINTER_SYMTAB_HPP
