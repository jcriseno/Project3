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
InfixExprNode::InfixExprNode(Token tk) : ExprNode{tk}, _left(nullptr), _right(nullptr) {}

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
    else if ( token().isComma())
        return value1.keepTogether(value1, value2); // function inside TypeDescriptor class
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