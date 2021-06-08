#ifndef LABA3_FUNC_H
#define LABA3_FUNC_H

#include <string>
#include "Complex.h"
using namespace std;

string ToStr(float value);
string ToStr(int value);
string ToStr(complex value);
float DoubleUp(float value);
int DoubleUp(int value);
complex DoubleUp(complex value);
bool NotZero(float value);
bool NotZero(int value);
bool NotZero(complex value);
void print(int val);
void print(float val);
void print(complex val);
#endif //LABA3_FUNC_H
