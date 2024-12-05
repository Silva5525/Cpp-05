/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:45 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 20:08:10 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/// @brief Default constructor.
ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", 145, 137), tar("default") {}

/// @brief Constructor.
/// @param tar target file to write to.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tar)
		: AForm("ShrubberyCreationForm", 145, 137), tar(tar) {}

/// @brief copy constructor.
/// @param src the source ShrubberyCreationForm object to copy.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
		: AForm(src), tar(src.tar) {}

/// @brief assignment operator.
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
		tar = src.tar;
	return (*this);
}

/// @brief Destructor.
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/// @brief executes the ShrubberyCreationForm.
/// @note New in C++;
/// @see std::ofstream opens or creates a file for writing.
/// @see std::ios::app appends to the end of the file.
/// @see .close() is not needed becouse ofstream is handling
/// it already, but it is good practice to close it to free
/// resources and show intent.
/// @see R"()" is a raw string literal. It allows to write
/// multi-line strings without escaping characters.
void ShrubberyCreationForm::execute(Bureaucrat const& ex) const
{
	if (!getSigCheck())
		throw (FormNotSignedExecption());
	if (ex.getGrade() > getGradeEx())
		throw (GradeTooLowException());
	std::ofstream ofs(tar + "_shrubbery", std::ios::app);
	if (!ofs)
		throw (std::ios_base::failure("File could not be created."));
	ofs << R"(
                *
               /.\
              /o..\
              /..o\      *        *        *       !
  *         /.o..o\\    /.\\     /.\\     /o..\\   !
 /.\\       /...o.\\   /_\\_\\  /o..\\   /o....\\  !
/_\\_\\    /..o....\\    [_]   /_..o_\\ /o..o...\\ !
 [_]       ^^^[_]^^^           [_]       [_]       !
	)" << std::endl;
	ofs.close();
}
