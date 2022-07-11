#include "mlx.h"

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "so_long");
    mlx_loop(mlx_ptr);
}
//gcc main.c -Iminilibx-linux -I/usr/include -L/usr/lib -lXext -lX11 -Lminilibx-linux -lmlx