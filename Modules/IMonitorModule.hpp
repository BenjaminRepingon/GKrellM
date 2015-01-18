/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:14:18 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/18 14:44:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE
#define IMONITORMODULE

class IMonitorModule
{
	public:
		virtual ~IMonitorModule( void ) {};
		virtual std::string const &		getTitle( void ) const = 0;

	private:

};

#endif
