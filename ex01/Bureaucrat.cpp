/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:08:50 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/02 21:52:26 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/// @brief Default constructor
Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

/// @brief Constructor with name and grade parameters
/// @param name of the bureaucrat
/// @param grade of the bureaucrat
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/// @brief Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade) {}

/// @brief Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->grade = src.grade;
	return (*this);
}

/// @brief Destructor
Bureaucrat::~Bureaucrat() {}

/// @brief Exception handling for grade too high
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade Too High Exception.");
}

/// @brief Exception handling for grade too low
const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade Too Low Exception");
}

/// @brief getter for name
const std::string& Bureaucrat::getName() const
{
	return (name);
}

/// @brief getter for grade
int Bureaucrat::getGrade() const
{
	return (grade);
}

/// @brief Increases the grade by 1 (example: from 3 to 2)
void Bureaucrat::plusGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

/// @brief Decreases the grade by 1 (example: from 3 to 4)
void Bureaucrat::minusGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

/// @brief Returns a string with the name and grade of the bureaucrat
/// in the correct format.
std::string Bureaucrat::showStr() const
{
	return (name + ", bureaucrat grade " + std::to_string(grade));
}

/// @brief Overloads the output stream operator to print the Bureaucrat object.
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << src.showStr();
	return (out);
}

/// @brief tries to sign a form. If the form is not signed, it throws an exception.
/// (throws exception if the grade of the bureaucrat is too low)
/// @param form the form to sign
void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << ".\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << name << " cannot sign " << form.getName() << " because: " << e.what() << "\n";
	}
}
