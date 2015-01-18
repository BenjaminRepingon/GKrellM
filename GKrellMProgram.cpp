/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellMProgram.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:30:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 18:11:45 by rbenjami         ###   ########.fr       */
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
# include "Components/Cpu.hpp"

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

	ModuleObject *hostnameModule = new ModuleObject( "Hostname", Vector2f( 3, 2 ), Vector2f( 25, 7 ) );
	hostnameModule->addComponent( new Hostname() );

	ModuleObject *userNameModule = new ModuleObject( "Username", Vector2f( 32, 12 ), Vector2f( 25, 7 ) );
	userNameModule->addComponent( new Username() );

	ModuleObject *OSInfoModule = new ModuleObject( "OSInfo", Vector2f( 4, 16 ), Vector2f( 25, 7 ) );
	OSInfoModule->addComponent( new OSInfo() );

	ModuleObject *currentTimeModule = new ModuleObject( "CurrentTime", Vector2f( 57, 20 ), Vector2f( 25, 7 ) );
	currentTimeModule->addComponent( new CurrentTime() );

	ModuleObject *memoryModule = new ModuleObject( "Memory", Vector2f( 98, 18 ), Vector2f( 25, 7 ) );
	memoryModule->addComponent( new Memory() );

	ModuleObject *cpuModule = new ModuleObject( "CPU", Vector2f( 56, 5 ), Vector2f( 75, 7 ) );
	cpuModule->addComponent( new Cpu() );

	addObject( hostnameModule );
	addObject( userNameModule );
	addObject( OSInfoModule );
	addObject( currentTimeModule );
	addObject( memoryModule );
	addObject( cpuModule );

	// END INIT
	return ( true );
}
