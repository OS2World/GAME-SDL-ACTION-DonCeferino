# Don Ceferino Hazaña

A fun game similar to the classic Super Pang. Don Ceferino is a gaucho from Argentina
who must rescue his cow from the aliens. Shoot the bubbles, survive the levels, beat
the high scores.

This repository contains the **ArcaOS / OS/2 port** (SDL2), version **0.97.8 Release 2**.
The original game was developed by Hugo Ruscitti and Walter Velazquez using SDL 1.x.

---

## License

GNU General Public License v2 — see `doc/COPYING`.

---

## Authors

**Original game**
- Hugo Ruscitti — programming and project management
- Walter Velazquez — graphics and story
- Javier Da Silva — music
- José Jorge Enríquez Rodríguez (Geo) — Windows version

**Translations (gettext)**
- English: Gabriel Valentin
- French: YBSAR
- Catalan: Raúl Cambeiro

**ArcaOS / OS/2 SDL2 port**
- Gianfilippo Cimmino
- Martin Iturbide

---

## How to Build (ArcaOS / OS/2)

Requirements:
- GCC 9.2 (InnoTek LIBC / EMX)
- SDL2, SDL2_image, SDL2_mixer (via ANPM or RPM)
- Open Watcom wlink (`wl.exe`) on PATH

```
compile.cmd
```

The script sets the required `EMXOMFLD_*` environment variables, performs a clean
build, and writes a full log to `compile.log`. The output binary is `ceferino.exe`.

---

## How to Play

| Key | Action |
|---|---|
| Arrow keys | Move |
| `X` | Fire hook |
| `Z` or `C` | Sweep attack (hold to repeat) |
| `W` / `A` / `S` / `D` | Alternative movement |
| `H` / `J` / `K` / `L` | Vi-style movement |
| `F` or `Alt+Enter` | Toggle fullscreen |
| `Ctrl+X` | Exit immediately |

The player can also be controlled with keys `1`, `2`, and `3`.
Menu navigation uses the same movement keys.

**Cheats** (press simultaneously during a game):

| Keys | Effect |
|---|---|
| `J` + `U` | Jump 1 level |
| `S` + `J` | Jump to level 26 |
| `B` + `O` | Bomb all enemies |

---

## Configuration and High Scores

The game stores its configuration file and high-score table under:

```
%XDG_CONFIG_HOME%\ceferino\    (if XDG_CONFIG_HOME is set)
%HOME%\.config\ceferino\       (default)
```

Files created:
- `ceferino.cfg` — display, audio, and fullscreen preferences
- `marcas.dat` — high-score table

---

## Links

- Original project: http://www.losersjuegos.com.ar/juegos/ceferino
- ArcaOS software repository: https://www.arcanoae.com/
- ArcaOS port: https://github.com/OS2World/GAME-SDL-ACTION-Don_Ceferino
