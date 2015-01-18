/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:19:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 16:10:51 by rbenjami         ###   ########.fr       */
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
	}
	(void)delta;
}

void			OSInfo::ncursesRender( NcursesRenderEngine & renderEngine )
{
	drawRectangleBorder();
	drawString( Vector2f( 5, 1), "OSInfo:" );
	drawString( Vector2f( 3, 3 ), this->_OSInfo );
	(void)renderEngine;
}

std::string		OSInfo::getOSInfo( void ) const
{
	return ( this->_OSInfo );
}
