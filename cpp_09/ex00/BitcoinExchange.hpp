/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/12 02:30:10 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BAD_YEAR
#define BAD_YEAR "year should be between 2009 and 2025"
#endif

#ifndef BAD_MONTH
#define BAD_MONTH "bad month"
#endif

#ifndef BAD_DAY
#define BAD_DAY "bad day (leap years are checked too)"
#endif

/* error printers */
void fatal_error(char const *str);
void usage_error(char const *str);
void stupidity_error(char const *str);