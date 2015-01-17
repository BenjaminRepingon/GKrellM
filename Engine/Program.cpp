# include "Program.hpp"
# include "CoreEngine.hpp"

Program::Program() :
	_root( 0 )
{
	return ;
}

Program::Program( Program const & src ) :
	_root( 0 )
{
	*this = src;
	return ;
}

Program::~Program()
{
	return ;
}

Program &	Program::operator=( Program const & rhs )
{
	if ( this != &rhs )
	{
		this->_root = &rhs.getRoot();
	}
	return ( *this );
}

ProgramObject &	Program::getRoot() const
{
	return ( *this->_root );
}

ProgramObject &	Program::getRootObject()
{
	if ( !this->_root )
		this->_root = new ProgramObject();
	return ( *this->_root );
}

void	Program::input( float delta )
{
	this->getRootObject().inputAll( delta );
}

void	Program::update( float delta )
{
	this->getRootObject().updateAll( delta );
}

void	Program::render( RenderEngine & renderEngine )
{
	this->getRootObject().renderAll( renderEngine );
}

void	Program::addObject( ProgramObject & object )
{
	this->getRootObject().addChild( object );
}

void	Program::setEngine( CoreEngine & engine )
{
	this->getRootObject().setCoreEngine( engine );
}
