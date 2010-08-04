#include <iostream>
#include "RayTracer.h"
#include "SDL/SDL.h"
 
const int WIDTH = 800;
const int HEIGHT = 600;
const int BITS_PER_PIXEL = 4;
const int BIT_DEPTH = 32;

RayTracer tracer = RayTracer();
Camera cam = Camera(30.0f, Vector3(WIDTH / 2 , HEIGHT / 2, 400), Vector3(0, 1, 0), Vector3(), WIDTH, HEIGHT, 45.0f);

void SetPixel(SDL_Surface* surface, int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    Uint32 *pixelMem32 = (Uint32*)surface->pixels + y + x;
    Uint32 color = SDL_MapRGB(surface->format, r, g, b);
	
    *pixelMem32 = color;
}
 
void Draw(SDL_Surface* surface, int h)
{
    int x,y, yTimesW;
	
    if(SDL_MUSTLOCK(surface))
    {
	    if(SDL_LockSurface(surface) < 0) return;
    }
	
    for(y = 0; y < surface->h; y++)
    {
	    yTimesW = y * surface->pitch / BITS_PER_PIXEL;
	    for(x = 0; x < surface->w; x++)
	    {
            Color result = tracer.Trace(cam, x, y);
            SetPixel(surface, x, yTimesW, result.r, result.g, result.b);
	    }
    }
    std::cout << "Finished rendering" << std::endl;

    if(SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);
	
    SDL_Flip(surface);
}
 
int main(int argc, char* argv[])
{
    SDL_Surface* surface;
    SDL_Event event;
	
    bool keyPressed = false;
    int h = 0;
	
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return 1;
	
    if(!(surface = SDL_SetVideoMode(WIDTH, HEIGHT, BIT_DEPTH, SDL_HWSURFACE)))
    {
	    SDL_Quit();
	    return 1;
    }

    bool renderingComplete = false;

    while(!keyPressed)
    {
        if (!renderingComplete)
        {
            Draw(surface, h++);
            renderingComplete = true;
        }
	    while(SDL_PollEvent(&event))
	    {
		    switch(event.type)
		    {
			    case SDL_QUIT:
				    keyPressed = 1;
				    break;
		    }
	    }
    }
	
    SDL_Quit();
	
    return 0;
}