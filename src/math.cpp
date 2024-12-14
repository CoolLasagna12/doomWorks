#include "math.h"

float Math::normalize(float angle) {
    const float PI = 3.14159265359f;
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
    const float PI = 3.14159265359f;
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

float Math::cosinus(float x) {
    return sinus(x, true)
}
