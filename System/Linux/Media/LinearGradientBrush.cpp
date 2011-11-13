#include <System/Linux/Media/LinearGradientBrush.h>

#include <cairomm/cairomm.h>
#include <cairomm/xlib_surface.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			LinearGradientBrush::LinearGradientBrush() : GradientBrush()
			{
			}

			LinearGradientBrush::LinearGradientBrush(const LinearGradientBrush &copy)
			{
				StartPoint = copy.StartPoint;
				EndPoint = copy.EndPoint;
			}
			
			LinearGradientBrush::LinearGradientBrush(Color c1, Color c2, Point p1, Point p2)
			{
				StartPoint = p1;
				EndPoint = p2;
				
				GradientStops.Add(GradientStop(c1, 0));
				GradientStops.Add(GradientStop(c2, 1));
			}
			
			void LinearGradientBrush::SetupContext(Cairo::RefPtr<Cairo::Context> cr, double w, double h)
			{
				Cairo::RefPtr<Cairo::LinearGradient> g = Cairo::LinearGradient::create(StartPoint.X * w, StartPoint.Y * w, EndPoint.X * h, EndPoint.Y * h);
				
				for (int i = 0; i < GradientStops.Count(); i++)
				{
					g->add_color_stop_rgba(GradientStops[i].Offset, GradientStops[i].color.R, GradientStops[i].color.G, GradientStops[i].color.B, GradientStops[i].color.A);
				}
				
				cr->set_source(g);
			}
		}
	}
}

