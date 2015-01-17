#ifndef PROGRAM_COMPONENT
# define PROGRAM_COMPONENT
# include "RenderEngine.hpp"

class ProgramObject;

class ProgramComponent
{
public:
	ProgramComponent( void );
	ProgramComponent( ProgramComponent const & src );
	virtual ~ProgramComponent( void );

	virtual void			input( float delta );
	virtual void			update( float delta );
	virtual void			render( RenderEngine & renderEngine );

	void					setParent( ProgramObject & parent );
	ProgramObject &			getParent() const;

	ProgramComponent &			operator=( ProgramComponent const & rhs );

private:
	ProgramObject *			_parent;
};

#endif
