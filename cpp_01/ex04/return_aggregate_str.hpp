/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_aggregate_str.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/14 04:50:17 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>

std::string* return_aggregate_str(char *filename, std::streamsize *gcount);