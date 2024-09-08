#include <iostream>

class Two {
private:
    int a;
    int b;

public:
    int study(int x) { // a b (x)
        if (b < x) { // ? b < x
            std::swap(b, x); // a x b
        }
        if (a < b) { // ? a < b(x)
            std::swap(a, b); // x a b
        }

        return x;
    }

    void print() {
        std::cout << "a = " << a << " b = " << b << " ";
    }

    Two(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }

        this->a = a;
        this->b = b;
    }
};

class Three : public Two {
private:
    int c;

public:
    int study(int x) {
        if (c < x) {
            std::swap(c, x);
            c = Two::study(c);
        }

        return x;
    }

    void print() {
        Two::print();
        std::cout << "c = " << c << std::endl;
    }

    Three(int x, int y, int z) : Two(x, y), c(Two::study(z)) {}
};

int main() {
    Two a(3, 18);
    Three b(1, 7, 9);
    a.study(19);
    a.print();
    b.study(11);
    b.print();

    return EXIT_SUCCESS;
}