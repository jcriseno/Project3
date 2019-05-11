//
// Created by smith on 3/20/2019.
//

#ifndef EXPRINTER_SYMTAB_HPP
#define EXPRINTER_SYMTAB_HPP

#include <string>
#include <map>
#include <stack>
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

    // For forward declaration
    /* This is when i thought functionsList was a part of symTab
    Function_def *function_def;
    void addFunction(std::string fName, Function_def* function);
    */


    void openScope(SymTab);
    void storeReturnValue(TypeDescriptor* returnValue);
    TypeDescriptor getReturnValue();
    void closeScope();

    const std::stack<SymTab> &getSymTabStack() const;


private:
    std::map<std::string, TypeDescriptor> symTab;
    //std::map<std::string, Function_def*> functionsList;
    //std::stack <SymTab> symTabStack;
};

#endif //EXPRINTER_SYMTAB_HPP
