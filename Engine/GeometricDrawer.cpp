# include "GeometricDrawer.hpp"

void				GeometricDrawer::drawRectangleBorder( Vector2f const & pos, int width, int height )
{
	(void)pos;
	for ( int i = 0; i < width; ++i )
	{
		for ( int j = 0; j < height; ++j )
		{
			if ( i == 0 || j == 0 || i == width - 1 || j == height - 1 )
				mvprintw( j, i, "+" );
		}
	}
}