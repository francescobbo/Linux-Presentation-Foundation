#include <System/Linux/Media/SolidColorBrush.h>

#include <cairomm/cairomm.h>
#include <cairomm/xlib_surface.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			SolidColorBrush::SolidColorBrush() : Brush()
			{
			}

			SolidColorBrush::SolidColorBrush(Color color) : Brush()
			{
				this->color = color;
			}
			
			SolidColorBrush::SolidColorBrush(const SolidColorBrush &copy)
			{
				this->color = color;
			}
			
			void SolidColorBrush::SetupContext(Cairo::RefPtr<Cairo::Context> cr, double w, double h)
			{
				cr->set_source_rgba(color.R / 255.0, color.G / 255.0, color.B / 255.0, color.A / 255.0);
			}
		}
	}
}
