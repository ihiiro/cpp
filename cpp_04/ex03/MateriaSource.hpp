/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:38 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 23:33:35 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource& operator=(const MateriaSource &obj);
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};