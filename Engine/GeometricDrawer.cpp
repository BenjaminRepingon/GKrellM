# include "GeometricDrawer.hpp"

void				GeometricDrawer::drawRectangleBorder( Vector2f const & pos, int width, int height )
{
	for ( int i = pos.getX(); i < width + pos.getX(); ++i )
	{
		for ( int j = pos.getY(); j < height + pos.getY(); ++j )
		{
			if ( i == pos.getX() || j == pos.getY() || i == width + pos.getX() - 1 || j == height + pos.getY() - 1 )
				mvprintw( j, i, "+" );
		}
	}
}

void				GeometricDrawer::drawString( Vector2f const & pos, std::string const & str )
{
	mvprintw( pos.getY(), pos.getX(), str.c_str() );
}
