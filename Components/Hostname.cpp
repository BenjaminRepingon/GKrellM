/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:44:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 15:20:00 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Hostname.hpp"
# include <iostream>
# include <sys/utsname.h>
# include <sstream>
# include "../Engine/ProgramObject.hpp"

Hostname::Hostname() : ProgramComponent()
{
	return ;
}

Hostname::Hostname( Hostname const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

Hostname::~Hostname()
{

}

Hostname &				Hostname::operator=( Hostname const & lhs )
{
	this->_hostname = lhs.getHostname();

	return (*this);
}

void			Hostname::input( float delta )
{
	(void)delta;

}

void			Hostname::update( float delta )
{
	struct utsname	info;

	if ( uname( &info ) != -1 )
		this->_hostname = info.nodename;
	(void)delta;
}

void			Hostname::ncursesRender( NcursesRenderEngine & renderEngine )
{
	(void)renderEngine;
	drawRectangleBorder();
	drawString( Vector2f( 5, 1), "Hostname:" );
	drawString( Vector2f( 3, 3 ), this->_hostname );
}

std::string		Hostname::getHostname( void ) const
{
	return ( this->_hostname );
}
