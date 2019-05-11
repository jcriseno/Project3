//
// Created by Ali A. Kooshesh on 2/5/19.
//

#ifndef EXPRINTER_ARITHEXPR_HPP
#define EXPRINTER_ARITHEXPR_HPP

#include "Token.hpp"
#include "SymTab.hpp"
#include "TypeDescriptor.hpp"
#include <queue>

// Classes in this file define the internal representation of arithmetic expressions.


// An ExprNode serves as the base class (super class) for arithmetic expression.
// It forces the derived classes (subclasses) to implement two functions, print and
// evaluate.
class ExprNode {
public:
    ExprNode(Token token);
    Token token();
    virtual void print() = 0;
    virtual TypeDescriptor evaluate(SymTab &symTab) = 0;

private:
    Token _token;
};


// An InfixExprNode is useful to represent binary arithmetic operators.
class InfixExprNode: public ExprNode {  // An expression tree node.

public:
    InfixExprNode(Token tk);

    ExprNode *&left();
    ExprNode *&right();
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);

    int arrayLength();

private:
    ExprNode *_left, *_right;
    int _arrLength;
};

// WholeNumber is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

class WholeNumber: public ExprNode {
public:
    WholeNumber(Token token);
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);
};

class DecimalNumber: public ExprNode {
public:
    DecimalNumber(Token token);
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);
};

// Variable is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

class Variable: public ExprNode {
public:
    Variable(Token token);
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);
};

class Keyword: public ExprNode {
public:
    Keyword(Token token);
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);
};

class String: public ExprNode {
public:
    String(Token token);
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);
};

//prefix
class PrefixExprNode: public ExprNode {  // An expression tree node.

public:
    PrefixExprNode(Token tk);

    ExprNode *&right();
    virtual void print();
    virtual TypeDescriptor evaluate(SymTab &symTab);

private:
    ExprNode *_right;
};

#endif //EXPRINTER_ARITHEXPR_HPP
