/*
** EPITECH PROJECT, 2018
** move thing
** File description:
** yes
*/

#include "../include/duck_hunt.h"
#include "../include/graphic.h"
#include <stdlib.h>
#include <time.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void move_sprite(graphics_t *base, sfVector2f movement)
{
    sfVector2f place = sfSprite_getPosition(base->s_bird);

    sfSprite_move(base->s_bird, movement);
    sfRenderWindow_drawSprite(base->window, base->s_bird, NULL);
    if (place.x > 1920) {
        place.x = -110;
        movement.x = movement.x + 0.5;
        sfSprite_setPosition(base->s_bird, place);
    }
    if (place.y > 935) {
        movement.y *= -1;
        place.y = 990;
        sfSprite_setPosition(base->s_bird, place);
    }
    if (place.y < -55) {
        movement.y *= -1;
        place.y = place.y;
        sfSprite_setPosition(base->s_bird, place);
    }
}