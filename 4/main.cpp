#include "Expr.h"
#include <cmath>
#include <iostream>

int main() {
    Expr *expr1 = new Sum(new Cos(new Var), new Prod(new Sin(new Var), new Const(5)));

    expr1->print();
    std::cout << std::endl;
    expr1->der()->print();
    std::cout << std::endl;
    delete expr1;

    return EXIT_SUCCESS;
}