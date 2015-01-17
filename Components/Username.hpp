/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Username.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:39:55 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 18:53:10 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAME_HPP
#define USERNAME_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class Username : public ProgramComponent
{
	public:
		Username();
		Username( Username const & cpy );
		~Username();

		Username &				operator=( Username const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			graphicRender( GraphicRenderEngine & renderEngine );

		std::string				getUsername( void ) const;

	private:
		std::string				_username;
};

#endif
