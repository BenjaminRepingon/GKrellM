# include "ProgramComponent.hpp"

ProgramComponent::ProgramComponent()
{
	return ;
}

ProgramComponent::ProgramComponent( ProgramComponent const & src )
{
	*this = src;
	return ;
}

ProgramComponent::~ProgramComponent()
{
	return ;
}

ProgramComponent &	ProgramComponent::operator=( ProgramComponent const & rhs )
{
	if ( this != &rhs )
	{
		this->_parent = &rhs.getParent();
	}
	return ( *this );
}

void			ProgramComponent::input( float delta )
{
	(void)delta;
}

void			ProgramComponent::update( float delta )
{
	(void)delta;
}

void			ProgramComponent::ncursesRender( NcursesRenderEngine & renderEngine )
{
	(void)renderEngine;
}

//void			ProgramComponent::render( RenderEngine & renderEngine )
//{
//	(void)renderEngine;
//}

ProgramObject &	ProgramComponent::getParent() const
{
	return ( *this->_parent );
}

void			ProgramComponent::setParent( ProgramObject & parent )
{
	this->_parent = &parent;
}
