#ifndef TRIGOAPPROX_H
#define TRIGOAPPROX_H

namespace TrigoUtils {
    
    class Trigo {
    public:
        static float sinus(float x, bool cos);
    private:
        static float modulo(float angle);
    };
}

#endif
