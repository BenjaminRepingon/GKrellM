# include "ProgramComponent.hpp"
# include "../Engine/ProgramObject.hpp"

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

void			ProgramComponent::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;
}

ProgramObject &	ProgramComponent::getParent() const
{
	return ( *this->_parent );
}

void			ProgramComponent::setParent( ProgramObject & parent )
{
	this->_parent = &parent;
}

void			ProgramComponent::drawRectangleBorder()
{
	Vector2f	pos = this->getParent().getPos();
	int			width = this->getParent().getWidth();
	int			height = this->getParent().getHeight();
	for ( int i = pos.getX(); i < width + pos.getX(); ++i )
	{
		for ( int j = pos.getY(); j < height + pos.getY(); ++j )
		{
			if ( i == pos.getX() || j == pos.getY() || i == width + pos.getX() - 1 || j == height + pos.getY() - 1 )
				mvprintw( j, i, "+" );
		}
	}
}

void			ProgramComponent::drawString( Vector2f const & pos, std::string const & str )
{
	Vector2f parentPos = this->getParent().getPos();
	mvprintw( parentPos.getY() + pos.getY(), parentPos.getX() + pos.getX(), str.c_str() );
}
