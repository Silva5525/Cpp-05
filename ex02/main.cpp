/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:08:00 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 18:25:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/// @brief Creates a Bureaucrat and tests it on all forms.
/// @note New in C++; (ShrubberyCreationForm::execute)
/// @see std::ofstream opens or creates a file for writing.
/// @see std::ios::app appends to the end of the file.
/// @see .close() is not needed becouse ofstream is handling
/// it already, but it is good practice to close it to free
/// resources and show intent.
/// @note New in C++; (RobotomyRequestForm::execute)
/// @see std::srand seeds the random number generator. So the
/// same random number isn't generated every time rand() is called.
/// @see std::rand generates a random number.
int	main(void)
{
	Bureaucrat rats[] =
	{
		Bureaucrat("Rat150", 150),
		Bureaucrat("RatRockie75", 75),
		Bureaucrat("RatBoss5", 5),
		Bureaucrat("RatBoss1", 1),
	};
	const size_t ratsSize = sizeof(rats) / sizeof(rats[0]);
	
	AForm* papers[] =
	{
		new ShrubberyCreationForm("AChristmasForest"),
		new RobotomyRequestForm("CyberRat"),
		new PresidentialPardonForm("RatSorry"),
	};
	const size_t papersSize = sizeof(papers) / sizeof(papers[0]);
	
	for (size_t i = 0; i < ratsSize; i++)
	{
		for (size_t j = 0; j < papersSize; j++)
		{
			std::cout << "\n========== Testing Bureaucrat: " << rats[i].getName()
					<< " on Form: " << papers[j]->getName() << " ==========\n";
			try
			{
				std::cout << rats[i].getName() << "trys to sign" << papers[j]->getName() << '\n';
				papers[j]->beSigned(rats[i]);
			}
			catch (const std::exception& e)
			{
				std::cerr << rats[i].getName() << " could not sign " << papers[j]->getName() << ": "
					<< e.what() << '\n';
			}
			
			try
			{
				std::cout << rats[i].getName() << "trys to execute" << papers[j]->getName() << '\n';
				rats[i].executeAForm(*papers[j]);
			}
			catch(const std::exception& e)
			{
				std::cerr << rats[i].getName() << " could not execute " << papers[j]->getName() << ": "
					<< e.what() << '\n';
			}
		}
	}

	for (size_t i = 0; i < papersSize; i++)
	{
		delete papers[i];
	}
	
	return (0);
}
