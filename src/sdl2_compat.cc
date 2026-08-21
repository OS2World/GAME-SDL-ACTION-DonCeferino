#include "sdl2_compat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

SDL_Window   *g_window = NULL;
SDL_Renderer *g_renderer = NULL;
SDL_Texture  *g_screen_texture = NULL;

void Ceferino_Flip(SDL_Surface *screen)
{
    SDL_UpdateTexture(g_screen_texture, NULL, screen->pixels, screen->pitch);
    SDL_RenderClear(g_renderer);
    SDL_RenderCopy(g_renderer, g_screen_texture, NULL, NULL);
    SDL_RenderPresent(g_renderer);
}

void Ceferino_ToggleFullscreen(void)
{
    Uint32 flags = SDL_GetWindowFlags(g_window);
    if (flags & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP))
        SDL_SetWindowFullscreen(g_window, 0);
    else
        SDL_SetWindowFullscreen(g_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

static void mkdirp(const char *path)
{
    char buf[512];
    char *p;
    strncpy(buf, path, sizeof(buf)-1);
    buf[sizeof(buf)-1] = '\0';
    for (p = buf+1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            char c = *p;
            *p = '\0';
            mkdir(buf, 0755);
            *p = c;
        }
    }
    mkdir(buf, 0755);
}

void ceferino_config_dir(char *buf, size_t len)
{
    const char *xdg = getenv("XDG_CONFIG_HOME");
    if (xdg && xdg[0])
        snprintf(buf, len, "%s/ceferino", xdg);
    else {
        const char *home = getenv("HOME");
        snprintf(buf, len, "%s/.config/ceferino", home ? home : ".");
    }
    mkdirp(buf);
}

void ceferino_config_path(char *buf, size_t len, const char *filename)
{
    char dir[490];
    ceferino_config_dir(dir, sizeof(dir));
    snprintf(buf, len, "%s/%s", dir, filename);
}
