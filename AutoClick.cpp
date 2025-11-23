#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <iostream>
#include <unistd.h>

int ms;


int main()
{
	std::cout<<"\033[2J\033[H";
	Display* display = XOpenDisplay(NULL);
	std::cout<<"Digite quanto tempo de pausa do autoclick(em milisegundos): ";
	std::cin>>ms;
	int micro = ms * 1000;
	
	std::cout<<"AutoClicker rodando, use CTRL + C para parar\n";
	
	while (true)
	{
		XTestFakeButtonEvent(display, 1, true, 0);
	
		XTestFakeButtonEvent(display, 1, false, 0);
		XFlush(display);
			
		usleep(micro);
	}
	
	
	
	
	XCloseDisplay(display);
	
	return 0;

}
