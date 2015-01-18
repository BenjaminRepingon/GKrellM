/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemoryGraphic.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:29:54 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 18:23:52 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "MemoryGraphic.hpp"
# include <iostream>
# include <sstream>
# include "../Engine/GeometricDrawer.hpp"
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <sys/sysctl.h>
# include <sys/types.h>

MemoryGraphic::MemoryGraphic() : ProgramComponent()
{
	return ;
}

MemoryGraphic::MemoryGraphic( MemoryGraphic const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

MemoryGraphic::~MemoryGraphic()
{

}

MemoryGraphic &				MemoryGraphic::operator=( MemoryGraphic const & )
{
	return (*this);
}

void			MemoryGraphic::input( float delta )
{
	(void)delta;

}

void			MemoryGraphic::update( float delta )
{
	std::stringstream ss;
	vm_size_t					page_size;
	mach_port_t					mach_port;
	mach_msg_type_number_t		count;
	vm_statistics64_data_t		vm_stats;

	/*
	** TOTAL MemoryGraphic
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


	/*
	** FREE & USED MemoryGraphic
	*/

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);

	if ( KERN_SUCCESS == host_page_size( mach_port, &page_size ) &&
		KERN_SUCCESS == host_statistics64( mach_port, HOST_VM_INFO, reinterpret_cast<host_info64_t>( &vm_stats ), &count ) )
	{
		long long used_memory = ( static_cast<int64_t>( vm_stats.active_count ) + static_cast<int64_t>( vm_stats.inactive_count ) + static_cast<int64_t>( vm_stats.wire_count ) ) * static_cast<int64_t>( page_size );

		this->_memory = static_cast<int>(static_cast<float>( ( used_memory / 1024 ) / 1024 ) / static_cast<float>( ( rm / 1024 ) / 1024 ) * 100);
	}

	(void)delta;
}
void			MemoryGraphic::ncursesRender( NcursesRenderEngine & renderEngine )
{
	(void)renderEngine;
	drawString( Vector2f( 1, 1), "Analize With Polynomial Interpolation Of Random Access Memory: " );

	for (int i = 0; i < 100; ++i)
	{
		if ( i < this->_memory )
			drawString( Vector2f( i, 2 ), "#" );
		else
			drawString( Vector2f( i, 2 ), " " );

	}
}
