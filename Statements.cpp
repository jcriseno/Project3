//
// Created by smith on 3/20/2019.
//

#include "Statements.hpp"
#include "TypeDescriptor.hpp"
#include "Functions.hpp"

// Statement
Statement::Statement() {}

// Statements
Statements::Statements() {}
void Statements::addStatement(Statement *statement) { _statements.push_back(statement); }

void Statements::print() {
    for (auto s: _statements)
        s->print();
}

void Statements::evaluate(SymTab &symTab) {
    for (auto s: _statements)
        s->evaluate(symTab);
}

const std::vector<Statement *> &Statements::get_statements() const {
    return _statements;
}

// AssignmentStatement
AssignmentStatement::AssignmentStatement() : _lhsVariable{""}, _rhsExpression{nullptr} {}

AssignmentStatement::AssignmentStatement(std::string lhsVar, ExprNode *rhsExpr):
        _lhsVariable{lhsVar}, _rhsExpression{rhsExpr} {}

void AssignmentStatement::evaluate(SymTab &symTab) {
    TypeDescriptor rhs = rhsExpression()->evaluate(symTab);
    symTab.setValueFor(lhsVariable(), rhs);
}

std::string &AssignmentStatement::lhsVariable() {
    return _lhsVariable;
}

ExprNode *&AssignmentStatement::rhsExpression() {
    return _rhsExpression;
}

void AssignmentStatement::print() {
    bool isString = false;
    if(_rhsExpression->token().isString())
        isString = true;
    if(isString) {
        std::cout << _lhsVariable << " = ";
        std::cout << "\"";
        _rhsExpression->print();
        std::cout << "\"";
        std::cout << std::endl;
    }
    else {
        std::cout << _lhsVariable << " = ";
        _rhsExpression->print();
        std::cout << std::endl;
    }
}

void AssignmentStatement::print2() {
    std::cout << _lhsVariable << " = ";
    _rhsExpression->print();
}




// PrintStatement
PrintStatement::PrintStatement() : _lhsVariable{""}, _rhsExpression{nullptr} {}

PrintStatement::PrintStatement(std::string lhsVar, ExprNode *rhsExpr):
        _lhsVariable{lhsVar}, _rhsExpression{rhsExpr} {}

void PrintStatement::evaluate(SymTab &symTab) {
    TypeDescriptor rhs = rhsExpression()->evaluate(symTab);
    std::cout << /*"[OUTPUT] Printing -> " <<*/ rhs << std::endl;
}

std::string &PrintStatement::lhsVariable() {
    return _lhsVariable;
}

ExprNode *&PrintStatement::rhsExpression() {
    return _rhsExpression;
}

void PrintStatement::print() {
    std::cout << _lhsVariable << " ";
    _rhsExpression->print();
    std::cout << std::endl;
}

// ForStatement
ForStatement::ForStatement() : _firstExpr{nullptr}, _secondExpr{nullptr}, _firstState{nullptr} {}

ForStatement::ForStatement(ExprNode *expr1, ExprNode *expr2, Statements *State):
        _firstExpr{expr1}, _secondExpr{expr2}, _firstState{State} {}


void ForStatement::evaluate(SymTab &symTab) {

    range rangeValue;
    TypeDescriptor values = secondExpr()->evaluate(symTab);
    TypeDescriptor currentIteratorValue;

    rangeValue.setValues(values);

    currentIteratorValue = rangeValue.getStartValue();
    const int stepValue = rangeValue.getStepValue();

    Token id = firstExpr()->token();

    if(stepValue < 0) {
        while (rangeValue.getStartValue() > rangeValue.getEndValue()) {

            symTab.setValueFor(id.getName(), currentIteratorValue);

            firstExpr()->evaluate(symTab);

            firstState()->evaluate(symTab); // Evaluates statement

            rangeValue.next(); //iterates to next value

            currentIteratorValue = rangeValue.getStartValue(); //updates currentIteratorValue
        }
    }
    else {
        while (rangeValue.getStartValue() < rangeValue.getEndValue()) {

            symTab.setValueFor(id.getName(), currentIteratorValue);

            firstExpr()->evaluate(symTab);

            firstState()->evaluate(symTab); // Evaluates statement

            rangeValue.next(); //iterates to next value

            currentIteratorValue = rangeValue.getStartValue(); //updates currentIteratorValue
        }
    }
}

