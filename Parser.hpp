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

#include<vector>
#include<iostream>
#include<map>


class Parser {
public:
    Parser(Tokenizer &tokenizer) : tokenizer{tokenizer} {}

    Statements *statements();
    Statement *statement();
    ForStatement *forStatement();
    AssignmentStatement *assignStatement();
    PrintStatement *printStatement();
    IfStatement *ifStatement();

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

    void die(std::string where, std::string message, Token &token);

};

#endif

