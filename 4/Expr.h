#include <cmath>
#include <iostream>

class Expr {
public:
    virtual double eval(double x) const = 0;
    virtual void print() const = 0;
    virtual Expr *der() const = 0;
    virtual Expr *clone() const = 0;
    virtual ~Expr() {}
};

class Const : public Expr {
private:
    double value;

public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Const(double _value) : value(_value) {}
};

class Var : public Expr {
public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Var() {}
};

class Sum : public Expr {
private:
    const Expr *left;
    const Expr *right;

public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Sum(const Expr *_left, const Expr *_right) : left(_left), right(_right) {}
    ~Sum() {
        delete left;
        delete right;
    }
};

class Prod : public Expr {
private:
    Expr *left;
    Expr *right;

public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Prod(Expr *_left, Expr *_right) : left(_left), right(_right) {}
    ~Prod() {
        delete left;
        delete right;
    }
};

class Sin : public Expr {
private:
    Expr *argument;

public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Sin(Expr *_argument) : argument(_argument) {}
    ~Sin() {
        delete argument;
    }
};

class Cos : public Expr {
private:
    Expr *argument;

public:
    double eval(double x) const;
    void print() const;
    Expr *der() const;
    Expr *clone() const;

    Cos(Expr *_argument) : argument(_argument) {}
    ~Cos() {
        delete argument;
    }
};
