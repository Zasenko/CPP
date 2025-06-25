/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:41:43 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/23 12:41:44 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Account.hpp"
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "amount:" << initial_deposit << ";"
                << "created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
     this->_nbDeposits++;
     _displayTimestamp();
     std::cout << "index:" << this->_accountIndex << ";"
               << "p_amount:" << this->_amount << ";"
               << "deposit:" << deposit << ";"
               << "amount:" << this->_amount + deposit << ";"
               << "nb_deposits:" << this->_nbDeposits
               << std::endl;
     this->_amount += deposit;
     _totalNbDeposits += 1;
     _totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";"
                << "withdrawal:";
    if (this->_amount - withdrawal < 0) {
        std::cout << "refused";
    }
    else {
        this->_nbWithdrawals++;
        std::cout << withdrawal << ";"
                  << "amount:" << this->_amount - withdrawal << ";"
                  << "nb_withdrawals:" << this->_nbWithdrawals;
        this->_amount -= withdrawal;
        _totalNbWithdrawals +=1;
        _totalAmount -= withdrawal;
    }
    std::cout << std::endl;
    return true;
}

int		Account::checkAmount(void) const {
    return this->_amount;
}

void	Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << checkAmount() << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

Account::Account(void) {
    this->_accountIndex = 0;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}

void	Account::_displayTimestamp(void) {
    std::time_t time = std::time(NULL);
    std::tm *now = std::localtime(&time);
    if (!now)
        return;
    std::cout   << std::setfill('0')
                << "["
                << 1900 + now->tm_year
                << std::setw(2) << now->tm_mon + 1
                << std::setw(2) << now->tm_mday
                << "_"
                << std::setw(2) << now->tm_hour
                << std::setw(2) << now->tm_min
                << std::setw(2) << now->tm_sec
                << "] ";
}