#ifndef PROGRAM_COMPONENT
# define PROGRAM_COMPONENT
# include "NcursesRenderEngine.hpp"
# include "GraphicRenderEngine.hpp"

class ProgramObject;

class ProgramComponent
{
public:
	ProgramComponent( void );
	ProgramComponent( ProgramComponent const & src );
	virtual ~ProgramComponent( void );

	virtual void			input( float delta );
	virtual void			update( float delta );
	virtual void			ncursesRender( NcursesRenderEngine & renderEngine );
	virtual void			graphicRender( GraphicRenderEngine & renderEngine );
	virtual void			drawRectangleBorder();
	virtual void			drawString( Vector2f const & pos, std::string const & str );

	void					setParent( ProgramObject & parent );
	ProgramObject &			getParent() const;

	ProgramComponent &			operator=( ProgramComponent const & rhs );

private:
	ProgramObject *			_parent;
};

#endif
