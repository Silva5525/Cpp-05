/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 12:21:26 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/// @brief Default constructor.
Form::Form() : name("Form"), sigCheck(false), gradeSig(150), gradeEx(150) {}

/// @brief Constructor. Sets the name, gradeSig and gradeEx. throws exception if
/// gradeSig or gradeEx is too high or too low.
Form::Form(const std::string& name, int gradeSig, int gradeEx)
	: name(name), sigCheck(false), gradeSig(gradeSig), gradeEx(gradeEx)
{
	if (gradeSig < 1 || gradeEx < 1)
		throw GradeTooHighException();
	if (gradeSig > 150 || gradeEx > 150)
		throw GradeTooLowException();
}

/// @brief Copy constructor.
/// @param src The source Form object to copy.
Form::Form(const Form& src)
	: name(src.name), sigCheck(src.sigCheck), gradeSig(src.gradeSig), gradeEx(src.gradeEx) {}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
	{
		this->sigCheck = src.sigCheck;
	}
	return (*this);
}

/// @brief Destructor.
Form::~Form() {}

/// @brief Exception handling for grade too high.
const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form Grade Too High.");
}

/// @brief Exception handling for grade too low.
const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form Grade Too Low.");
}

/// @brief getter for name.
/// @return The name of the form.
const std::string& Form::getName() const
{
	return (name);
}

/// @brief getter for sigCheck.
/// @return The boolean value of sigCheck.
bool Form::getSigCheck() const
{
	return (sigCheck);
}

/// @brief getter for gradeSig.
/// @return The grade required to sign the form.
int Form::getGradeSig() const
{
	return (gradeSig);
}

/// @brief getter for gradeEx.
/// @return the grade required to execute the form.
int Form::getGradeEx() const
{
	return (gradeEx);
}

/// @brief Checks if the bureaucrat has the right grade to sign the form.
/// @param bureaucrat the bureaucrat that wants to sign the form.
/// @else throws an exception.
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeSig)
		sigCheck = true;
	else
		throw GradeTooLowException();
}

/// @brief Overloads the output stream operator to print the Form object.
/// @param out holding the output.
/// @param form the Form object to print.
/// @return the output stream.
std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form: " << form.getName() << " \n"
		<< "Signed: " << (form.getSigCheck() ? "Yes" : "No" ) << " \n"
		<< "Grade to sign: " << form.getGradeSig() << " \n"
		<< "Grade to execute: " << form.getGradeEx() << " \n";
	return (out);
}
