//
// Created by smith on 3/20/2019.
//

#include<vector>
#include<iostream>

#include "Token.hpp"
#include "Parser.hpp"
#include "Statements.hpp"
#include "SymTab.hpp"

static bool firstRun = true; // Are we on the firstLine of the program? (true = yes, false = no)

// Parser functions

void FunctionList::addFunction(std::string fName, Function_def* function) {
    //functionsList[Function.fName()] = function;
    functionsList[fName] = function;
}

bool FunctionList::isDefined(std::string fName) {
    return functionsList.find(fName) != functionsList.end();
}

Function_def* FunctionList::findFunction(std::string fName) {
    if( ! isDefined(fName)) {
        std::cout << "FunctionList::getValueFor: " << fName << " has not been defined.\n";
        exit(1);
    }
    //std::cout << "SymTab::getValueFor: " << vName << " contains " << symTab.find(vName)->second << std::endl;
    return functionsList.find(fName)->second;
}

const std::map<std::string, Function_def *> &FunctionList::getFunctionsList() const {
    return functionsList;
}

void Parser::die(std::string where, std::string message, Token &token) {
    std::cout << where << " " << message << std::endl;
    token.print();
    std::cout << std::endl;
    std::cout << "\nThe following is a list of tokens that have been identified up to this point.\n";
    tokenizer.printProcessedTokens();
    exit(1);
}

Statements *Parser::statements() {

    // This function parses the grammar rules:
    // <statements> -> {NEWLINE | stmt}* ENDMARKER

    Statements *value = new Statements();
    Token tok = tokenizer.getToken();

    if(firstRun && tok.isIndent()) {
        std::cout << "Cannot indent first line, exiting program!" << std::endl;
        exit(1000);
    }

    while(tok.eol() || tok.isKeyword() || tok.isName() || tok.isIf() ||
    tok.isElse() || tok.isElseIf() || tok.isName() || tok.isDef()) { // {NEWLINE | stmt}*
        if(tok.eol() ) { // NEWLINE
            //DO NOTHING
        }
        else if (tok.isKeyword() || tok.isName() || tok.isIf() ||
        tok.isElse() || tok.isElseIf() || tok.isDef())  { // stmt
            tokenizer.ungetToken();
            Statement *state = statement();
            value->addStatement(state);
        }
        tok = tokenizer.getToken();
    }

    firstRun = false;

    tokenizer.ungetToken();
    return value;
}

Statement *Parser::statement() {

    // This function parses the grammar rules:
    // <statement> -> <if_stmt> | <for_stmt> | <print_stmt> | <assign_stmt>

    Token tok = tokenizer.getToken();
    if(tok.isIf()) {
        tokenizer.ungetToken();
        return ifStatement();
    }
    else if(tok.isDef()){
        tokenizer.ungetToken();
        // only call func def, dont return it
        return func_def();
        //func_def();
    }
    else if (tok.isKeyword()) {
        if (tok.getKeyword() == "print") {
            tokenizer.ungetToken();
            return printStatement();
        }
        else if (tok.getKeyword() == "for") {
            tokenizer.ungetToken();
            return forStatement();
        }
        else if(tok.getKeyword() == "def") {
            tokenizer.ungetToken();
            // only call func def, dont return it
            func_def();
            //func_def();
        }
    }
    else if(tok.isName()) {
        tokenizer.ungetToken();
        return assignStatement();
    }
    else {
        die("Parser::statement:", "Unexpected token, got", tok);
    }

    //Should never be reached
    return nullptr;
}

