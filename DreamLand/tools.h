#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <CSFML/Graphics.h>
#include <CSFML/Audio.h>

#define TEXTURE_PATH "..\\Data\\textures\\"
#define MAP_PATH "..\\Data\\maps\\"
#define MAP_WIDTH 80
#define MAP_HEIGHT 40
#define TILE_SIZE 32
#define WIDTH_WINDOW_GAME MAP_WIDTH * TILE_SIZE
#define HEIGHT_WINDOW_GAME MAP_HEIGHT * TILE_SIZE