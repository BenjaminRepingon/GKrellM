/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRenderEngine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:14:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MONITOR_DISPLAY
# define I_MONITOR_DISPLAY

class IMonitorDisplay
{
public:

	virtual int				getWidth() const = 0;
	virtual int				getHeight() const = 0;

private:
//	IRenderEngine( void );
//	IRenderEngine( IRenderEngine const & src );
//	virtual ~IRenderEngine( void );
//
//	IRenderEngine &	operator=( IRenderEngine const & rhs );
};

#endif
