#include "trigoApprox.h"

namespace TrigoUtils {
    float sinus(float x, bool cos) {
        const float PI = 3.14159265359f;
        x = x * (PI / 180.0f);
        if (cos == true) {
          x -= 90;
        }
        x = fmod(x, 2 * PI);
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
}
