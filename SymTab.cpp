//
// Created by smith on 3/20/2019.
//

#include <iostream>
#include <stack>
#include <map>
#include "SymTab.hpp"


void SymTab::setValueFor(std::string vName, TypeDescriptor value) {
    // Define a variable by setting its initial value.

    if(value.getTypeValue() == 0) { // Int
        //std::cout << "[DEBUG] "<< vName << " <- " << value.getIntValue() << std::endl;
        symTab.back()[vName] = value.getIntValue();
    }
    else if(value.getTypeValue() == 1) { // Double
        //std::cout << "[DEBUG] "<< vName << " <- " << value.getDoubleValue() << std::endl;
        symTab.back()[vName] = value.getDoubleValue();
    }
    else if(value.getTypeValue() == 2) { // String
        //std::cout << "[DEBUG] "<< vName << " <- " << value.getStringValue() << std::endl;
        symTab.back()[vName] = value.getStringValue();
    }
    else if(value.getTypeValue() == 3) { // Bool
        //std::cout << "[DEBUG] "<< vName << " <- " << value.getBoolValue() << std::endl;
        symTab.back()[vName] = value.getBoolValue();
    }

}

bool SymTab::isDefined(std::string vName) {
    if( symTab.back().find(vName) != symTab.back().end() )
        return symTab.back().find(vName) != symTab.back().end();
    else
        return symTab[0].find(vName) != symTab[0].end();

}

TypeDescriptor SymTab::getValueFor(std::string vName) {
    if( ! isDefined(vName)) {
        std::cout << "SymTab::getValueFor: " << vName << " has not been defined.\n";
        exit(1);
    }
    //std::cout << "SymTab::getValueFor: " << vName << " contains " << symTab.find(vName)->second << std::endl;
    return symTab.back().find(vName)->second;
}

void SymTab::openScope() {
    std::map<std::string, TypeDescriptor> _symTab;
    symTab.push_back(_symTab);
}

void SymTab::closeScope() {
    symTab.pop_back();
}


/*
void SymTab::addFunction(std::string fName, Function_def* function) {
    //functionsList[Function.fName()] = function;
    functionsList[fName] = function;
}
 */

