#include "trigoApprox.h"

class TrigoUtils {
private:
    static float modulo(float angle) {
        while (angle < 0) {
            angle += 360.0f;
        }
        while (angle >= 360) {
            angle -= 360.0f;
        }
        return angle;
    }
public:
    static float sinus(float x, bool cos) {
        const float PI = 3.14159265359f;
        x = x * (PI / 180.0f);
        if (cos == true) {
            x -= PI / 2;
        }
        x = modulo(x);
        float term = x;
        float sinus = term;
        int sign = -1;
        for (int i = 3; i <= 15; i += 2) {
            term *= x * x / (i * (i - 1));
            sinus += sign * term;
            sign *= -1;
        }
        return sinus;
    }
};
