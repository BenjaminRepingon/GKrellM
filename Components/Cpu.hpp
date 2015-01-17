/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:56:50 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 19:57:59 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
#define CPU_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class Cpu : public ProgramComponent
{
	public:
		Cpu();
		Cpu( Cpu const & cpy );
		~Cpu();

		Cpu &				operator=( Cpu const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

		std::string				getCpuInfo( void ) const;

	private:
		std::string				_cpuInfo;
};

#endif
