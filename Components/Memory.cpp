/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:29:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 11:10:23 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Memory.hpp"
# include <iostream>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <sys/sysctl.h>
# include <sys/types.h>

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
	std::stringstream ss;
	vm_size_t					page_size;
	mach_port_t					mach_port;
	mach_msg_type_number_t		count;
	vm_statistics64_data_t		vm_stats;

	/*
	** TOTAL Memory
	*/
	long long unsigned int rm;
	int mib[]={CTL_HW,HW_MEMSIZE};
	size_t len;
	uint64_t m2;

	len = sizeof(m2);
	if(sysctl(mib, 2, &m2, &len, NULL,0) == 0)
		rm = m2;
	else
		rm = 0.0;

	ss << "Total memory: " << static_cast<float>( ( rm / 1024 ) / 1024 ) << "Mo   --------   ";

	/*
	** FREE & USED Memory
	*/

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);

	if ( KERN_SUCCESS == host_page_size( mach_port, &page_size ) &&
		KERN_SUCCESS == host_statistics64( mach_port, HOST_VM_INFO, reinterpret_cast<host_info64_t>( &vm_stats ), &count ) )
	{
		long long free_memory = static_cast<int64_t>( vm_stats.free_count ) * static_cast<int64_t>( page_size );

		long long used_memory = ( static_cast<int64_t>( vm_stats.active_count ) + static_cast<int64_t>( vm_stats.inactive_count ) + static_cast<int64_t>( vm_stats.wire_count ) ) * static_cast<int64_t>( page_size );
		ss <<  "Free memory: " << static_cast<float>((free_memory / 1024.0 / 1024.0)) << "Mo   --------   " << " Used Memory: " << static_cast<float>((used_memory / 1024.0) / 1024.0) << "Mo";
		this->_memoryInfo = ss.str();
	}

	// std::cout << this->_memoryInfo << std::endl;
	(void)delta;
}
void			Memory::ncursesRender( NcursesRenderEngine & renderEngine )
{
	std::stringstream ss;
	ss << this->_memoryInfo;

	// GeometricDrawer::drawRectangleBorder( Vector2f( 0, 0 ), 20, 5 );

	mvprintw( 1, 6, "Memory:" );
	mvprintw( 10, 6, ss.str().c_str() );
	(void)renderEngine;
}

std::string		Memory::getMemoryInfo( void ) const
{
	return ( this->_memoryInfo );
}
