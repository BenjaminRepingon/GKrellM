/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:29:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 21:03:43 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Memory.hpp"
# include <iostream>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"
# include <sys/types.h>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>


Memory::Memory() : ProgramComponent()
{
	return ;
}

Memory::Memory( Memory const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

Memory::~Memory()
{

}

Memory &				Memory::operator=( Memory const & lhs )
{
	this->_memoryInfo = lhs.getMemoryInfo();

	return (*this);
}

void			Memory::input( float delta )
{
	(void)delta;

}

void			Memory::update( float delta )
{

	vm_size_t					page_size;
	mach_port_t					mach_port;
	mach_msg_type_number_t		count;
	vm_statistics64_data_t		vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);

	if ( KERN_SUCCESS == host_page_size( mach_port, &page_size ) &&
		KERN_SUCCESS == host_statistics64( mach_port, HOST_VM_INFO, reinterpret_cast<host_info64_t>( &vm_stats ), &count ) )
	{
		long long free_memory = static_cast<int64_t>( vm_stats.free_count ) * static_cast<int64_t>( page_size );

		long long used_memory = ( static_cast<int64_t>( vm_stats.active_count ) + static_cast<int64_t>( vm_stats.inactive_count ) + static_cast<int64_t>( vm_stats.wire_count ) ) * static_cast<int64_t>( page_size );
		std::stringstream ss;
		ss <<  "Free memory: " << static_cast<float>((free_memory / 1024.0 / 1024.0)) << "Mo -------- " << " Used Memory: " << static_cast<float>((used_memory / 1024.0) / 1024.0) << "Mo";
		this->_memoryInfo = ss.str();
	}
	std::cout << this->_memoryInfo << std::endl;
	(void)delta;
}
void			Memory::ncursesRender( NcursesRenderEngine & renderEngine )
{
	// struct utsname info;
	// if(uname(&info) != -1)
	// 	this->_memoryInfo = info.nodename;

	// std::stringstream ss;
	// ss << this->_memoryInfo;

	// GeometricDrawer::drawRectangleBorder( Vector2f( 0, 0 ), 20, 5 );

	// mvprintw( 1, 6, "Memory:" );
	// mvprintw( 10, 6, ss.str().c_str() );
	(void)renderEngine;
}

std::string		Memory::getMemoryInfo( void ) const
{
	return ( this->_memoryInfo );
}
