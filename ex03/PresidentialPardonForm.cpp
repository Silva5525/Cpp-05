/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:45 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 14:11:04 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/// @brief Default constructor.
PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", 25, 5), tar("default") {}

/// @brief Constructor.
/// @param tar target file to write to.
PresidentialPardonForm::PresidentialPardonForm(const std::string& tar)
		: AForm("PresidentialPardonForm", 25, 5), tar(tar) {}

/// @brief copy constructor.
/// @param src the source PresidentialPardonForm object to copy.
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
		: AForm(src), tar(src.tar) {}

/// @brief assignment operator.
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
		tar = src.tar;
	return (*this);
}

/// @brief Destructor.
PresidentialPardonForm::~PresidentialPardonForm() {}

/// @brief executes the PresidentialPardonForm.
void PresidentialPardonForm::execute(Bureaucrat const& ex) const
{
	if (!getSigCheck())
		throw (FormNotSignedExecption());
	if (ex.getGrade() > getGradeEx())
		throw (GradeTooLowException());
	std::cout << "Informs that " << tar << " becomes pardoned by Zafod Beeblebrox." << '\n';
}
