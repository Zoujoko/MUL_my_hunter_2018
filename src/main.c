/*
** EPITECH PROJECT, 2018
** main duck hunt
** File description:
** yes
*/

#include "../include/graphic.h"
#include "../include/duck_hunt.h"
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio/Music.h>

void destroyer(graphics_t *base)
{
    sfTexture_destroy(base->t_back);
    sfTexture_destroy(base->t_bird);
    sfSprite_destroy(base->s_back);
    sfSprite_destroy(base->s_bird);
    sfMusic_destroy(base->theme);
    sfSound_destroy(base->bird);
    sfSoundBuffer_destroy(base->buffer_bird);
    sfText_destroy(base->score);
    sfText_destroy(base->score_number);
    sfRenderWindow_destroy(base->window);
}

void set_music(graphics_t *base)
{
    sfMusic_setLoop(base->theme, 1);
    sfSound_setVolume(base->bird, 25);
    sfMusic_setVolume(base->theme, 50);
    sfMusic_play(base->theme);
}

void clock(sfClock *clock, sfTime time, float seconds, sfIntRect *rect)
{
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.05) {
        move_rect(rect, 150, 600);
        sfClock_restart(clock);
    }
}

void window_open(graphics_t *base, sfIntRect rect, sfVector2f movement)
{
    sfRenderWindow_clear(base->window, sfBlack);
    sfRenderWindow_drawSprite(base->window, base->s_back, NULL);
    sfSprite_setTextureRect(base->s_bird, rect);
    move_sprite(base, movement);
    sight(base->window);
    sfRenderWindow_drawText(base->window, base->score, NULL);
    sfRenderWindow_display(base->window);
}

int main(void)
{
    graphics_t *base = malloc(sizeof(graphics_t));
    sfIntRect rect = {0, 0, 150, 150};
    sfVector2f place;
    sfVector2f movement = {4, 0};
    sfEvent event;

    create_struct(base);
    set_music(base);
    while (sfRenderWindow_isOpen(base->window))
    {
        window_open(base, rect, movement);
        clock(base->clock, base->time, base->seconds, &rect);
        event_manager(base, event, &movement);
    }
    destroyer(base);
    return (0);
}

