#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    void	*mlx_ptr;
    void	*win_ptr;
    void	*img_ptr;
    void	*img_ptr2;
    int		i;

    i = 64;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
    if (!(img_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/floor.xpm", &i, &i)))
    {
	    printf(" !! KO !!\n");
	    exit(1);
    }
    if (!(img_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "assets/knight.xpm", &i, &i)))
    {
            printf(" !! KO !!\n");
	    exit(1);
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 128);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 128);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 128, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 128, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 128, 128);
   // mlx_destroy_image(mlx_ptr, img_ptr);
    sleep(1);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, 64, 64);
    sleep(1);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, 128, 128);
    mlx_loop(mlx_ptr);
    return (0);

}
//gcc main.c -Iminilibx-linux -I/usr/include -L/usr/lib -lXext -lX11 -Lminilibx-linux -lmlx
