/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#define N 10

int wbox = 0;
int lev;
struct Object obj[N] = {};

void levList(int *h, int *w, int *array, t_soko soko)
{
    if (soko.n == 0)
    {
        *h = 7;
        *w = 6;
        int map0[7][6] = {
            {1, 1, 1, 1, 1, 1},
            {1, 0, 2, 1, 1, 1},
            {1, 0, 0, 1, 1, 1}, 
            {1, 2, 5, 0, 0, 1},
            {1, 4, 0, 4, 0, 1},
            {1, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1}};
            *array = map0[soko.y][soko.x];
    }
    else if (soko.n == 1) {
        *h = 9;
        *w = 10;
        int map1[9][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 0, 1, 0, 2, 1, 1, 1},
            {1, 0, 0, 0, 0, 4, 0, 1, 1, 1},
            {1, 1, 1, 0, 1, 4, 2, 0, 0, 1},
            {1, 0, 0, 0, 1, 5, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
            *array = map1[soko.y][soko.x];
    }
}

void palette(void)
{
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

void Level(int lev)
{
    t_soko soko;

    clear();
    mvprintw(1, 8, "Oops soko... Map -> %d", lev);
    mvprintw(2, 1, "Move_ARROW. Restart-R. Map-M. Exit-Q");
    soko.x = 0, soko.y = 0;
    int h = 1, w = 1, map;
    wbox = 0;

    for (soko.y = 0; soko.y < h; soko.y++) {
        for (soko.x = 0; soko.x < w; soko.x++) {
            levList(&h, &w, &map, soko);
            switch (map) {
                case 0: mvaddch(soko.y + 4, soko.x + 10, ' ' | COLOR_PAIR(4));
                break;
                case 1: mvaddch(soko.y + 4, soko.x + 10, '#' | COLOR_PAIR(1));
                break;
                case 2: mvaddch(soko.y + 4, soko.x + 10, 'O' | COLOR_PAIR(2));
                break;
                case 4:
                    mvaddch(soko.y + 4, soko.x + 10, ' ' | COLOR_PAIR(4));
                    wbox += 1;
                    obj[wbox].ozn = mvinch(soko.y + 4 , soko.x + 10);
                    obj[wbox].yPosition = soko.y + 4;
                    obj[wbox].xPosition = soko.x + 10;
                    obj[wbox].zn = 'X';
                    mvaddch(obj[wbox].yPosition, obj[wbox].xPosition,
                    obj[wbox].zn | COLOR_PAIR(5));
                    break;
                case 5 :
                    mvaddch(soko.y + 4, soko.x + 10, ' ' | COLOR_PAIR(4));
                    wbox += 1;
                    obj[0].ozn = mvinch(soko.y + 4 , soko.x + 10);
                    obj[0].yPosition = soko.y + 4;
                    obj[0].xPosition = soko.x + 10;
                    obj[0].zn = 'P';
                    mvaddch(obj[0].yPosition, obj[0].xPosition, obj[0].zn |
                    COLOR_PAIR(3));
                    break;
            }
        }
    }
    move(obj[0].yPosition, obj[0].xPosition);
}

void Play(int input)
{
    bool restart = FALSE;

    chtype up, lf, dw, rg, oup, olf, odw, org;
    up = (mvinch(obj[0].yPosition - 1, obj[0].xPosition) & A_CHARTEXT);
    lf = (mvinch(obj[0].yPosition, obj[0].xPosition - 1) & A_CHARTEXT);
    dw = (mvinch(obj[0].yPosition + 1, obj[0].xPosition) & A_CHARTEXT);
    rg = (mvinch(obj[0].yPosition, obj[0].xPosition + 1) & A_CHARTEXT);
    oup = (mvinch(obj[0].yPosition - 2, obj[0].xPosition) & A_CHARTEXT);
    olf = (mvinch(obj[0].yPosition, obj[0].xPosition - 2) & A_CHARTEXT);
    odw = (mvinch(obj[0].yPosition + 2, obj[0].xPosition) & A_CHARTEXT);
    org = (mvinch(obj[0].yPosition, obj[0].xPosition + 2) & A_CHARTEXT);

    for (int o = 0; o <= wbox; o++) {
        mvaddch(obj[o].yPosition, obj[o].xPosition, obj[o].ozn);
        }

    switch (input)
    {
        case KEY_UP:
            if (up != 35) {
                if (up == 88 && (oup == 32 || oup == 79)) {
                    obj[0].yPosition -= 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].yPosition == obj[o].yPosition)
                        && (obj[0].xPosition == obj[o].xPosition)) {
                            obj[o].yPosition -= 1;
                        }
                    }
                }
                else if (up != 88) obj[0].yPosition -= 1;
            }
            break;

        case KEY_DOWN:
            if (dw != 35) {
                if (dw == 88 && (odw == 32 || odw == 79)) {
                    obj[0].yPosition += 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].yPosition == obj[o].yPosition)
                        && (obj[0].xPosition == obj[o].xPosition)) {
                            obj[o].yPosition += 1;
                        }
                    }
                }
                else if (dw != 88) obj[0].yPosition += 1;
            }
            break;

        case KEY_LEFT:
            if (lf != 35) {
                if (lf == 88 && (olf == 32 || olf == 79)) {
                    obj[0].xPosition -= 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].yPosition == obj[o].yPosition)
                        && (obj[0].xPosition == obj[o].xPosition)) {
                            obj[o].xPosition -= 1;
                        }
                    }
                }
                else if (lf != 88) obj[0].xPosition -= 1;
            }
            break;

        case KEY_RIGHT:
            if (rg != 35) {
                if (rg == 88 && (org == 32 || org == 79)) {
                    obj[0].xPosition += 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].yPosition == obj[o].yPosition)
                        && (obj[0].xPosition == obj[o].xPosition)) {
                            obj[o].xPosition += 1;
                        }
                    }
                }
                else if (rg != 88) obj[0].xPosition += 1;
            }
            break;

        case 'm':
        case 'M':
            restart = TRUE;
            if (lev < 2) lev += 1;
            else lev = 0;
            Level(lev);
            break;

        case 'r':
        case 'R':
            restart = TRUE;
            Level(lev);
            break;
        default:
            break;
    }
    if (!restart) {
        for (int o = 0; o <= wbox; o++) {
            obj[o].ozn = mvinch(obj[o].yPosition, obj[o].xPosition);
            mvaddch(obj[o].yPosition, obj[o].xPosition, obj[o].zn |
            ((o == 0) ? COLOR_PAIR(3) : COLOR_PAIR(5)));
        }
        move(obj[0].yPosition, obj[0].xPosition);
    }
    else restart = FALSE;
}
