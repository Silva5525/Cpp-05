/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:13:41 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/04 20:21:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		AForm* makeForm(const std::string& aFormName, const std::string& tar) const;
};


#endif