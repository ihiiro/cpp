/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_err.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:14:55 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/15 17:38:12 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include <sys/statvfs.h>

int return_err(int err_const, struct statvfs& fsstats)
{
	switch(err_const)
	{
		case INPUT_ERR_MAX_MIN:
			std::cout << "error: atleast 2 args, max is 3 {file, str, str_replacer}" << std::endl;
			break;
		case NULL_ARGS:
			std::cout << "error: null args or empty strings passed" << std::endl;
			break;
		case PRODUCT_FILENAME_TOO_LONG:
			std::cout << "error: filename <filename>.replace is longer than " << fsstats.f_namemax << std::endl;
			break;
		case FIRST_STRING_LARGER_THAN_FILE:
			std::cout << "error: string passed is larger than file (possible empty file)" << std::endl;
			break;
		case FILE_DOES_NOT_EXIST:
			std::cout << "error: file not found" << std::endl;
			break;
		case PRODUCT_LARGER_THAN_AVAILABLE_STORAGE:
			std::cout << "error: insufficient storage for <filename>.replace" << std::endl;
			break;
		case NO_OCCURENCE_IN_FILE:
			std::cout << "error: no occurence of string in file" << std::endl;
			break;
		default:
			std::cout << "unkown error" << std::endl;
	}
	return (ERR_RETURN_CONSTANT);
}