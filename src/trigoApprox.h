#ifndef TRIGO_APPROX_H
#define TRIGO_APPROX_H

class TrigoUtils {
public:
    static float modulo(float angle);
    
private:
    static float sinus(float x, bool cos);
};

#endif
