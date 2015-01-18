/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:19:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 09:58:00 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "OSInfo.hpp"
# include <iostream>
# include <sys/utsname.h>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"

OSInfo::OSInfo() : ProgramComponent()
{
	return ;
}

OSInfo::OSInfo( OSInfo const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

OSInfo::~OSInfo()
{

}

OSInfo &				OSInfo::operator=( OSInfo const & lhs )
{
	this->_OSInfo = lhs.getOSInfo();

	return (*this);
}

void			OSInfo::input( float delta )
{
	(void)delta;

}

void			OSInfo::update( float delta )
{
	struct utsname info;
	if(uname(&info) != -1)
	{
		this->_OSInfo = info.sysname;
		this->_OSInfo += " - ";
		this->_OSInfo += info.release;
		this->_OSInfo += " - ";
		this->_OSInfo += info.version;
	}
	(void)delta;
}

void			OSInfo::ncursesRender( NcursesRenderEngine & renderEngine )
{
	std::stringstream ss;
	ss << this->_OSInfo;

	// GeometricDrawer::drawRectangleBorder( Vector2f( 0, 0 ), 20, 5 );

	mvprintw( 1, 4, "OSInfo:" );
	mvprintw( 8, 4, ss.str().c_str() );
	(void)renderEngine;
}

std::string		OSInfo::getOSInfo( void ) const
{
	return ( this->_OSInfo );
}
