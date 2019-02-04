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
#include "tiles.h"
static Tiles tiles;

constexpr auto LEVEL_WIDTH = 4200;
constexpr auto LEVEL_HEIGHT = (1080 / 3);// *2;

constexpr auto SCREEN_WIDTH = (1920 / 3);// *2; // accounting for scaling on personal device
constexpr auto SCREEN_HEIGHT = (1080 / 3);// *2;

constexpr auto TILE_WIDTH = 32;
constexpr auto TILE_HEIGHT = 32;

//tile types
constexpr auto topLeft = 1;
constexpr auto top = 2;
constexpr auto topRight = 3;
constexpr auto right = 4;
constexpr auto bottomRight = 5;
constexpr auto bottom = 6;
constexpr auto bottomLeft = 7;
constexpr auto left = 8;
constexpr auto center = 9;

constexpr auto Gravity = 2;