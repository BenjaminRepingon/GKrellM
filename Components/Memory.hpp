/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:29:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 16:20:52 by rbenjami         ###   ########.fr       */
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

	private:
		std::string				_memoryInfoTotal;
		std::string				_memoryInfoFree;
		std::string				_memoryInfoUsed;
};

#endif
