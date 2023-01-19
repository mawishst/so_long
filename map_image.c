#include "so_long.h"

void    ft_close_game(t_mlx *mlx)
{
    mlx_destroy_image(mlx->start, mlx->photo->coin);
    mlx_destroy_image(mlx->start, mlx->photo->enemy);
    mlx_destroy_image(mlx->start, mlx->photo->exit);
    mlx_destroy_image(mlx->start, mlx->photo->ground);
    mlx_destroy_image(mlx->start, mlx->photo->player);
    mlx_destroy_image(mlx->start, mlx->photo->wall);
    free(mlx->mapsize->map);
    free(mlx->mapsize);
    free(mlx->photo);
    free(mlx->start);
    free(mlx->win);
}

void    ft_img_put(char s, t_mlx *mlx, t_photo *photo, t_temp *temp)
{
    if (s == 'C')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->coin, temp->l, temp->k);
    else if (s == 'E')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->exit, temp->l, temp->k);
    else if (s == '0')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->ground, temp->l, temp->k);
    else if (s == '1')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->wall, temp->l, temp->k);
    else if (s == 'P')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->player, temp->l, temp->k);
}

void    ft_img_idx(t_map *mapsize, t_mlx *mlx, t_photo *photo)
{
    t_temp  temp;

    temp.i = -1;
    temp.k = 0;
    while (mapsize->map[++temp.i])
    {
        temp.j = -1;
        temp.l = 0;
        while (mapsize->map[temp.i][++temp.j])
        {
            ft_img_put(mapsize->map[temp.i][temp.j], mlx, photo, &temp);
            temp.l += 64;
        }
        temp.k += 64;
    }
}

void    ft_img_addr(t_photo *photo, t_mlx *mlx)
{
    photo->exit = mlx_xpm_file_to_image(mlx->start, exit_path, &photo->x, &photo->y);
    photo->enemy = mlx_xpm_file_to_image(mlx->start, enemy_path, &photo->x, &photo->y);
    photo->player = mlx_xpm_file_to_image(mlx->start, p_normal_path, &photo->x, &photo->y);
    photo->coin = mlx_xpm_file_to_image(mlx->start, coin_path, &photo->x, &photo->y);
    photo->ground = mlx_xpm_file_to_image(mlx->start, ground_path, &photo->x, &photo->y);
    photo->wall = mlx_xpm_file_to_image(mlx->start, wall_path, &photo->x, &photo->y);
}