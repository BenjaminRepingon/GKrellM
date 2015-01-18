/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentTime.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:11 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 16:13:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURRENTTIME_HPP
#define CURRENTTIME_HPP
#include "../Engine/ProgramComponent.hpp"
#include <iostream>

class CurrentTime : public ProgramComponent
{
	public:
		CurrentTime();
		CurrentTime( CurrentTime const & cpy );
		~CurrentTime();

		CurrentTime &				operator=( CurrentTime const & lhs );

		virtual void			input( float delta );
		virtual void			update( float delta );
		virtual void			graphicRender( GraphicRenderEngine & renderEngine );
		virtual void			ncursesRender( NcursesRenderEngine & renderEngine );

		std::string				getDate( void ) const;

	private:
		std::string				_date;
};

#endif
