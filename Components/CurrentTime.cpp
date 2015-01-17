/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentTime.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 19:02:50 by dsousa           ###   ########.fr       */
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

	std::cout << this->_date << std::endl;

	(void)delta;
}

void			CurrentTime::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;

}

std::string		CurrentTime::getDate( void ) const
{
	return ( this->_date );
}
