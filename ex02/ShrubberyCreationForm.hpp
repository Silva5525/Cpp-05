/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 18:08:28 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"

/// @brief ShrubberyCreationForm class represents a form that can be signed & Executed
/// by a Bureaucrat.
class ShrubberyCreationForm : public AForm
{
	private:
		std::string tar;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& tar);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		
		void execute(const Bureaucrat& executor) const;
		// void execute(const Bureaucrat& executor) const override;	
};

#endif
