#ifndef GEOMETRIC_DRAWER
# define GEOMETRIC_DRAWER
# include <ncurses.h>
# include "Vector2f.hpp"

class GeometricDrawer
{
public:
	static void				drawRectangleBorder( Vector2f const & pos, int width, int height );
	static void				drawString( Vector2f const & pos, std::string const & str );

private:
	GeometricDrawer();
	GeometricDrawer( GeometricDrawer const & cpy );
	~GeometricDrawer();

	GeometricDrawer &				operator=( GeometricDrawer const & lhs );
	std::string				_GeometricDrawer;
};

#endif
