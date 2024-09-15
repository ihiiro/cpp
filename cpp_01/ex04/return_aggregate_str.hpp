/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_aggregate_str.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/15 17:43:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <sys/statvfs.h>
#include "defines.hpp"

std::string* return_aggregate_str(char *filename, std::streamsize *gcount, struct statvfs& sysstats);