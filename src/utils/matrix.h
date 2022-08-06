#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

struct matrix
{
    size_t width;
    size_t height;
    unsigned char *data;
};

struct matrix* matrix_new(size_t height, size_t width);

void matrix_free(struct matrix *matrix);

unsigned char matrix_get(struct matrix *matrix, size_t i, size_t j);

void matrix_put(struct matrix *matrix, size_t i, size_t j, unsigned char value);

#endif /* ! MATRIX_H */
