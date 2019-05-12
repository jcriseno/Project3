//
// Created by Ali A. Kooshesh on 2/5/19.
//

#include<iostream>
#include "ArithExpr.hpp"
#include "TypeDescriptor.hpp"

// ExprNode
ExprNode::ExprNode(Token token): _token{token} {}

Token ExprNode::token() { return _token; }

// InfixExprNode functions
InfixExprNode::InfixExprNode(Token tk) : ExprNode{tk}, _left(nullptr), _right(nullptr), _arrLength{0} {}

ExprNode *&InfixExprNode::left() { return _left; }

ExprNode *&InfixExprNode::right() { return _right; }

TypeDescriptor InfixExprNode::evaluate(SymTab &symTab) {
    TypeDescriptor value1;
    TypeDescriptor value2;
    // Evaluates an infix expression using a post-order traversal of the expression tree.
    auto lValue = left()->evaluate(symTab);
    auto rValue = right()->evaluate(symTab);
    value1 = lValue;
    value2 = rValue;
    //if (token().symbol())
        //std::cout << "[DEBUG] Evaluating: " << lValue << " " << token().symbol() << " " << rValue << std::endl;
    //else
        //std::cout << "[DEBUG] Evaluating: " << lValue << " " << token().symbolString() << " " << rValue << std::endl;
    if( token().isAdditionOperator() )
        return value1 + value2;
    else if(token().isSubtractionOperator())
        return value1 - value2;
    else if(token().isMultiplicationOperator())
        return value1 * value2;
    else if(token().isDivisionOperator())
        return value1 / value2; // division by zero?
    else if( token().isModuloOperator() )
        return value1 % value2;
    else if ( token().isGreaterThan() )
        return value1 > value2;
    else if ( token().isGreaterThanOrEqual() )
        return value1 >= value2;
    else if ( token().isLessThan() )
        return value1 < value2;
    else if ( token().isLessThanOrEqual() )
        return value1 <= value2;
    else if ( token().isEqualTo() )
        return value1 == value2;
    else if ( token().isNotEqualTo() )
        return value1 != value2;
    else if ( token().isNotEqualTo2() )
        return value1 != value2;
    else if ( token().isName())
        return value1 == value2;
    else if ( token().isOr() )
        return value1 || value2;
    else if ( token().isAnd() )
        return value1 && value2;
    else if ( token().isComma()) {


        // This is where I'm getting a bug


        _arrLength++;
        TypeDescriptor value = value1.keepTogether(value1, value2);
        if (value2.getTypeValue() == 0) { // Integer Array
            if (value1.getTypeValue() == 0) {
                std::queue<int> a;
                value1.setIntArray(a, value1.getIntValue());
                a = value1.getIntArray();
                value.setIntArray(a, value2.getIntValue());
            } else {
                if (!value1.isIntArray()) {
                    value.setHeterogeneousArray();
                } else {
                    std::queue<int> a = value1.getIntArray();
                    value.setIntArray(a,value2.getIntValue());
                }
            }
        } else if (value2.getTypeValue() == 1) { // Double Array
            if (value1.getTypeValue() == 1) {
                std::queue<double> a;
                value1.setDoubleArray(a, value1.getDoubleValue());
                a = value1.getDoubleArray();
                value.setDoubleArray(a, value2.getDoubleValue());
            } else {
                if (!value1.isDoubleArray()) {
                    value.setHeterogeneousArray();
                } else {
                    std::queue<double> a = value1.getDoubleArray();
                    value.setDoubleArray(a, value2.getDoubleValue());
                }
            }
        } else if (value2.getTypeValue() == 2) { // String Array
            if (value1.getTypeValue() == 2) {
                std::queue<std::string> a;
                value.setStringArray(a, value1.getStringValue());
                a = value1.getStringArray();
                value.setStringArray(a, value2.getStringValue());
            } else {
                if (!value1.isStringArray()) {
                    value.setHeterogeneousArray();
                } else {
                    std::queue<std::string> a = value1.getStringArray();
                    value.setStringArray(a, value2.getStringValue());
                }
            }
        } else if (value2.getTypeValue() == 3) { // Boolean Array
            if (value1.getTypeValue() == 3) {
                std::queue<bool> a;
                value.setBooleanArray(a, value1.getBoolValue());
                a = value1.getBooleanArray();
                value.setBooleanArray(a, value2.getBoolValue());
            } else {
                if (!value1.isBooleanArray()) {
                    value.setHeterogeneousArray();
                } else {
                    std::queue<bool> a = value1.getBooleanArray();
                    value.setBooleanArray(a, value2.getBoolValue());
                } 
            }
        }
        return value; // function inside TypeDescriptor class
    }
    else if ( token().isFloorDivision() )
        return value1.floorDivision(value1, value2);
    else {
        std::cout << "InfixExprNode::evaluate: don't know how to evaluate this operator\n";
        token().print();
        std::cout << std::endl;
        exit(2);
    }
}

