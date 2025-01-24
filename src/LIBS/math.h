#ifndef MATH_H
#define MATH_H

class Math {
private:
    float normalize(float angle);
public:
    float sinus(float x, bool cos);
    float cosinus(float x);
    float sqrt(float x);
    float abs(float x);
    float pow(float number, int exponent);
    int floor(float x);
};

#endif
