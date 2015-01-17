/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:19:15 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 19:20:46 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
#define OSINFO_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class OSInfo : public ProgramComponent
{
	public:
		OSInfo();
		OSInfo( OSInfo const & cpy );
		~OSInfo();

		OSInfo &				operator=( OSInfo const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

		std::string				getOSInfo( void ) const;

	private:
		std::string				_OSInfo;
};

#endif
