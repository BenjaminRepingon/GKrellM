#ifndef GEOMETRIC_DRAWER
# define GEOMETRIC_DRAWER
# include <ncurses.h>
# include "Vector2f.hpp"

class GeometricDrawer
{
public:
	static void				drawRectangleBorder( Vector2f const & pos, int width, int height );

private:
	GeometricDrawer();
	GeometricDrawer( GeometricDrawer const & cpy );
	~GeometricDrawer();

	GeometricDrawer &				operator=( GeometricDrawer const & lhs );
	std::string				_GeometricDrawer;
};

#endif