Function_def *Parser::func_def() {
    // func_def: ’def’ ID ’(’ [parameter_list] ’)’ ’:’ func_suite

    // def
    Token defToken = tokenizer.getToken();
    if (!defToken.isDef()){
        die("Parser::Function_def:"," Expected def token, instead got ", defToken);
    }

    // ID
    //ExprNode *Expr1 = id();
    Token funcNameToken = tokenizer.getToken();
    if(!funcNameToken.isName()){
        die("Parser::Function_def:"," Expected keyword, instead got ", funcNameToken);
    }

    // (
    Token openParenToken = tokenizer.getToken();
    if(!openParenToken.isOpenParen()){
        die("Parser::Function_def:", " Expected OpenParenToken, instead got ", openParenToken);
    }

    // [parameter list]
    //ExprNode *Expr2 = test();
    std::vector<ExprNode*> *paramemter_list;

    Token emptyParamTest = tokenizer.getToken();
    if(emptyParamTest.isCloseParen()){
        tokenizer.ungetToken();
    }
    else {
        tokenizer.ungetToken();
        ExprNode *paramID = id();
        paramemter_list->push_back(paramID);
        Token paramTok = tokenizer.getToken();
        while (paramTok.isComma()) {
            ExprNode *paramID = id();
            paramemter_list->push_back(paramID);
            Token paramTok = tokenizer.getToken();
        }
        tokenizer.ungetToken();
    }
    // )
    Token closedParenToken = tokenizer.getToken();
    if(!closedParenToken.isCloseParen()){
        die("Parser::Function_def: ", "Expected ClosedParenToken, instead got ", closedParenToken);
    }

    // :
    Token colonToken = tokenizer.getToken();
    if(!colonToken.isColon()){
        die("Parser::Function_def: ", "Expected colonToken, instead got ", colonToken);
    }

    // [NEWLINE]
    Token newLineToken = tokenizer.getToken();
    if(!newLineToken.eol()){
        die("Parser::Function_def: ", "Expected newLineToken, instead got ", newLineToken);
    }

    // [INDENT]
    Token indentToken = tokenizer.getToken();
    if(!indentToken.isIndent()){
        die("Parser::Function_def: ", "Expected indentToken, instead got ", indentToken);
    }

    // --code--
    Statements *State = statements();

    // [DEDENT]
    Token dedentToken = tokenizer.getToken();
    if(!dedentToken.isDedent()){
        die("Parser::Function_def: ", "Expected dedentToken, instead got ", dedentToken);
    }

    //return new Function_def(Expr1, Expr2, State);
    //return new Function_def(Expr1, paramemter_list, State);

    // dont return it but just call add it to the functionList

    Function_def *function =  new Function_def(funcNameToken.getName(), paramemter_list, State);
    functionList.addFunction(funcNameToken.getName(), function);

    return function;


}


IfStatement *Parser::ifStatement() {

    // This function parses the grammar rules:
    // <if_stmt> -> ’if’ <or_test> ’:’ <suite> {’elif’ <or_test> ’:’ <suite>}* [’else’ ’:’ <suite>]
    // <suit> -> NEWLINE INDENT <stmt> DEDENT

    std::vector<ExprNode *> elifExprVector;
    std::vector<Statements *> elifAssignVector;
    bool isElseTrue = false;

    Token varIf = tokenizer.getToken();
    if (!varIf.isIf())
        die("Parser::ifStatement", "Expected a Keyword 'if' token, instead got", varIf);

    ExprNode *ifExpr = or_test();

    Token varColon = tokenizer.getToken();
    if (!varColon.isColon())
        die("Parser::ifStatement", "Expected a ':' token, instead got", varColon);

    Token varNewline = tokenizer.getToken();
    if (!varNewline.eol())
        die("Parser::ifStatement", "Expected a 'NEWLINE' token, instead got", varNewline);

    Token varIndent = tokenizer.getToken();
    if (!varIndent.isIndent())
        die("Parser::ifStatement", "Expected a 'INDENT' token, instead got", varIndent);

    Statements *ifStatements = statements();

    Token varDedent = tokenizer.getToken();
    if (!varDedent.isDedent())
        die("Parser::ifStatement", "Expected a 'DEDENT' token, instead got", varDedent);

    Token varElseIf = tokenizer.getToken();
    while (varElseIf.isElseIf()) {
        bool isElseTrue = true;
        ExprNode *elifExpr = or_test();
        elifExprVector.push_back(elifExpr);

        Token varColonTwo = tokenizer.getToken();
        if (!varColonTwo.isColon())
            die("Parser::ifStatement", "Expected a ':' token, instead got", varColonTwo);

        Token varNewlineTwo = tokenizer.getToken();
        if (!varNewlineTwo.eol())
            die("Parser::ifStatement", "Expected a 'NEWLINE' token, instead got", varNewlineTwo);

        Token varIndentTwo = tokenizer.getToken();
        if (!varIndentTwo.isIndent())
            die("Parser::ifStatement", "Expected a 'INDENT' token, instead got", varIndentTwo);

        Statements *elifStatements = statements();
        elifAssignVector.push_back(elifStatements);

        Token varDedentTwo = tokenizer.getToken();
        if (!varDedentTwo.isDedent())
            die("Parser::ifStatement", "Expected a 'DEDENT' token, instead got", varDedentTwo);

        varElseIf = tokenizer.getToken();
    }

    if(varElseIf.isElse()) {
        bool isElseTrue = true;
        Token varColonThree = tokenizer.getToken();
        if (!varColonThree.isColon())
            die("Parser::ifStatement", "Expected a ':' token, instead got", varColonThree);

        Token varNewlineThree = tokenizer.getToken();
        if (!varNewlineThree.eol())
            die("Parser::ifStatement", "Expected a 'NEWLINE' token, instead got", varNewlineThree);

        Token varIndentThree = tokenizer.getToken();
        if (!varIndentThree.isIndent())
            die("Parser::ifStatement", "Expected a 'INDENT' token, instead got", varIndentThree);

        Statements *elseStatements = statements();

        Token varDedentThree = tokenizer.getToken();
        if (!varDedentThree.isDedent())
            die("Parser::ifStatement", "Expected a 'DEDENT' token, instead got", varDedentThree);

        return new IfStatement(ifExpr, ifStatements, elifExprVector,
                               elifAssignVector, elseStatements, isElseTrue);
    }
    else {
        tokenizer.ungetToken();
        Statements *elseStatements = nullptr;
        return new IfStatement(ifExpr, ifStatements, elifExprVector,
                               elifAssignVector, elseStatements, isElseTrue);
    }

}

