#ifndef MATH_H
#define MATH_H

class Math {
private:
    float normalize(float angle);
public:
    float sinus(float x, bool cos, bool multiply);
    float cosinus(float x, bool multiply);
    float sqrt(float x);
    float pow(float number, int exponent);
};

#endif
