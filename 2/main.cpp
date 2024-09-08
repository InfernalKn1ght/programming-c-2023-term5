#include <iostream>

class Payment {
private:
    std::string address;

public:
    Payment(std::string _address) : address(_address) {}
    virtual double checkout() = 0;
    virtual ~Payment() {}
};

class Heat : public Payment {
private:
    double square;

public:
    double checkout() {
        return square * 50;
    }
    Heat(std::string _address, double _square) : Payment(_address), square(_square) {}
};

class Water : public Payment {
private:
    double quantity;

public:
    double checkout() {
        return quantity * 200;
    }
    Water(std::string _address, double _quantity) : Payment(_address), quantity(_quantity) {}
};

class Electricity : public Payment {
private:
    double kilowatth;

public:
    double checkout() {
        return kilowatth * 5;
    }
    Electricity(std::string _address, double _kilowatth) : Payment(_address), kilowatth(_kilowatth) {}
};

int main() {
    Payment **arr = new Payment*[7];
    arr[0] = new Heat("street 1", 30);
    arr[1] = new Heat("street 2", 20);
    arr[2] = new Water("street 3", 5);
    arr[3] = new Water("street 4", 6);
    arr[4] = new Water("street 5", 7);
    arr[5] = new Electricity("street 6", 100);
    arr[6] = new Electricity("street 7", 200);

    for (int i = 0; i < 7; ++i) {
        std::cout << arr[i]->checkout() << std::endl;
    }

    for (int i = 0; i < 7; ++i) {
        delete arr[i];
    }
    delete[] arr;

    return EXIT_SUCCESS;
}