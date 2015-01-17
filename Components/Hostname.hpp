/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:36:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 17:02:23 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME
#define HOSTNAME
#include "../Engine/ProgramComponent.hpp"

class Hostname : public ProgramComponent
{
	public:
		Hostname();
		Hostname( Hostname const & cpy );
		~Hostname();

		Hostname &				operator=( Hostname const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			render( RenderEngine & renderEngine );

};

#endif
