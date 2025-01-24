#include "math.h"

const float PI = 3.14159265359f;

float Math::normalize(float angle) {
    const float TWO_PI = 2.0f * PI;
    while (angle > TWO_PI) {
        angle -= TWO_PI;
    }
    while (angle < TWO_PI) {
        angle += TWO_PI;
    }
    if (angle > PI) {
        angle -= TWO_PI;
    }
    else if (angle < -PI) {
        angle += TWO_PI;
    }
    return angle;
}
float Math::sinus(float x, bool cos = false) {
    if (cos) {
        x -= 90.0f;
    }
    x = x * (PI / 180.0f);
    x = normalize(x);
    float term = x;
    float sinus = term;
    int sign = -1;
    for (int i = 3; i <= 15; i += 2) {
        term *= (x * x) / (i * (i - 1));
        sinus += sign * term;
        sign *= -1;
    }
    return sinus;
}

float Math::sqrt(float x) {
    if (x < 0) {
        return -1;
    }
    float guess = x / 2.0;
    float epsilon = 0.01;
    float diff = 1;

    while(diff > epsilon) {
        float new_guess = (guess + x / guess) / 2.0;
        diff = (new_guess - guess > 0) ? (new_guess - guess) : (guess - new_guess);
        guess = new_guess;
    }
    return guess;
}

int Math::floor(float x) {
    if (x == (int)x) {
        return x;
    }
    if (x > 0) {
        return (int)x;
    }
    return (int)x - 1;
}

float Math::pow(float number, int exponent) {
    double result = 1.0;
    bool negative = false;
    if (exponent < 0) {
        negative = true;
        exponent = -exponent;
    }
    for (int i = 1; i <= exponent; i++) {
        result *= number;
    }
    if (negative) {
        return 1.0 / result;
    }
    return result;
}

float Math::abs(float x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

float Math::cosinus(float x) {
    return sinus(x, true);
}