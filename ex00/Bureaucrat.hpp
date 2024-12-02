/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:07:13 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/02 15:55:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

/// @brief A Bureaucrat class
/// New in C++;
/// - Exception handling with custom exception classes.
/// - Operator overloading for output stream.
/// * The grade ranges from 1 (highest) to 150 (lowest).
class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();
	
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
		int getGrade() const;

		void plusGrade();
		void minusGrade();
	
		std::string showStr() const;
};

/// @brief Overloads the output stream operator to print the Bureaucrat object.
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif