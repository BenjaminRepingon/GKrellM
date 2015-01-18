/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentTime.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 16:14:44 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CurrentTime.hpp"
#include <iostream>
#include <ctime>

CurrentTime::CurrentTime() : ProgramComponent()
{
	return ;
}

CurrentTime::CurrentTime( CurrentTime const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

CurrentTime::~CurrentTime()
{

}

CurrentTime &				CurrentTime::operator=( CurrentTime const & lhs )
{
	this->_date = lhs.getDate();

	return (*this);
}

void			CurrentTime::input( float delta )
{
	(void)delta;

}

void			CurrentTime::update( float delta )
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	std::string str(buffer);

	this->_date = str;

	(void)delta;
}

void			CurrentTime::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;
}

void			CurrentTime::ncursesRender( NcursesRenderEngine & renderEngine )
{
	(void)renderEngine;
	drawRectangleBorder();
	drawString( Vector2f( 5, 1), "CurrentTime:" );
	drawString( Vector2f( 1, 3 ), this->_date );
}

std::string		CurrentTime::getDate( void ) const
{
	return ( this->_date );
}
