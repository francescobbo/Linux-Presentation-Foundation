#include <Engine/Xlib.h>
#include <pthread.h>

#include <System/Linux.h>

Xlib xlib(true);

int main(int argc, char *argv[])
{
	System::Linux::Window w;
	w.Show();

	return 0;
}

