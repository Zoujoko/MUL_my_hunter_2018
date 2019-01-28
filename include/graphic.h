/*
** EPITECH PROJECT, 2018
** graphic struct
** File description:
** yes
*/

#pragma once

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct graphics_s{
    sfRenderWindow *window;
    sfTexture *t_back;
    sfTexture *t_bird;
    sfTexture *t_heart;
    sfSprite *s_back;
    sfSprite *s_bird;
    sfSprite *s_heart;
    sfText *score;
    sfText *score_number;
    int your_score;
    int life;
    sfText *life_remain;
    sfMusic *theme;
    sfSoundBuffer *buffer_bird;
    sfSound *bird;
    sfClock *clock;
    sfTime time;
    float seconds;
    float speed;
}              graphics_t;
