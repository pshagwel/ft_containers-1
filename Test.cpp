/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 06:27:11 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/24 10:44:50 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

int ConstrCounter::g_constr = 0;
int ConstrCounter::g_destr = 0;

ConstrCounter::ConstrCounter(int val):
	val(val)
{
	g_constr++;
}

ConstrCounter::ConstrCounter(const ConstrCounter &o):
	val(o.val)
{
	g_constr++;
}

ConstrCounter::~ConstrCounter()
{
	g_destr++;
}

void ConstrCounter::resetCounters()
{
	g_constr = 0;
	g_destr = 0;
}

bool operator==(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val == rhs.val;
}

bool operator!=(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val != rhs.val;
}

bool operator<(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val < rhs.val;
}

bool operator<=(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val <= rhs.val;
}

bool operator>(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val > rhs.val;
}

bool operator>=(const ConstrCounter& lhs, const ConstrCounter& rhs)
{
	return lhs.val >= rhs.val;
}

void testOne(std::string name, void (&fn)())
{
	std::cout << "> " << name << std::endl;
	fn();
    assert(ConstrCounter::g_constr == ConstrCounter::g_destr);
	ConstrCounter::resetCounters();
}
