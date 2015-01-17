#ifndef PROGRAM
# define PROGRAM
# include "ProgramObject.hpp"

class CoreEngine;

class Program
{
public:
	Program( void );
	Program( Program const & src );
	virtual ~Program( void );

	ProgramObject &	getRootObject();

	virtual void	input( float delta );
	virtual void	update( float delta );
	virtual void	render( RenderEngine & renderEngine );
	virtual void	addObject( ProgramObject & object );
	ProgramObject &	getRoot() const;
	void			setEngine( CoreEngine & engine );

	virtual bool	init( void ) = 0;

	Program &			operator=( Program const & rhs );

private:
	ProgramObject *	_root;
};

#endif
