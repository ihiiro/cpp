/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:31 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 00:36:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource();
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};