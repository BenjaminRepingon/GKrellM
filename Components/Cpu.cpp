/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:56:40 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 21:09:38 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cpu.hpp"
# include <iostream>
# include <sys/utsname.h>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"

Cpu::Cpu() : ProgramComponent()
{
	return ;
}

Cpu::Cpu( Cpu const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

Cpu::~Cpu()
{

}

Cpu &				Cpu::operator=( Cpu const & lhs )
{
	this->_cpuInfo = lhs.getCpuInfo();

	return (*this);
}

void			Cpu::input( float delta )
{
	(void)delta;

}

void			Cpu::update( float delta )
{

	(void)delta;
}
void			Cpu::ncursesRender( NcursesRenderEngine & renderEngine )
{
	// struct utsname info;
	// if(uname(&info) != -1)
	// 	this->_cpuInfo = info.nodename;

	// std::stringstream ss;
	// ss << this->_cpuInfo;

	// GeometricDrawer::drawRectangleBorder( Vector2f( 0, 0 ), 20, 5 );

	// mvprintw( 1, 3, "Cpu:" );
	// mvprintw( 3, 3, ss.str().c_str() );
	(void)renderEngine;
}

std::string		Cpu::getCpu( void ) const
{
	return ( this->_cpuInfo );
}
