/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicRenderEngine.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:14:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_RENDER_ENGINE
# define GRAPHIC_RENDER_ENGINE
//# include <gtk/gtk.h>
# include "SDL.h"
# include <stdio.h>
# include "IMonitorDisplay.hpp"

class GraphicRenderEngine : public IMonitorDisplay
{
public:
	GraphicRenderEngine( void );
	GraphicRenderEngine( GraphicRenderEngine const & src );
	virtual ~GraphicRenderEngine( void );

	GraphicRenderEngine &	operator=( GraphicRenderEngine const & rhs );

	virtual int				getWidth() const;
	virtual int				getHeight() const;
	virtual void			init( void );
	bool 					isInit( void );

private:
	int						_width;
	int						_height;
	bool					_isInit;
};

#endif
