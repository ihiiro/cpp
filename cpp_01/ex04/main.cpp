/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/03 01:05:01 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "return_err.hpp"
#include <cstring>
#include <string>
#include "return_aggregate_str.hpp"
#include "return_occurence_count.hpp"
#include <sys/statvfs.h>

int main(int argc, char **argv)
{
	/* FILESYSTEM STRUCT */
	struct statvfs fsstats;
	statvfs(".", &fsstats);
	/* INPUT VALIDATION */
	if (argc > MAXIMUM || argc < MINIMUM)
		return (return_err(INPUT_ERR_MAX_MIN, fsstats));
	if (
			argv[FIRST_ARG] == NULL or !argv[FIRST_ARG][0] or
			argv[SECOND_ARG] == NULL or !argv[SECOND_ARG][0] or
			(argc == MAXIMUM and (argv[THIRD_ARG] == NULL or !argv[THIRD_ARG][0]))
		)
		return (return_err(NULL_ARGS, fsstats));
	/* IMPORTANT CONSTANTS */
	const size_t 				filename_char_size(std::strlen(argv[FIRST_ARG]));
	const size_t 				str_char_size(std::strlen(argv[SECOND_ARG]));
	size_t 				str_replacer_char_size;
	if (argv[THIRD_ARG])
		str_replacer_char_size = std::strlen(argv[THIRD_ARG]);
	str_replacer_char_size = 0;
	const char suffix[] = 		".replace";
	const size_t				suffix_char_size(std::strlen(suffix));
	/* VALIDATE CONSTANTS AND READ FILE/CONSTRUCT FULL-CONTENT STRING */
	if (filename_char_size + suffix_char_size > fsstats.f_namemax)
		return(return_err(PRODUCT_FILENAME_TOO_LONG, fsstats));
	std::streamsize				file_char_size = 0;
	std::string 				*full_char_content_str(return_aggregate_str(argv[FIRST_ARG], &file_char_size, fsstats));
	if (full_char_content_str == NULL)
		return (return_err(FILE_DOES_NOT_EXIST, fsstats));
	if (str_char_size > (size_t)file_char_size)
		return (return_err(FIRST_STRING_LARGER_THAN_FILE, fsstats));
	size_t 						occurence_count = return_occurence_count(
		*full_char_content_str,
		argv[SECOND_ARG]
	);
	if (occurence_count == 0)
		return (delete full_char_content_str, return_err(NO_OCCURENCE_IN_FILE, fsstats));
	size_t 						storage_avail_in_bytes = fsstats.f_bfree * fsstats.f_frsize;
	if (file_char_size -
						(str_char_size * occurence_count) +
						(str_replacer_char_size * occurence_count) +
						filename_char_size + suffix_char_size >= storage_avail_in_bytes
	)
		return (return_err(PRODUCT_LARGER_THAN_AVAILABLE_STORAGE, fsstats));
	/* WRITE TO <FILENAME>.REPLACE WITH REPLACED SUBSTRINGS */
	std::string 				product_filename(argv[FIRST_ARG]);
	product_filename.append(suffix);
	std::ofstream 				ofstream(product_filename);
	if (!ofstream.is_open())
		return (delete full_char_content_str, ERR_RETURN_CONSTANT);
	size_t 						occurence_start_index = full_char_content_str->find(argv[SECOND_ARG], 0);
	for (std::streamsize i = 0; i < file_char_size; i++)
	{
		if (i != (std::streamsize)occurence_start_index)
			ofstream << (*full_char_content_str)[i];
		else
		{
			if (argv[THIRD_ARG])
				ofstream << argv[THIRD_ARG];
			i += str_char_size - 1;
			occurence_start_index = full_char_content_str->find(argv[SECOND_ARG], i + 1);
		}
	}
	delete full_char_content_str;
	return (SUCCESS_RETURN_CONSTANT);
}
