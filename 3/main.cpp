#include <iostream>

struct Expression {
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : public Expression {
public: 
    double evaluate() const {
        return value;
    }

    Number(double _value)
        : value(_value) {}

private:
    double value;
};

struct BinaryOperation : public Expression {
public:
    double evaluate() const {
        switch (op) {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        default:
            return 0;
        }
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }
    BinaryOperation(const Expression *_left, char _op, const Expression *_right)
        : left(_left), op(_op), right(_right) {}

private:
    Expression const *left;
    Expression const *right;
    char op;
};

int main() {
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << std::endl;
    delete expr;
    
    return EXIT_SUCCESS;
}