#include "to_ascii.h"

#include "utils/pixel_operation.h"
#include "utils/matrix.h"

#include <SDL/SDL.h>
#include <err.h>

int main(int argc, char *argv[])
{
	if(argc<2)
		errx(1, "Usage: %s *image_path*", argv[0]);

	SDL_Surface *img = load_image(argv[1]);

	to_grayscale(img);

	struct matrix *big_mat = to_matrix(img);

	struct matrix *small_mat = to_scale(big_mat, 10);

	to_ascii(small_mat);

	print_matrix(small_mat);


	matrix_free(small_mat);
	matrix_free(big_mat);
	SDL_FreeSurface(img);


	return 0;
}
