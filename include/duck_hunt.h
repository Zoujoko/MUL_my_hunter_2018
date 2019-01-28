/*
** EPITECH PROJECT, 2018
** all functions of  duck hunt
** File description:
** yes
*/
#include "graphic.h"

//function to create the struct
int create_struct(graphics_t *graphic);
int create_struct_part_2(graphics_t *graphic);
int create_struct_part_3(graphics_t *graphic);

//movement function
void move_sprite(graphics_t *base, sfVector2f movement);
void move_rect(sfIntRect *rect, int offset, int max_value);
void rand_speed(graphics_t *base);

//sight event
void sight(sfRenderWindow *r_window);
void event_manager(graphics_t *base, sfEvent event, sfVector2f *movement);

//main
void window_open(graphics_t *base, sfIntRect rect, sfVector2f movement);
void destroyer(graphics_t *base);