ForStatement *Parser::forStatement() {

    // This function parses the grammar rules:
    // <for_stmt> ’for’ <id> ’in’ ’range’ ’(’ <test> ’)’ ’:’ <suite>
    // <suit> -> NEWLINE INDENT <stmt> DEDENT

    Token varKeyword = tokenizer.getToken();
    if (!varKeyword.isKeyword())
        die("Parser::forStatement", "Expected a Keyword token, instead got", varKeyword);

    ExprNode *Expr1 = id();

    Token varIsInKeyword = tokenizer.getToken();
    if (varIsInKeyword.getKeyword() != "in")
        die("Parser::forStatement", "Expected a Keyword 'in' token, instead got", varIsInKeyword);

    Token varIsRangeKeyword = tokenizer.getToken();
    if (varIsRangeKeyword.getKeyword() != "range")
        die("Parser::forStatement", "Expected a Keyword 'range' token, instead got", varIsRangeKeyword);

    Token varIsOpenParen = tokenizer.getToken();
    if (!varIsOpenParen.isOpenParen())
        die("Parser::forStatement", "Expected a '(' token, instead got", varIsOpenParen);

    ExprNode *Expr2 = test();

    Token varIsClosedParen = tokenizer.getToken();
    if (!varIsClosedParen.isCloseParen())
        die("Parser::forStatement", "Expected a ')' token, instead got", varIsClosedParen);

    Token varColon = tokenizer.getToken();
    if (!varColon.isColon())
        die("Parser::forStatement", "Expected a Colon ':' token, instead got", varColon);

    Token varNewline = tokenizer.getToken();
    if (!varNewline.eol())
        die("Parser::forStatement", "Expected a 'NEWLINE' token, instead got", varNewline);

    Token varIndent = tokenizer.getToken();
    if (!varIndent.isIndent())
        die("Parser::forStatement", "Expected a 'INDENT' token, instead got", varIndent);

    Statements *State = statements();

    Token varDedent = tokenizer.getToken();
    if (!varDedent.isDedent())
        die("Parser::forStatement", "Expected a 'DEDENT' token, instead got", varDedent);

    return new ForStatement(Expr1, Expr2, State);
}

AssignmentStatement *Parser::assignStatement() {

    // This function parses the grammar rules:
    // <assign_stmt> -> 'id' ’=’ <or_test>

    Token varName = tokenizer.getToken();
    if (!varName.isName())
        die("Parser::assignStatement", "Expected a name token, instead got", varName);

    Token assignOp = tokenizer.getToken();
    if (!assignOp.isAssignmentOperator())
        die("Parser::assignStatement", "Expected an '=', instead got", assignOp);

    ExprNode *rightHandSideExpr = or_test();

    return new AssignmentStatement(varName.getName(), rightHandSideExpr);
}

PrintStatement *Parser::printStatement() {

    // This function parses the grammar rules:
    // <print_stmt> -> 'print' [ <test> ]

    Token varKeyword = tokenizer.getToken();
    if (!varKeyword.isKeyword())
        die("Parser::printStatement", "Expected a Keyword token, instead got", varKeyword);

    ExprNode *rightHandSideExpr = test();

    return new PrintStatement(varKeyword.getKeyword(), rightHandSideExpr);
}

