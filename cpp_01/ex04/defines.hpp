/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/14 04:55:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/* RANGE CONSTANTS */
# define 		MAXIMUM 						4
# define 		MINIMUM 						3

/* INDEXING CONSTANTS */
# define 		FIRST_ARG 						1
# define 		SECOND_ARG 						2
# define 		THIRD_ARG 						3

/* ERROR CONSTANTS */
# define 		INPUT_ERR_MAX_MIN 				0
# define 		NULL_ARGS 						1
# define 		ERR_RETURN_CONSTANT 			2
# define 		PRODUCT_FILENAME_TOO_LONG		3
# define 		FIRST_STRING_LARGER_THAN_FILE 	4
# define		FILE_DOES_NOT_EXIST				5

/* MACOS CONSTANTS */
# define 		MACOS_FILENAME_CHAR_MAX_LEN 	255
# define 		APFS_BLOCK_SIZE					4096 // from APFS manual