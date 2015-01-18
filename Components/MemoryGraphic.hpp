/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemoryGraphic.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:31:49 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 17:35:32 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MEMORYGRAPHIC_HPP
#define MEMORYGRAPHIC_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class MemoryGraphic : public ProgramComponent
{
	public:
		MemoryGraphic();
		MemoryGraphic( MemoryGraphic const & cpy );
		~MemoryGraphic();

		MemoryGraphic &				operator=( MemoryGraphic const & );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

	private:
		int						_memory;
};

#endif
