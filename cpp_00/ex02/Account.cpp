/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:42:36 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/02 19:38:32 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

void Account::_displayTimestamp()
{
	std::time_t s_since_epoch = std::time(nullptr);
	std::tm* 	local_time_obj = std::localtime(&s_since_epoch);
	std::cout << "[" << std::put_time(local_time_obj, "%Y%m%d_%H%M%S") << "] ";
}

int remember_NbDeposits(int flag)
{
	static int d;

	if (flag)
		d += 1;
	return (d);
}

int remember_NbWithdrawals(int flag)
{
	static int w;

	if (flag)
		w += 1;
	return (w);
}

int Account::getNbDeposits()
{
	return (remember_NbDeposits(0));
}

int Account::getNbWithdrawals()
{
	return (remember_NbWithdrawals(0));
	
}

int remember_NbAccounts(int flag)
{
	static int a;

	if (flag)
		a += 1;
	return (a);
}

int Account::getNbAccounts()
{
	return (remember_NbAccounts(0) + 1);
}

int remember_total(int amount)
{
	static int total;

	total += amount;
	return (total);
}

int Account::getTotalAmount()
{
	return (remember_total(0));
}

void Account::makeDeposit(int deposit)
{
	(void)deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	return (withdrawal);
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() - 1 << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

int remember_index_constr()
{
	static int index = -1;

	index += 1;
	return (index);
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;

	_accountIndex = remember_index_constr();
	remember_NbAccounts(1);
	remember_total(_amount);
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account()
{
	
}