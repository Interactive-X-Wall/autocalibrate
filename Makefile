.PHONY: all build clean

all: build

build:
	mkdir -p dist
	x86_64-w64-mingw32-gcc autocalibrate.c -o dist/autocalibrate.exe -luser32 -static

clean:
	rm -rf dist
