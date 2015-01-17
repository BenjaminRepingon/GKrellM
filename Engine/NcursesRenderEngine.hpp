/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesRenderEngine.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:14:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_RENDER_ENGINE
# define NCURSES_RENDER_ENGINE
# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# define SET_COLOR(COLOR) (attron(COLOR_PAIR(COLOR)))
# define COLOR_GRAY (COLOR_WHITE + 1)
# define COLOR_HIGH_YELLOW (COLOR_WHITE + 2)

class NcursesRenderEngine : public IMonitorDisplay
{
public:
	NcursesRenderEngine( void );
	NcursesRenderEngine( NcursesRenderEngine const & src );
	virtual ~NcursesRenderEngine( void );

	NcursesRenderEngine &	operator=( NcursesRenderEngine const & rhs );

	virtual int				getWidth() const;
	virtual int				getHeight() const;

	WINDOW &				getWindow() const;

private:
	WINDOW*					_window;
	int						_width;
	int						_height;
};

#endif