void InfixExprNode::print() {
    _left->print();
    token().print();
    _right->print();
}

int InfixExprNode::arrayLength() {
    return _arrLength;
}

// WholeNumber
DecimalNumber::DecimalNumber(Token token): ExprNode{token} {}

void DecimalNumber::print() {
    token().print();
}

TypeDescriptor DecimalNumber::evaluate(SymTab &symTab) {
    //std::cout << "DecimalNumber::evaluate: returning " << token().getWholeNumber() << std::endl;
    TypeDescriptor value;
    value = token().getDecimalNumber();
    return value;
}

// DecimalNumber
WholeNumber::WholeNumber(Token token): ExprNode{token} {}

void WholeNumber::print() {
    token().print();
}

TypeDescriptor WholeNumber::evaluate(SymTab &symTab) {
    //std::cout << "WholeNumber::evaluate: returning " << token().getWholeNumber() << std::endl;
    TypeDescriptor value;
    value = token().getWholeNumber();
    return value;
}

// Variable
Variable::Variable(Token token): ExprNode{token} {}

void Variable::print() {
    token().print();
}

TypeDescriptor Variable::evaluate(SymTab &symTab) {
    if( ! symTab.isDefined(token().getName())) {
        std::cout << "Use of undefined variable, " << token().getName() << std::endl;
        exit(1);
    }
    TypeDescriptor value;
    if (token().isSubscript()) {
        if (symTab.getArrayType(token().getName()) == 0)
            value = symTab.getIntArrayIndex(token().getName(), token().getSubscript());
        else if (symTab.getArrayType(token().getName()) == 1)
            value = symTab.getDoubleArrayIndex(token().getName(), token().getSubscript());
        else if (symTab.getArrayType(token().getName()) == 2)
            value = symTab.getStringArrayIndex(token().getName(), token().getSubscript());
        else if (symTab.getArrayType(token().getName()) == 3)
            value = symTab.getBooleanArrayIndex(token().getName(), token().getSubscript());
    }
    else if( token().isArrayLength()) {
        value = symTab.getArrayLength(token().getName());
    }
    else
        value = symTab.getValueFor(token().getName());
    //std::cout << "Variable::evaluate: returning " << symTab.getValueFor(token().getName()) << std::endl;
    return value;
}

// Keyword
Keyword::Keyword(Token token): ExprNode{token} {}

void Keyword::print() {
    token().print();
}

TypeDescriptor Keyword::evaluate(SymTab &symTab) {
    if( ! symTab.isDefined(token().getKeyword())) {
        std::cout << "Use of keyword, '" << token().getKeyword() << "' not allowed!" << std::endl;
        exit(1);
    }

    TypeDescriptor value;
    value = 1;
    //std::cout << "Keyword::evaluate: returning " << symTab.getValueFor(token().getKeyword()) << std::endl;
    return value;
}

// String
String::String(Token token): ExprNode{token} {}

void String::print() {
    token().print();
}

TypeDescriptor String::evaluate(SymTab &symTab) {
    TypeDescriptor value;
    value = token().getString();
    //std::cout << "Keyword::evaluate: returning " << symTab.getValueFor(token().getKeyword()) << std::endl;
    return value;
}

// prefixExprNode functions
PrefixExprNode::PrefixExprNode(Token tk) : ExprNode{tk}, _right(nullptr) {}

ExprNode *&PrefixExprNode::right() { return _right; }

TypeDescriptor PrefixExprNode::evaluate(SymTab &symTab) {
    TypeDescriptor value;
    auto rValue = right()->evaluate(symTab);
    value = rValue;

    if ( token().isNot() )
        return !value;
    else if ( token().isSubtractionOperator() )
        return -value;
    else {
        std::cout << "PrefixExprNode::evaluate: don't know how to evaluate this operator\n";
        token().print();
        std::cout << std::endl;
        exit(2);
    }
}

void PrefixExprNode::print() {
    token().print();
    _right->print();
}
