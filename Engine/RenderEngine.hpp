/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:14:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_ENGINE
# define RENDER_ENGINE
# include <ncurses.h>
# define SET_COLOR(COLOR) (attron(COLOR_PAIR(COLOR)))
# define COLOR_GRAY (COLOR_WHITE + 1)
# define COLOR_HIGH_YELLOW (COLOR_WHITE + 2)
class RenderEngine
{
public:
	RenderEngine( void );
	RenderEngine( RenderEngine const & src );
	virtual ~RenderEngine( void );

	RenderEngine &	operator=( RenderEngine const & rhs );

	int				getWidth() const;
	int				getHeight() const;

	WINDOW &		getWindow() const;

private:
	WINDOW*			_window;
	int				_width;
	int				_height;
};

#endif
