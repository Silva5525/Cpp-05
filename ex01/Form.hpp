/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:17 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 12:08:50 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

#include "Bureaucrat.hpp"

/// @brief  Form class represents a form that can be signed by a Bureaucrat.
/// @param name The name of the form.
/// @param sigCheck A boolean that indicates if the form is signed.
/// @param gradeSig The grade required to sign the form.
/// @param gradeEx The grade required to execute the form.
class Form
{
	private:
		const		std::string name;
		bool		sigCheck;
		const int	gradeSig;
		const int	gradeEx;

	public:
		Form();
		Form(const std::string& name, int gradeSig, int gradeEx);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		const std::string& getName() const;
		bool getSigCheck() const;
		int getGradeSig() const;
		int getGradeEx() const;

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
