//
// Created by smith on 3/20/2019.
//

#ifndef __PARSER_HPP
#define __PARSER_HPP

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "SymTab.hpp"
#include "ArithExpr.hpp"
#include "Statements.hpp"
#include "Functions.hpp"

#include<vector>
#include<iostream>
#include<map>

class FunctionList{
public:
    const std::map<std::string, Function_def *> &getFunctionsList() const;
    void addFunction(std::string fName, Function_def* function);
    bool isDefined(std::string fName);
    Function_def* findFunction(std::string fName);

private:
    std::map<std::string, Function_def*> functionsList;
};


class Parser {
public:
    Parser(Tokenizer &tokenizer) : tokenizer{tokenizer} {}

    Statements *statements();
    Statement *statement();
    ForStatement *forStatement();
    AssignmentStatement *assignStatement();
    PrintStatement *printStatement();
    IfStatement *ifStatement();
    Function_def *func_def();

    ExprNode *test();
    ExprNode *or_test();
    ExprNode *and_test();
    ExprNode *not_test();
    ExprNode *rel_expr();
    ExprNode *expr();
    ExprNode *term();
    ExprNode *factor();
    ExprNode *primary();
    ExprNode *id();


private:
    Tokenizer &tokenizer;
    FunctionList functionList;


    void die(std::string where, std::string message, Token &token);

};

#endif

