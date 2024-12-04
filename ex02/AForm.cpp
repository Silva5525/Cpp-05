/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 20:00:30 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/// @brief Default constructor.
AForm::AForm() : name("AForm"), sigCheck(false), gradeSig(150), gradeEx(150) {}

/// @brief Constructor. Sets the name, gradeSig and gradeEx. throws exception if
/// gradeSig or gradeEx is too high or too low.
AForm::AForm(const std::string& name, int gradeSig, int gradeEx)
	: name(name), sigCheck(false), gradeSig(gradeSig), gradeEx(gradeEx)
{
	if (gradeSig < 1 || gradeEx < 1)
		throw GradeTooHighException();
	if (gradeSig > 150 || gradeEx > 150)
		throw GradeTooLowException();
}

/// @brief Copy constructor.
/// @param src The source AForm object to copy.
AForm::AForm(const AForm& src)
	: name(src.name), sigCheck(src.sigCheck), gradeSig(src.gradeSig), gradeEx(src.gradeEx) {}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
		sigCheck = src.sigCheck;
	return (*this);
}

/// @brief Destructor.
AForm::~AForm() {}

/// @brief Exception handling for grade too high.
const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("AForm Grade Too High.");
}

/// @brief Exception handling for grade too low.
const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("AForm Grade Too Low.");
}

/// @brief Exception handling for form not signed.
const char* AForm::FormNotSignedExecption::what() const noexcept
{
	return ("AForm not signed.");
}

/// @brief getter for name.
/// @return The name of the Aform.
const std::string& AForm::getName() const
{
	return (name);
}

/// @brief getter for sigCheck.
/// @return The boolean value of sigCheck.
bool AForm::getSigCheck() const
{
	return (sigCheck);
}

/// @brief getter for gradeSig.
/// @return The grade required to sign the Aform.
int AForm::getGradeSig() const
{
	return (gradeSig);
}

/// @brief getter for gradeEx.
/// @return the grade required to execute the Aform.
int AForm::getGradeEx() const
{
	return (gradeEx);
}

/// @brief Checks if the bureaucrat has the right grade to sign the Aform.
/// @param bureaucrat the bureaucrat that wants to sign the Aform.
/// @else throws an exception.
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeSig)
		sigCheck = true;
	else
		throw GradeTooLowException();
}

/// @brief Overloads the output stream operator to print the AForm object.
/// @param out holding the output.
/// @param Aform the AForm object to print.
/// @return the output stream.
std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
	out << "AForm: " << Aform.getName() << " \n"
		<< "Signed: " << (Aform.getSigCheck() ? "Yes" : "No" ) << " \n"
		<< "Grade to sign: " << Aform.getGradeSig() << " \n"
		<< "Grade to execute: " << Aform.getGradeEx() << " \n";
	return (out);
}
