/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:36:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 18:53:06 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP
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
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

		std::string				getHostname( void ) const;

	private:
		std::string				_hostname;
};

#endif
