/*
** EPITECH PROJECT, 2018
** score and sight
** File description:
** yes
*/
#include "../include/duck_hunt.h"
#include "../include/graphic.h"
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <time.h>

void sight(sfRenderWindow *window)
{
    sfSprite *sight_s = sfSprite_create();
    sfTexture *sight_t = sfTexture_createFromFile("./add/sight.png", NULL);
    sfVector2i pos_i = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_f;

    pos_f.x = pos_i.x - 90;
    pos_f.y = pos_i.y - 90;
    sfRenderWindow_setMouseCursorVisible(window, 0);
    sfSprite_setTexture(sight_s, sight_t, sfTrue);
    sfSprite_setPosition(sight_s, pos_f);
    sfRenderWindow_drawSprite(window, sight_s, NULL);
}

float rand_place_generator(void)
{
    int random = 0;
    const int Max = 800;
    const int Min = 0;

    srand(time(NULL));
    random = (rand() % (Max - Min + 1)) + Min;
    return (random);
}

void reset_sprite(graphics_t *base, sfVector2f *movement)
{
    sfVector2f place;

    place.x = -110;
    base->your_score += movement->x;
    place.y = rand_place_generator();
    movement->x = movement->x + 0.5;
    sfSprite_setPosition(base->s_bird, place);
    sfSound_play(base->bird);
}

void check_hitboxes(graphics_t *base, sfVector2f *movement)
{
    sfVector2i pos_mouse_i = sfMouse_getPositionRenderWindow(base->window);
    sfVector2f pos_sprite_f = sfSprite_getPosition(base->s_bird);
    int i = 0;

    if (pos_mouse_i.x > pos_sprite_f.x && pos_mouse_i.x < pos_sprite_f.x + 150)
        i++;
    if (pos_mouse_i.y > pos_sprite_f.y && pos_mouse_i.y < pos_sprite_f.y + 150)
        i++;
    if (i == 2)
        reset_sprite(base, movement);
}

void event_manager(graphics_t *base, sfEvent event, sfVector2f *movement)
{
    while (sfRenderWindow_pollEvent(base->window, &event)) {
        if (event.type == sfEvtClosed) {
            printf("Your score is : %d\n", base->your_score);
            sfRenderWindow_close(base->window);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            check_hitboxes(base, movement);
        }
    }
}