@echo off
rem Don Ceferino Hazana - ArcaOS SDL2 build script

set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0

make -f Makefile.os2 clean
make -f Makefile.os2 %1 %2 %3 2>&1 | tee compile.log
