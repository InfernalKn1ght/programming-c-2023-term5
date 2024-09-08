#include "Expr.h"

double Const::eval(double x) const {
    return value;
}

void Const::print() const {
    std::cout << value;
}

Expr *Const::der() const {
    return new Const(0);
}

Expr *Const::clone() const {
    return new Const(value);
}



double Var::eval(double x) const {
    return x;
}

void Var::print() const {
    std::cout << "x";
}

Expr *Var::der() const {
    return new Const(1);
}

Expr *Var::clone() const {
    return new Var;
}



double Sum::eval(double x) const {
    return left->eval(x) + right->eval(x);
}

void Sum::print() const {
    left->print();
    std::cout << "+";
    right->print();
}

Expr *Sum::der() const {
    return new Sum(left->der(), right->der());
}

Expr *Sum::clone() const {
    return new Sum(left->clone(), right->clone());
}



double Prod::eval(double x) const {
        return left->eval(x) * right->eval(x);
    }

    void Prod::print() const {
        left->print();
        std::cout << "*";
        right->print();
    }

    Expr *Prod::der() const {
        return new Sum(new Prod(left->der(), right->clone()), new Prod(left->clone(), right->der()));
    }

    Expr *Prod::clone() const {
        return new Prod(left->clone(), right->clone());
    }



    double Sin::eval(double x) const {
        return std::sin(x);
    }

    void Sin::print() const {
        std::cout << "sin(";
        argument->print();
        std::cout << ")";
    }

    Expr *Sin::der() const {
        return new Prod(argument->der(), new Cos(argument->clone()));
    }

    Expr *Sin::clone() const {
        return new Sin(argument->clone());
    }



        double Cos::eval(double x) const {
        return std::cos(x);
    }

    void Cos::print() const {
        std::cout << "cos(";
        argument->print();
        std::cout << ")";
    }

    Expr *Cos::der() const {
        return new Prod(argument->der(), new Prod(new Const(-1), new Sin(argument->clone())));
    }

    Expr *Cos::clone() const {
        return new Cos(argument->clone());
    }
