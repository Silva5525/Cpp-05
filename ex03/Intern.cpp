/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:13:37 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/05 12:33:33 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/// @brief Default constructor.
Intern::Intern() {}

/// @brief Copy constructor.
Intern::Intern(const Intern& src)
{
	(void)src;
}

/// @brief Assignment operator.
Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

/// @brief Destructor.
Intern::~Intern() {}

/// @brief Exception handling for form not found.
const char* Intern::FormNotFoundException::what() const noexcept
{
	return ("Intern could not find the form.");
}

/// @brief Method to create a form.
/// @param formName name of the form.
/// @param tar target of the form.
/// @return Pointer to the created form. (we use new so we have to delete it later)
/// @throw FormNotFoundException if the form could not be found.
/// @note New in C++;
/// @see 1. **Lambda Functions:** (google Lambda C++11)
/// - A lambda function is an anonymous function (a function without a name) 
/// that can be defined inline. It allows us to create functions dynamically 
/// and concisely without the overhead of defining them separately.
/// - In this case, the lambdas are used to dynamically allocate and return 
/// the corresponding form objects.. in my case:
/// @fn	[](const std::string& tar) -> AForm* { return (new ShrubberyCreationForm(tar)); }
/// @see 2. **Type Aliases with `using`:**
/// - Instead of using verbose typedefs, the modern `using` keyword provides 
/// a cleaner syntax for type aliases.
/// - Here, we define a `using` alias `Forming` for a function pointer type 
/// that returns a pointer to an `AForm` object and takes a `const std::string&`
/// as an argument.. in my case:
/// @fn 	using Forming = AForm* (*)(const std::string&);
/// @see 3. **Structured Data with a Static Array:**
/// - A `static` array of structs is used to associate form names with their 
/// respective creation lambdas.
/// - This avoids the need for an "if-else forest" and provides a clean and 
/// extensible way to manage form types.. in my case:
/// @fn	static const struct {
/// 		std::string name;
/// 		Forming drawForm;
/// 	} forms[];
/// @see 4. **Range-Based Loops:** for (auto **:**)
/// - A range-based `for` loop is used to iterate over the `forms` array, making 
/// the code concise and expressive.. in my case:
/// @fn	for (const auto& form : forms)
AForm* Intern::makeForm(const std::string& formName, const std::string& tar) const
{
	using Forming = AForm* (*)(const std::string&);
	
	static const struct 
	{
		std::string name;
		Forming drawForm;
	}
	forms[] = 
	{
		{"shrubbery creation", [](const std::string& tar) -> AForm* { return (new ShrubberyCreationForm(tar)); }},
		{"robotomy request", [](const std::string& tar) -> AForm* { return (new RobotomyRequestForm(tar)); }},
		{"presidential pardon", [](const std::string& tar) -> AForm* { return (new PresidentialPardonForm(tar)); }}
	};
	
	for (const auto& form : forms)
	{
		if (form.name == formName)
		{
			std::cout << "Intern Prints " << formName << '\n';
			return (form.drawForm(tar));
		}
	}
	throw FormNotFoundException();
}
