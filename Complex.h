#ifndef LABA3_COMPLEX_H
#define LABA3_COMPLEX_H

#include<cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class complex {
private:
    float x;
    float y;

public:
    //Constructor
    complex() {
        x = 0;
        y = 0;
    }

    complex(float real, float imagine) {
        x = real;
        y = imagine;
    }

    complex(const complex &ob) {
        x = ob.x;
        y = ob.y;
    };

    float real() const {
        return this->x;
    }

    float imag() const {
        return this->y;
    }

    complex operator+(float val) const {
        return complex(this->x + val, this->y);
    }

    complex operator-(float val) const {
        return complex(this->x - val, this->y);
    }

    complex operator+(const complex &val) const {
        return complex(this->x + val.x, this->y + val.y);
    }

    complex operator-(const complex &val) const {
        return complex(this->x - val.x, this->y - val.y);
    }

    //Multiplying on float number
    complex operator*(int val) const {
        return complex(this->x * val, this->y * val);
    }

    //Multiplying on complex number
    complex operator*(complex val) const {
        return complex(this->x * val.x - this->y * val.y, this->x * val.y + this->y * val.x);
    }

    bool operator==(const complex& val) const {
        return this->x == val.real() && this->y == val.imag();
    }

    bool operator!=(const complex& val) const {
        return !this->operator==(val);
    }

    bool operator<(const complex& val) const
    {
        return this->real() < val.real();
    }

    bool operator<=(const complex& val) const
    {
        return this->real() <= val.real();
    }
    bool operator>(const complex& val) const
    {
        return this->real() > val.real();
    }

    bool operator>=(const complex& val) const
    {
        return this->real() >= val.real();
    }
    void print_complex() const {
        cout << this->x <<"+(" << this->y << ")" << "i" << setw(3);
    }

};



#endif //LABA3_COMPLEX_H
