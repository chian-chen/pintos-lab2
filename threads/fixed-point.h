#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

/* Fixed-point representation in 17.14 format (17 integer bits, 14 fractional bits). */
#define FP_F (1 << 14)
typedef int fp;

static inline fp int_to_fp(int n) {
    return n * FP_F;
}
static inline int fp_to_int_zero(fp x) {
    return x / FP_F;
}
static inline int fp_to_int_nearest(fp x) {
    if (x >= 0) {
        return (x + FP_F / 2) / FP_F;
    } else {
        return (x - FP_F / 2) / FP_F;
    }
}

static inline fp fp_add(fp x, fp y) {
    return x + y;
}
static inline fp fp_sub(fp x, fp y) {
    return x - y;
}

static inline fp fp_add_int(fp x, int n) {
    return x + n * FP_F;
}
static inline fp fp_sub_int(fp x, int n) {
    return x - n * FP_F;
}


static inline fp fp_mul(fp x, fp y) {
    return (fp)(((int64_t)x) * y / FP_F);
}
static inline fp fp_div(fp x, fp y) {
    return (fp)(((int64_t)x) * FP_F / y);
}


static inline fp fp_mul_int(fp x, int n) {
    return x * n;
}
static inline fp fp_div_int(fp x, int n) {
    return x / n;
}

#endif /* FIXED_POINT_H */
