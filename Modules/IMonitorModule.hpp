/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:14:18 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 16:31:36 by dsousa           ###   ########.fr       */
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
