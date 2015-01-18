/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleObject.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:49:05 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 14:55:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "ModuleObject.hpp"

ModuleObject::ModuleObject( std::string const & title ) : ProgramObject( Vector2f( 0, 0 ) ),
	_title( title )
{
	return ;
}

ModuleObject::ModuleObject( std::string const & title, Vector2f const & pos, Vector2f const & widthHeight ) : ProgramObject(),
	_title( title )
{
	this->_pos = pos;
	this->_widthHeight = widthHeight;
	return ;
}

ModuleObject::ModuleObject( void ) : ProgramObject(), _title( "Module Object" )
{
	return ;
}

ModuleObject::ModuleObject( ModuleObject const & src ) : ProgramObject( src )
{
	*this = src;
	return ;
}

ModuleObject::~ModuleObject()
{
	return ;
}

ModuleObject &	ModuleObject::operator=( ModuleObject const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void	ModuleObject::update( float delta )
{
	ProgramObject::update( delta );
}

std::string const &		ModuleObject::getTitle( void ) const
{
	return ( this->_title );
}
