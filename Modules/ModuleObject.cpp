/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleObject.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:49:05 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 17:34:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "ModuleObject.hpp"

ModuleObject::ModuleObject( std::string const & title ) : ProgramObject(), _title( title )
{
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
