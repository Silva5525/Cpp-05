/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormhpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:57:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/03 13:51:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string tar;
		
	public:
		RobotomyRequestForm	();
		RobotomyRequestForm	(const std::string& tar);
		RobotomyRequestForm	(const RobotomyRequestForm	& src);
		RobotomyRequestForm	& operator=(const RobotomyRequestForm	& src);
		~RobotomyRequestForm	();
		
		void execute(const Bureaucrat& executor) const override;	
};

#endif