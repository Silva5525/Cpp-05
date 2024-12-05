/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 13:51:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <fstream>

# include "AForm.hpp"

/// @brief PresidentialPardonForm class represents a form that can be signed & Executed
/// by a Bureaucrat.
class PresidentialPardonForm : public AForm
{
	private:
		std::string tar;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& tar);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		
		void execute(const Bureaucrat& executor) const;
		// void execute(const Bureaucrat& executor) const override;	
};

#endif
