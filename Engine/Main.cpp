#include <Engine/Xlib.h>
#include <pthread.h>

#include <System/Linux.h>
#include <System/Linux/Media/LinearGradientBrush.h>
#include <System/Linux/Media/Colors.h>
#include <System/Linux/Point.h>

Xlib xlib(true);

int main(int argc, char *argv[])
{
	System::Linux::Window w;
	w.Background = new System::Linux::Media::LinearGradientBrush(System::Linux::Media::Colors::White, System::Linux::Media::Colors::Black, System::Linux::Point(0, 0), System::Linux::Point(0, 1));
	w.Show();

	return 0;
}
