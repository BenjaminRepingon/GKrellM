/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicRenderEngine.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:15:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GraphicRenderEngine.hpp"

GraphicRenderEngine::GraphicRenderEngine() :
	_isInit( false)
{
	return ;
}

GraphicRenderEngine::GraphicRenderEngine( GraphicRenderEngine const & src )
{
	*this = src;
	return ;
}

GraphicRenderEngine::~GraphicRenderEngine()
{
	return ;
}

GraphicRenderEngine &	GraphicRenderEngine::operator=( GraphicRenderEngine const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

void			GraphicRenderEngine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
	}

	/* Création de la fenêtre */
	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	if( pWindow )
	{
		SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

		SDL_DestroyWindow(pWindow);
	}
	else
	{
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}
	this->_isInit = true;
}

bool			GraphicRenderEngine::isInit()
{
	return ( this->_isInit );
}

int				GraphicRenderEngine::getWidth() const
{
	return ( this->_width );
}

int				GraphicRenderEngine::getHeight() const
{
	return ( this->_height );
}
