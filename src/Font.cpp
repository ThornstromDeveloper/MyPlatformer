#include "Font.hpp"

#include "SDL.h"
#include <SDL_TTF.h>
#include <iostream>
#include <string>
#include "Window.hpp"

Font::Font(Window* window) :
    window(window)
{
    int fontsize = 40;
    int t_width = 0;
    int t_height = 0;
    SDL_Color text_color = { 0,0,0 };

    std::string fontpath = "resource/Roboto-Bold.ttf";
    std::string text = "TEST";

    TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);
    SDL_Texture* ftexture = NULL;

    if (font == NULL) {
        std::cout << "Failed the load the font!" << TTF_GetError();
    }

    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);

    if (text_surface == NULL) {
        std::cout << "Failed to render text surface!" << TTF_GetError();
    }

    ftexture = SDL_CreateTextureFromSurface(window->renderer, text_surface);

    if (ftexture == NULL) {
        std::cout << "Unable to create texture from rendered text!";
    }

    t_width = text_surface->w;
    t_height = text_surface->h;

    int x = 0;
    int y = 0;
    SDL_Rect dst = { x, y, t_width, t_height };
    SDL_RenderCopy(window->renderer, ftexture, NULL, &dst);
    SDL_FreeSurface(text_surface);
}