ExprNode *&ForStatement::firstExpr() {
    return _firstExpr;
}

ExprNode *&ForStatement::secondExpr() {
    return _secondExpr;
}

Statements *&ForStatement::firstState() {
    return _firstState;
}

void ForStatement::print() {
    std::cout << "for ";
    _firstExpr->print();
    std::cout << " in range(";
    _secondExpr->print();
    std::cout << "):" << std::endl;
    std::cout << "[INDENT]" << std::endl;
    _firstState->print(), std::cout << "[DEDENT]" << std::endl;
}

// IfStatement
IfStatement::IfStatement() : _ifExpr{nullptr}, _ifStatements{nullptr}, _elifExpr{nullptr},
                             _elifStatements{nullptr}, _elseStatements{nullptr}, _isElseTrue{"false"} {}

IfStatement::IfStatement(ExprNode *ifExpr, Statements *ifStatements, std::vector<ExprNode *> elifExpr,
                         std::vector<Statements *> elifStatements, Statements *elseStatements,
                         bool isElseTrue):
        _ifExpr{ifExpr}, _ifStatements{ifStatements}, _elifExpr{elifExpr},
        _elifStatements{elifStatements}, _elseStatements{elseStatements},
        _isElseTrue{isElseTrue} {}

ExprNode *&IfStatement::ifExpr() {
    return _ifExpr;
}

Statements *&IfStatement::ifStatements() {
    return _ifStatements;
}

Statements *&IfStatement::elseStatements() {
    return _elseStatements;
}

void IfStatement::evaluate(SymTab &symTab) {
    TypeDescriptor ifExpression = ifExpr()->evaluate(symTab);
    bool skip = false;

    if(ifExpression.getBoolValue()) {
        skip = true;
        ifStatements()->evaluate(symTab);
    }
    else if(_elifExpr.size()) {
        for (auto i = 0; i < _elifExpr.size(); i++) {
            TypeDescriptor elifExpression = _elifExpr[i]->evaluate(symTab);
            if(elifExpression.getBoolValue()) {
                skip = true;
                _elifStatements[i]->evaluate(symTab);
                break;
            }
        }
    }
    if (!skip && _isElseTrue){
        elseStatements()->evaluate(symTab);
    }
}

void IfStatement::print() {
    std::cout << "if ";
    ifExpr()->print();
    std::cout << ":" << std::endl;
    ifStatements()->print();
    for(auto i = 0; i < _elifExpr.size(); i++) {
        std::cout << "elif ", _elifExpr[i]->print();
        std::cout << ":" << std::endl;
        _elifStatements[i]->print();
    }
    if(_elseStatements) {
        std::cout << "else";
        std::cout << ":" << std::endl;
        elseStatements()->print();
    }
}

// Function def
Function_def::Function_def() : _fName{""}, _Expr1{nullptr}, _parameter_list{nullptr}, _state{nullptr}, _statements{nullptr} {}

Function_def::Function_def(ExprNode *Expr1, std::vector<ExprNode *> *parameter_list, Statements *state) :
    _Expr1{Expr1}, _parameter_list{parameter_list}, _state{state} {}

Function_def::Function_def(ExprNode *Expr1, std::vector<ExprNode *> *parameter_list, std::vector<Statement *> statements) :
    _Expr1{Expr1}, _parameter_list{parameter_list}, _statements{statements} {}

Function_def::Function_def(std::string fName, std::vector<ExprNode *> *parameter_list, Statements *state) :
    _fName{fName}, _parameter_list{parameter_list}, _state{state} {}

ExprNode *Function_def::get_Expr1() const {
    return _Expr1;
}

Statements *Function_def::get_state() const {
    return _state;
}

const std::vector<Statement *> &Function_def::get_statements() const {
    return _statements;
}

std::vector<ExprNode *> *Function_def::get_parameter_list() const {
    return _parameter_list;
}

void Function_def::addStatement(Statement *statement) {
    _statements.push_back(statement);
}


void Function_def::evaluate(SymTab &symTab) {
    /*
    for (auto s: get_state()->get_statements()) {
        s->evaluate(symTab);
    }
    symTab.addFunction(get_fName(), this);
    */
    //just run stmts evaluate
    get_state()->evaluate(symTab);
}

void Function_def::print() {
    return;
}

const std::string &Function_def::get_fName() const {
    return _fName;
}








