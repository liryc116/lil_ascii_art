#include "to_ascii.h"

#include "utils/pixel_operation.h"
#include "utils/matrix.h"

#include <stddef.h>
#include <math.h>

void to_grayscale(SDL_Surface *img)
{
    for(int i = 0; i<img->w; i++)
    {
        for(int k = 0; k<img->h; k++)
        {
            Uint32 pixel = get_pixel(img, i, k);
            Uint8 r,g,b;
            SDL_GetRGB(pixel, img->format, &r, &g, &b);

            r = 0.3*r + 0.59*g + 0.11*b;

            pixel = SDL_MapRGB(img->format, r, r, r);

            put_pixel(img, i, k, pixel);
        }

    }
}

struct matrix *to_matrix(SDL_Surface *img)
{
    struct matrix *matrix = matrix_new(img->h, img->w);

    for(int i = 0; i<img->h; i++)
    {
        for(int k = 0; k<img->w; k++)
        {
            Uint32 pixel = get_pixel(img, k, i);
            Uint8 gray;
            SDL_GetRGB(pixel, img->format, &gray, &gray, &gray);

            matrix_put(matrix, i, k, (unsigned char)gray);
        }
    }

    return matrix;
}

struct matrix *to_scale(struct matrix *big_mat, size_t pixel_divider)
{
    struct matrix *small_mat = matrix_new(big_mat->height/pixel_divider,
                                         	2*big_mat->width/pixel_divider);

    size_t normal = pixel_divider * (size_t) round(pixel_divider/2);

    for(size_t i = 0; i<small_mat->height; i++)
    {
        for(size_t k = 0; k<small_mat->width; k++)
        {
            unsigned long long sum = 0;
            size_t x = i*pixel_divider;
            size_t y = k*pixel_divider/2;
            for(size_t a = 0; a<pixel_divider; a++)
            {
                for(size_t b = 0; b<pixel_divider/2; b++)
                    sum += matrix_get(big_mat, x+a, y+b);
            }

            matrix_put(small_mat, i, k, sum/normal);
        }
    }

    return small_mat;
}

void to_ascii(struct matrix *matrix)
{
    unsigned char symbol[11] = " .:-=+*#%@";
    size_t symbol_len = 10;
    double normal = 255.0/(double)symbol_len;

	double val = 0;
    for(size_t i = 0; i<matrix->height; i++)
    {
        for(size_t k = 0; k<matrix->width; k++)
        {
            val = ((double) matrix_get(matrix, i, k))/normal;
            matrix_put(matrix, i, k, symbol[(int)round(val)]);
        }
    }

}

void print_matrix(struct matrix *matrix)
{
	printf("height: %ld, width: %ld\n", matrix->height, matrix->width);
    for(size_t i = 0; i<matrix->height; i++)
    {
        for(size_t k = 0; k<matrix->width; k++)
            printf("%c", matrix_get(matrix, i, k));
		printf("\n");
    }
}
