#include "func.h"

string ToStr(float value)
{
    return to_string(value);
}

string ToStr(int value)
{
    return to_string(value);
}

string ToStr(complex value)
{
    string result = to_string(value.real()) + " ";
    result = result + "+ (" + to_string(value.imag()) + ")i";
    return result;
}

float DoubleUp(float value){
    return value * 2;
}
int DoubleUp(int value){
    return value * 2;
}

complex DoubleUp(complex value){
    complex* res = new complex(value.real()*2, value.imag()*2);
    return *res;
}

bool NotZero(float value){
    bool res = false;
    if (value != 0)
        res = true;
    return res;
}

bool NotZero(int value){
    bool res = false;
    if (value != 0)
        res = true;
    return res;
}

bool NotZero(complex value){
    bool res = false;
    if (value != complex(0,0))
        res = true;
    return res;
}
void print(int val){
    cout << val;
}
void print(float val){
    cout << val;
}
void print(complex val){
    val.print_complex();
}
