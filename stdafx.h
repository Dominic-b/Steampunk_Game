#pragma once
#include <SDL_image.h>
#include <SDL.h>
#undef main

#include <stdio.h>
#include <vector>

#include "object.h"
static Object object;
#include "event.h"
static Event event;
#include "move.h"
static Move move;
#include "draw.h"
static Draw draw;

constexpr auto LEVEL_WIDTH = 4200;
constexpr auto LEVEL_HEIGHT = (1080 / 3);// *2;

constexpr auto SCREEN_WIDTH = (1920 / 3);// *2; // accounting for scaling on personal device
constexpr auto SCREEN_HEIGHT = (1080 / 3);// *2;

constexpr auto Gravity = 2;