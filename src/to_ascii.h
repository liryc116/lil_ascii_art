#ifndef TO_ASCII_H
#define TO_ASCII_H

#include <SDL/SDL.h>

void to_grayscale(SDL_Surface *img);

struct matrix *to_matrix(SDL_Surface *img);

struct matrix *to_scale(struct matrix *big_mat, size_t pixel_divider);

void to_ascii(struct matrix *matrix);

void print_matrix(struct matrix *matrix);

#endif /* ! TO_ASCII_H */
