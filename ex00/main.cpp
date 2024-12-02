/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:08:00 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/02 16:11:22 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/// @brief example main for Bureaucrat class
/// first increments and prints the grade of a bureaucrat till it reaches the 
/// highest grade and throws an exception. then decrements it till exception.
/// then creates a bureaucrat with too high and too low grade to throw exceptions.
/// @note New in C++:
/// try-catch block for exception handling.
/// IF the code runs without throwing an exception, the try block completes normally.
/// IF an exception is thrown, the catch block prints the exception message.
int	main(void)
{
	std::cout << "==========Create with valid grade & test it==========" << std::endl;
	
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.plusGrade();
		std::cout << bob << std::endl;
		bob.plusGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat berta("Berta", 149);
		std::cout << berta << std::endl;
		berta.minusGrade();
		std::cout << berta << std::endl;
		berta.minusGrade();
	}	
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "==========Create with invalid grade==========" << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
