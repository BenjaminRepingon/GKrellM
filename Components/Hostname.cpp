/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:44:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 17:50:23 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.hpp"
#include <iostream>

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

void			Hostname::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;

}
