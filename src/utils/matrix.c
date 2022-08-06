#include "matrix.h"

#include <err.h>
#include <stdlib.h>
#include <string.h>

struct matrix* matrix_new(size_t height, size_t width)
{

    struct matrix *matrix = malloc(sizeof(struct matrix));

    if(matrix==NULL)
        errx(1, "matrix_new: Not enough memory");

    matrix->width = width;
    matrix->height = height;
    matrix->data = calloc(width*height, sizeof(unsigned char));

    if(matrix->data==NULL)
        errx(1, "matrix_new: Not enough memory");

    return matrix;
}

void matrix_free(struct matrix *matrix)
{
    free(matrix->data);
    free(matrix);
}

unsigned char matrix_get(struct matrix *matrix, size_t i, size_t j)
{
    if(i>=matrix->height || j>=matrix->width)
        return 0;
    return matrix->data[matrix->width*i+j];
}

void matrix_put(struct matrix *matrix, size_t i, size_t j, unsigned char value)
{
    if(i<matrix->height && j<matrix->width)
        matrix->data[matrix->width*i+j] = value;
}
