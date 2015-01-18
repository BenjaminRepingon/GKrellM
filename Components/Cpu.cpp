/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:56:40 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 17:25:25 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cpu.hpp"
# include <iostream>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"

# include <sys/sysctl.h>
# include <sys/types.h>
#include <unistd.h>

#include <mach/mach_host.h>

#include <sys/sysctl.h>
#include <sys/types.h>
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>

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

Cpu &				Cpu::operator=( Cpu const & )
{

	return (*this);
}

void			Cpu::input( float delta )
{
	(void)delta;

}

void			Cpu::update( float delta )
{
	std::stringstream		ss;
	uint64_t				freq = 0;
	size_t					size = sizeof(freq);
	char					model[100];
	size_t					modellen = sizeof(model);

	sysctlbyname("hw.cpufrequency_min", &freq, &size, NULL, 0);
	sysctlbyname("machdep.cpu.brand_string", &model, &modellen, NULL, 0);

	ss << "Cpu Model: " << model;
	this->_cpuModel = ss.str();

	ss.str("");
	ss << "Nb Core: " << sysconf(_SC_NPROCESSORS_CONF);
	this->_cpuCore = ss.str();


	ss.str("");
	ss << "Clock Speed: " << static_cast<float>(((freq / 1024.0) / 1024.0) / 1024.0) << "GHz";
	this->_cpuClock = ss.str();

	(void)delta;
}
void			Cpu::ncursesRender( NcursesRenderEngine & renderEngine )
{
	drawRectangleBorder();

	drawString( Vector2f(3, 1), "Cpu:" );
	drawString( Vector2f(3, 3), this->_cpuModel );
	drawString( Vector2f(3, 4), this->_cpuCore );
	drawString( Vector2f(3, 5), this->_cpuClock );

	(void)renderEngine;
}

