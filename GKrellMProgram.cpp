/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellMProgram.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:30:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 17:33:01 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "GKrellMProgram.hpp"
# include "Modules/ModuleObject.hpp"
# include "Components/Hostname.hpp"

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

	ModuleObject *hostnameModule = new ModuleObject( "Hostname" );
	hostnameModule->addComponent( new Hostname() );

	addObject( hostnameModule );

	// END INIT
	return ( true );
}