ExprNode *Parser::test() {

    // This function parses the grammar rules:
    // <test> -> <or_test> { ',' <or_test> }

    ExprNode *left = or_test();
    Token tok = tokenizer.getToken();
    while ( tok.isComma() ) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = or_test();
        left = p;
        tok = tokenizer.getToken();
    }

    tokenizer.ungetToken();
    return left;

}

ExprNode *Parser::or_test() {
    // This function parses the grammar rules:
    // <or_test> -> <and_test> { 'or' <and_test> }

    ExprNode *left = and_test();
    Token tok = tokenizer.getToken();
    while ( tok.isOr() ) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = and_test();
        left = p;
        tok = tokenizer.getToken();
    }

    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::and_test() {

    // This function parses the grammar rules:
    // <and_test> -> <not_test> { 'and' <not_test> }

    ExprNode *left = not_test();
    Token tok = tokenizer.getToken();
    while ( tok.isAnd() ) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = not_test();
        left = p;
        tok = tokenizer.getToken();
    }

    tokenizer.ungetToken();
    return left;

}

ExprNode *Parser::not_test() {

    // This function parses the grammar rules:
    // <not_test> -> ’not’ <not_test> | <rel_expr>

    Token tok = tokenizer.getToken();

    if ( tok.isNot() ) {
        ExprNode *right = not_test();
        PrefixExprNode *p = new PrefixExprNode(tok);
        p->right() = right;
        right = p;
        tokenizer.ungetToken();
        return right;
    }
    else {
        tokenizer.ungetToken();
        ExprNode *right = rel_expr();
        return right;
    }

    return nullptr;  // Will not reach this statement!
}


ExprNode *Parser::rel_expr() {
    // This function parses the grammar rules:
    // <rel_term> -> <expr> { (== | != | <> | > | >= | < | <=) <expr> }

    ExprNode *left = expr();
    Token tok = tokenizer.getToken();
    while (tok.isEqualTo() || tok.isNotEqualTo() || tok.isNotEqualTo2() || tok.isGreaterThan() ||
    tok.isGreaterThanOrEqual() || tok.isLessThan() || tok.isLessThanOrEqual()) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = expr();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::expr() {
    // This function parses the grammar rules:
    // <expr> -> <term> { <add_op> <term> }
    // <add_op> -> + | -

    // However, it makes the <add_op> left associative.

    ExprNode *left = term();
    Token tok = tokenizer.getToken();
    while (tok.isAdditionOperator() || tok.isSubtractionOperator()) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = term();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::term() {
    // This function parses the grammar rules:
    // <term> -> <factor> { <mult_op> <factor> }
    // <mult_op> -> * | / | % | //

    ExprNode *left = factor();
    Token tok = tokenizer.getToken();

    while (tok.isMultiplicationOperator() || tok.isDivisionOperator() || tok.isModuloOperator()
    || tok.isFloorDivision()) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = factor();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::factor() {

    // This function parses the grammar rules:
    // <factor> -> {’-’} <factor> | <primary>

    Token tok = tokenizer.getToken();

    if(tok.isSubtractionOperator()) {
        ExprNode *right = factor();
        PrefixExprNode *p = new PrefixExprNode(tok);
        p->right() = right;
        right = p;
        return right;
    }
    else {
        tokenizer.ungetToken();
        return primary();
    }

}

ExprNode *Parser::id() {

    Token tok = tokenizer.getToken();

    if (tok.isName()) {
        return new Variable(tok);
    }
    else {
        die("Parser::id", "Unexpected token", tok);
    }

    return nullptr; //will never hit
}

ExprNode *Parser::primary() {
    // This function parses the grammar rules:

    // <primary> -> [0-9]+
    // <primary> -> [0.0-inf+]+
    // <primary> -> [_a-zA-Z]+
    // <primary> -> (<expr>)

    Token tok = tokenizer.getToken();

    if (tok.isWholeNumber() )
        return new WholeNumber(tok);
    else if( tok.isDecimalNumber() )
        return new DecimalNumber(tok);
    else if( tok.isName())
        return new Variable(tok);
    else if( tok.isKeyword())
        return new Keyword(tok);
    else if( tok.isString())
        return new String(tok);
    else if (tok.eof()) {
        std::cout << "Error" << std::endl;
        exit(3432);
    }
    else if (tok.isOpenParen()) {
        ExprNode *p = or_test();
        Token token = tokenizer.getToken();
        if (!token.isCloseParen())
            die("Parser::primary", "Expected close-parenthesis, instead got", token);
        return p;
    }
    die("Parser::primary", "Unexpected token", tok);

    return nullptr;  // Will not reach this statement!
}
