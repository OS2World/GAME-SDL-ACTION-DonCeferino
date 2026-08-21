#ifndef SDL2_COMPAT_H
#define SDL2_COMPAT_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>

extern SDL_Window   *g_window;
extern SDL_Renderer *g_renderer;
extern SDL_Texture  *g_screen_texture;

void Ceferino_Flip(SDL_Surface *screen);
void Ceferino_ToggleFullscreen(void);

/* XDG-based config path helpers */
void ceferino_config_dir(char *buf, size_t len);
void ceferino_config_path(char *buf, size_t len, const char *filename);

/* Key helper: SDL2 keyboard state uses scancodes, not keycodes */
#define K(k) SDL_GetScancodeFromKey(k)

#endif
