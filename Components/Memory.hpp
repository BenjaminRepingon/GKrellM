/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:29:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 20:30:51 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class Memory : public ProgramComponent
{
	public:
		Memory();
		Memory( Memory const & cpy );
		~Memory();

		Memory &				operator=( Memory const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

		std::string				getMemoryInfo( void ) const;

	private:
		std::string				_memoryInfo;
};

#endif
