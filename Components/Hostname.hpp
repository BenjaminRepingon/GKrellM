/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:36:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 18:29:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME
#define HOSTNAME
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class Hostname : public ProgramComponent
{
	public:
		Hostname();
		Hostname( Hostname const & cpy );
		~Hostname();

		Hostname &				operator=( Hostname const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			graphicRender( GraphicRenderEngine & renderEngine );

	private:
		std::string				_hostname;
};

#endif
