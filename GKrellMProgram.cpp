/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellMProgram.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:30:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 15:47:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "GKrellMProgram.hpp"
# include "Modules/ModuleObject.hpp"
# include "Components/Hostname.hpp"
# include "Components/Username.hpp"
# include "Components/CurrentTime.hpp"
# include "Components/OSInfo.hpp"
# include "Components/Memory.hpp"

GKrellMProgram::GKrellMProgram() : Program()
{
	return ;
}

GKrellMProgram::GKrellMProgram( GKrellMProgram const & src ) : Program()
{
	*this = src;
	return ;
}

GKrellMProgram::~GKrellMProgram()
{
	return ;
}

GKrellMProgram &	GKrellMProgram::operator=( GKrellMProgram const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

bool			GKrellMProgram::init()
{
	// START INIT

	ModuleObject *hostnameModule = new ModuleObject( "Hostname", Vector2f( 0, 2 ), Vector2f( 20, 5 ) );
	hostnameModule->addComponent( new Hostname() );

	ModuleObject *userNameModule = new ModuleObject( "Username", Vector2f( 20, 2 ), Vector2f( 20, 5 ) );
	userNameModule->addComponent( new Username() );

	// ModuleObject *OSInfoModule = new ModuleObject( "OSInfo" );
	// OSInfoModule->addComponent( new OSInfo() );

	// ModuleObject *currentTimeModule = new ModuleObject( "CurrentTime" );
	// currentTimeModule->addComponent( new CurrentTime() );

	// ModuleObject *memoryModule = new ModuleObject( "Memory" );
	// memoryModule->addComponent( new Memory() );

	addObject( hostnameModule );
	addObject( userNameModule );
	// addObject( OSInfoModule );
	// addObject( currentTimeModule );
	// addObject( memoryModule );

	// END INIT
	return ( true );
}
