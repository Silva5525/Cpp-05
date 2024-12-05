/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:45 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 14:11:04 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/// @brief Default constructor.
RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", 72, 45), tar("default") {}

/// @brief Constructor.
/// @param tar target to write to.
RobotomyRequestForm::RobotomyRequestForm(const std::string& tar)
		: AForm("RobotomyRequestForm", 72, 45), tar(tar) {}

/// @brief copy constructor.
/// @param src the source RobotomyRequestForm object to copy.
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
		: AForm(src), tar(src.tar) {}

/// @brief assignment operator.
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
		tar = src.tar;
	return (*this);
}

/// @brief Destructor.
RobotomyRequestForm::~RobotomyRequestForm() {}

/// @brief executes the RobotomyRequestForm.
/// @note New in C++;
/// @see std::srand seeds the random number generator. So the
/// same random number isn't generated every time rand is called.
/// @see std::rand generates a random number.
void RobotomyRequestForm::execute(Bureaucrat const& ex) const
{
	if (!getSigCheck())
		throw (FormNotSignedExecption());
	if (ex.getGrade() > getGradeEx())
		throw (GradeTooLowException());
	std::cout << ("BiBoBub, BrrRR-ROOOOOOOBOTOMY!REEEEEEQUEST!") << '\n';
	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << tar << " robotomized SUCCESSFULL." << '\n';
	else
		std::cout << tar << " THe robotomy FAILED" << '\n';
}
