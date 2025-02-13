/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/13 16:53:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>

typedef struct
{
	int DATE;
	char *VALUE;
}		pair;

typedef std::ifstream::traits_type traits_type;

#ifndef BAD_YEAR
#define BAD_YEAR "year should be between 2009 and 2025 (no space prefix)"
#endif

#ifndef BAD_MONTH
#define BAD_MONTH "bad month"
#endif

#ifndef BAD_DAY
#define BAD_DAY "bad day (leap years are checked too)"
#endif

#ifndef BAD_VALUE
#define BAD_VALUE "bad value (NaN)"
#endif

#ifndef MISSING_DASH
#define MISSING_DASH "expected a dash: YYYY-MM-DD"
#endif

#ifndef MISSING_SPACE
#define MISSING_SPACE "expected a space: YYYY-MM-DD--> <--"
#endif

#ifndef MISSING_PIPE
#define MISSING_PIPE "expected a pipe character: YYYY-MM-DD |"
#endif


/* error printers */
void fatal_error(char const *str);
void usage_error(char const *str);
void stupidity_error(char const *str);

/* processors */
int process_year(std::ifstream& stream, int *feb_ptr);
int process_month(std::ifstream& stream);
int process_day(std::ifstream& stream, int month, int *months);
char *process_value(std::ifstream& stream);
pair process_line(std::ifstream& stream);