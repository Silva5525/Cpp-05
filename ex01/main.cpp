/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:08:00 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 12:30:03 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/// @brief example main for Bureaucrat & Form class.
/// first creates a form with valid grade and tests it.
/// then creates a form with invalid grade to throw an exception.
/// @note New in C++:
/// @throw is a keywordused to indicate that a exception has occured it terminates the function
/// and returns the exception to the caller.
/// @package try-catch block for exception handling.
/// IF the code runs without throwing an exception, the try block completes normally.
/// IF an exception is thrown, the catch block prints the exception message.
/// @param std::exception& e The exception to catch.
/// @fn e.what() const noexcept override; Returns a C-style character string describing
/// the general cause of the current error.
int	main(void)
{
	std::cout << "==========Create Form with valid grade & test it==========" << std::endl;
	
	try
	{
		Bureaucrat may("MayNotSign", 42);
		Bureaucrat bob("Bob", 2);
		Form paper("Paper", 10, 2);
		
		std::cout << paper << '\n';
		
		std::cout << bob << '\n';
		bob.signForm(paper);
		std::cout << paper << '\n';
		
		std::cout << may << '\n';
		may.signForm(paper);
		std::cout << paper << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "==========Create Form with invalid grade==========" << std::endl;
	
	try
	{
		Form badPaper("BadPaper", 0, 15);
		std::cout << badPaper << "Will not be printet." << std::endl;
	}	
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
