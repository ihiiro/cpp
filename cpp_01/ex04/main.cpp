/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/14 04:33:24 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "return_err.hpp"
#include <cstring>
#include <string>
#include "return_aggregate_str.hpp"

int main(int argc, char **argv)
{
	/* INPUT VALIDATION */
	if (argc > MAXIMUM || argc < MINIMUM)
		return (return_err(INPUT_ERR_MAX_MIN));
	if (	argv[FIRST_ARG] == NULL or 
			argv[SECOND_ARG] == NULL or
			(argv[THIRD_ARG] == NULL and argc == MAXIMUM)
		)
		return (return_err(NULL_ARGS));
	/* IMPORTANT CONSTANTS */
	const size_t 				filename_char_size(std::strlen(argv[FIRST_ARG]));
	// const size_t 				str_char_size(std::strlen(argv[SECOND_ARG]));
	// const size_t 				str_replacer_char_size(std::strlen(argv[THIRD_ARG]));
	const char suffix[] = 		".replace";
	/* VALIDATE CONSTANTS AND READ FILE/CONSTRUCT FULL-CONTENT STRING */
	if (filename_char_size + std::strlen(suffix) > MACOS_FILENAME_CHAR_MAX_LEN)
		return(return_err(PRODUCT_FILENAME_TOO_LONG));
	std::streamsize				file_char_size;
	std::string 				full_char_content_str(return_aggregate_str(argv[FIRST_ARG], &file_char_size));

}