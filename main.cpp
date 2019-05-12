// Name: Jevan Smith
// Assignment: Project02
// Date: February 28, 2019

#include <iostream>
#include <vector>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Parser.hpp"
#include "TypeDescriptor.hpp"

int main(int argc, char *argv[]) {

    if( argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }

    std::ifstream inputStream;

    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        perror("Error when attempting to open the input file.");
        exit(2);
    }

    Tokenizer tokenizer(inputStream);
    Parser parser(tokenizer);
    Statements *statements = parser.statements();
    SymTab symTab;

    //Initalizing the global scope for the symTab vector
    symTab.openScope();

    /*std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[MESSAGE] Starting print: " << std::endl;
    std::cout << "--------------------------------" << std::endl;
    statements->print();*/
    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[MESSAGE] Program Output: " << std::endl;
    std::cout << "--------------------------------" << std::endl;
    statements->evaluate(symTab);

    Token token = tokenizer.getToken();

    return 0;
}
