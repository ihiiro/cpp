/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_err.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:28:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/15 17:39:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/statvfs.h>

int return_err(int err_const, struct statvfs& fsstats);