/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Username.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:39:35 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 15:20:25 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Username.hpp"
# include <sys/types.h>
# include <pwd.h>
# include <unistd.h>
# include <sys/types.h>
# include "../Engine/ProgramObject.hpp"

Username::Username() : ProgramComponent()
{
	return ;
}

Username::Username( Username const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

Username::~Username()
{

}

Username &				Username::operator=( Username const & lhs )
{
	this->_username = lhs.getUsername();

	return (*this);
}

void			Username::input( float delta )
{
	(void)delta;

}

void			Username::update( float delta )
{
	uid_t				id = getuid();
	struct passwd		*pwd;


	pwd = getpwuid(id);
	this->_username = pwd->pw_name;
	(void)delta;
}

void			Username::ncursesRender( NcursesRenderEngine & renderEngine )
{
	(void)renderEngine;
	drawRectangleBorder();
	drawString( Vector2f( 5, 1 ), "Username:" );
	drawString( Vector2f( 6, 3 ), this->_username );
}

void			Username::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;

}

std::string		Username::getUsername( void ) const
{
	return ( this->_username );
}
