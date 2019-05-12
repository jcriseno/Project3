//
// Created by smith on 3/20/2019.
//

#include <iostream>
#include <stack>
#include <map>
#include "SymTab.hpp"


void SymTab::setValueFor(std::string vName, TypeDescriptor value) {
    if (isSubscript(vName)) {
        setIndex(vName, getSubscript(vName), value);
    } else {
    if (isArray(vName)) {
        if (getArrayType(vName) == 4) { // Is it Homogeneous?
            std::cout << "SymTab::setValueFor: " << vName << " is a heterogeneous array.\n";
            exit(1);
        }
        if (value.isIntArray()) {
            setIntArray(vName,value.getIntArray());
        } else if (value.isDoubleArray()) {
            setDoubleArray(vName,value.getDoubleArray());
        } else if (value.isStringArray()) {
            setStringArray(vName,value.getStringArray());
        } else if (value.isBooleanArray()) {
            setBooleanArray(vName,value.getBooleanArray());
        }
    }
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

    TypeDescriptor value = symTab.find(vName)->second;
    if (isArray(vName)) { // Is it an array?
        if (getArrayType(vName) == 4) { // Is it Homogeneous?
            std::cout << "SymTab::getValueFor: " << vName << " is a heterogeneous array.\n";
            exit(1);
        }
        if (getArrayType(vName) == 0) {
            std::queue<int> a = intArray[vName];
            std::string valueArray = "[";
            for (int k = 0; k < intArray[vName].size()-1; k++) {
                valueArray += std::to_string(a.front());
                valueArray += ", ";
                a.pop();
            }
            valueArray += std::to_string(a.front());
            valueArray += "]";
            value = valueArray;
        }
        else if (getArrayType(vName) == 1) {
            std::queue<double> a = doubleArray[vName];
            std::string valueArray = "[";
            for (int k = 0; k < doubleArray[vName].size()-1; k++) {
                valueArray += std::to_string(a.front());
                valueArray += ", ";
                a.pop();
            }
            valueArray += std::to_string(a.front());
            valueArray += "]";
            value = valueArray;
        }
        else if (getArrayType(vName) == 2) {
            std::queue<std::string> a = stringArray[vName];
            std::string valueArray = "[";
            for (int k = 0; k < stringArray[vName].size()-1; k++) {
                valueArray += a.front();
                valueArray += ", ";
                a.pop();
            }
            valueArray += a.front();
            valueArray += "]";
            value = valueArray;
        }
        else if (getArrayType(vName) == 3) {
            std::queue<bool> a = boolArray[vName];
            std::string valueArray = "[";
            for (int k = 0; k < boolArray[vName].size()-1; k++) {
                valueArray += std::to_string(a.front());
                valueArray += ", ";
                a.pop();
            }
            valueArray += std::to_string(a.front());
            valueArray += "]";
            value = valueArray;
        }
        else if (value.getTypeValue() == 2)
            value = "[" + value.getStringValue() + "]";
    }

    //std::cout << "SymTab::getValueFor: " << vName << " contains " << symTab.find(vName)->second << std::endl;

    return value;
}

void SymTab::setArraySize(std::string vName, int arrLen) {
    arraySize[vName] = arrLen;
}

bool SymTab::isArray(std::string vName) {
    return arraySize.find(vName) != arraySize.end();
}

void SymTab::setArrayType(std::string vName, int type) {
    arrayType[vName] = type;
}
int SymTab::getArrayType(std::string vName) {
    return arrayType[vName];
}

void SymTab::setIntArray(std::string vName, std::queue<int> iArray) {
    intArray[vName] = iArray;
}

void SymTab::setDoubleArray(std::string vName, std::queue<double> dArray) {
    doubleArray[vName] = dArray;
}

void SymTab::setStringArray(std::string vName, std::queue<std::string> sArray) {
    stringArray[vName] = sArray;
}

void SymTab::setBooleanArray(std::string vName, std::queue<bool> bArray) {
    boolArray[vName] = bArray;
}

int SymTab::getIntArrayIndex(std::string vName, int i) {
    if (i > intArray[vName].size()-1) {
        std::cout << "SymTab::getIntArrayIndex: index " << i << " is out bounds for " << vName << std::endl;
        exit(1);
    }
    std::queue<int> a = intArray[vName];
    while (i > 0) {
        a.pop();
        i--;
    }
    return a.front();
}

double SymTab::getDoubleArrayIndex(std::string vName, int i) {
    if (i > doubleArray[vName].size()-1) {
        std::cout << "SymTab::getDoubleArrayIndex: index " << i << " is out bounds for " << vName << std::endl;
        exit(1);
    }
    std::queue<double> a = doubleArray[vName];
    while (i > 0) {
        a.pop();
        i--;
    }
    return a.front();
}

std::string SymTab::getStringArrayIndex(std::string vName, int i) {
    if (i > stringArray[vName].size()-1) {
        std::cout << "SymTab::getStringArrayIndex: index " << i << " is out bounds for " << vName << std::endl;
        exit(1);
    }
    std::queue<std::string> a = stringArray[vName];
    while (i > 0) {
        a.pop();
        i--;    
    }
    return a.front();
}

bool SymTab::getBooleanArrayIndex(std::string vName, int i) {
    if (i > boolArray[vName].size()-1) {
        std::cout << "SymTab::getBooleanArrayIndex: index " << i << " is out bounds for " << vName << std::endl;
        exit(1);
    }
    std::queue<bool> a = boolArray[vName];
    while (i > 0) {
        a.pop();
        i--;
    }
    return a.front();
}

bool SymTab::isSubscript(std::string vName) {
    return Subscript[vName];
}

void SymTab::setSubscript(std::string vName, int i) {
    if (!isArray(vName)) {
        std::cout << "SymTab::setSubscript(std::string vName): " << vName << " is not an array!" << std::endl;
        exit(1);
    }
    Subscript[vName] = i;
}

int SymTab::getSubscript(std::string vName) {
    return Subscript[vName];
}

void SymTab::setIndex(std::string vName, int i, TypeDescriptor value) {
    if (value.getTypeValue() == 0) {
        std::queue<int> a = intArray[vName];
        if (i > a.size()-1) {
            std::cout << "SymTab::setIndex: index " << i << " is out bounds for " << vName << std::endl;
            exit(1);
        }
        std::queue<int> b;
        int size = a.size();
        while(size > 0) {
            if (i == 0) {
                b.push(value.getIntValue());
            } else
                b.push(a.front());
            a.pop();
            i--;
            size--;
        }
        intArray[vName] = b;
    } else if (value.getTypeValue() == 1) {
        std::queue<double> a = doubleArray[vName];
        if (i > a.size()-1) {
            std::cout << "SymTab::setIndex: index " << i << " is out bounds for " << vName << std::endl;
            exit(1);
        }
        std::queue<double> b;
        int size = a.size();
        while(size > 0) {
            if (i == 0)
                b.push(value.getDoubleValue());
            else
                b.push(a.front());
            a.pop();
            i--;
            size--;
        }
        doubleArray[vName] = b;
    } else if (value.getTypeValue() == 2) {
        std::queue<std::string> a = stringArray[vName];
        if (i > a.size()-1) {
            std::cout << "SymTab::setIndex: index " << i << " is out bounds for " << vName << std::endl;
            exit(1);
        }
        std::queue<std::string> b;
        int size = a.size();
        while(size > 0) {
            if (i == 0)
                b.push(value.getStringValue());
            else
                b.push(a.front());
            a.pop();
            i--;
            size--;
        }
        stringArray[vName] = b;
    } else if (value.getTypeValue() == 3) {
        std::queue<bool> a = boolArray[vName];
        if (i > a.size()-1) {
            std::cout << "SymTab::setIndex: index " << i << " is out bounds for " << vName << std::endl;
            exit(1);
        }
        std::queue<bool> b;
        int size = a.size();
        while(size > 0) {
            if (i == 0)
                b.push(value.getBoolValue());
            else
                b.push(a.front());
            a.pop();
            i--;
            size--;
        }
        boolArray[vName] = b;
    }
}

int SymTab::getArrayLength(std::string vName) {
    if (!isArray(vName)) {
        std::cout << "SymTab::getArraySize: " << vName << " is not defined! " << std::endl;
        exit(1);
    }
    return arraySize[vName];
}

void SymTab::arrayPush(std::string vName, int type, TypeDescriptor value) {
    if (!isArray(vName)) {
        std::cout << "SymTab::arrayPush: " << vName << " is not defined! " << std::endl;
        exit(1);
    }
    if (type == 0) {
        std::queue<int> a = intArray[vName];
        a.push(value.getIntValue());
        intArray[vName] = a;
    } else if (type == 1) {
        std::queue<double> a = doubleArray[vName];
        a.push(value.getDoubleValue());
        doubleArray[vName] = a;
    } else if (type == 2) {
        std::queue<std::string> a = stringArray[vName];
        a.push(value.getStringValue());
        stringArray[vName] = a;
    } else if (type == 3) {
        std::queue<bool> a = boolArray[vName];
        a.push(value.getBoolValue());
        boolArray[vName] = a;
    }
}

void SymTab::arrayPop(std::string vName, int type) {
    if (!isArray(vName)) {
        std::cout << "SymTab::arrayPop: " << vName << " is not defined! " << std::endl;
        exit(1);
    }
    if (type == 0) {
        std::queue<int> a = intArray[vName];
        a.pop();
        intArray[vName] = a;
    } else if (type == 1) {
        std::queue<double> a = doubleArray[vName];
        a.pop();
        doubleArray[vName] = a;
    } else if (type == 2) {
        std::queue<std::string> a = stringArray[vName];
        a.pop();
        stringArray[vName] = a;
    } else if (type == 3) {
        std::queue<bool> a = boolArray[vName];
        a.pop();
        boolArray[vName] = a;
    }
}

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


