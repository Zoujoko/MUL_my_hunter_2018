/*
** EPITECH PROJECT, 2018
** create struct
** File description:
** yes
*/
#include "../include/duck_hunt.h"
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int create_struct(graphics_t *graphic)
{
    sfVideoMode mode = {1920, 1080, 32};
    graphic->window = sfRenderWindow_create(mode, "Social Hunt", sfDefaultStyle 
    , NULL);
    if (!graphic->window)
        return (84);
    graphic->t_back = sfTexture_createFromFile("./add/google.png", NULL);
    graphic->s_back = sfSprite_create();
    if (!graphic->s_back)
        return (84);
    sfSprite_setTexture(graphic->s_back, graphic->t_back, sfTrue);
    graphic->theme = sfMusic_createFromFile("./add/theme.ogg");
    sfRenderWindow_setFramerateLimit(graphic->window, 80);
    create_struct_part_2(graphic);
    return (0);
}

int create_struct_part_2(graphics_t *graphic)
{
    graphic->t_bird =  sfTexture_createFromFile("./add/twitter.png", NULL);
    if (!graphic->t_bird)
        return (84);
    graphic->s_bird = sfSprite_create();
    if (!graphic->s_bird)
        return (84);
    sfSprite_setTexture(graphic->s_bird, graphic->t_bird, sfTrue);
    sfSprite_setRotation(graphic->s_bird, 30);
    graphic->buffer_bird = sfSoundBuffer_createFromFile("./add/bird.ogg");
    graphic->bird = sfSound_create();
    sfSound_setBuffer(graphic->bird, graphic->buffer_bird);
    graphic->clock = sfClock_create();
    create_struct_part_3(graphic);
    return (0);
}

int create_struct_part_3(graphics_t *graphic)
{
    sfVector2f score = {0, 0};

    graphic->score = sfText_create();
    sfText_setString(graphic->score, "Your Score : ");
    sfText_setPosition(graphic->score, score);
    sfText_setColor(graphic->score, sfWhite);
    sfText_setOutlineColor(graphic->score, sfBlack);
    sfText_setOutlineThickness(graphic->score, 2);
    graphic->life = 3;
    graphic->t_heart = sfTexture_createFromFile("./add/heart.png", NULL);
    graphic->s_heart = sfSprite_create();
    sfSprite_setTexture(graphic->s_heart, graphic->t_heart, sfTrue);
    return (0);
}