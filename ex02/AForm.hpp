/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:17 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 20:00:05 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

#include "Bureaucrat.hpp"

/// @brief Virtual AForm class represents a form that can be signed & Executed
/// by a Bureaucrat.
class AForm
{
	private:
		const		std::string name;
		bool		sigCheck;
		const int	gradeSig;
		const int	gradeEx;

	public:
		AForm();
		AForm(const std::string& name, int gradeSig, int gradeEx);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

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
		class FormNotSignedExecption : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		const std::string& getName() const;
		bool getSigCheck() const;
		int getGradeSig() const;
		int getGradeEx() const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& ex) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& Aform);

#endif
