/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:44:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 18:34:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Hostname.hpp"
# include <iostream>
# include <sys/utsname.h>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"

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
	(void)lhs;
	return (*this);
}

void			Hostname::input( float delta )
{
	(void)delta;

}

void			Hostname::update( float delta )
{
	(void)delta;
}
void			Hostname::ncursesRender( NcursesRenderEngine & renderEngine )
{
	struct utsname info;
	if(uname(&info) != -1)
		this->_hostname = info.nodename;

	std::stringstream ss;
	ss << this->_hostname;

	GeometricDrawer::drawRectangleBorder( Vector2f( 0, 0 ), 20, 5 );

	mvprintw( 1, 3, "Hostname:" );
	mvprintw( 3, 3, ss.str().c_str() );
	(void)renderEngine;
}
