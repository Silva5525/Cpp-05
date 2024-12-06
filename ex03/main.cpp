/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:08:00 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/05 13:21:16 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/// @brief Creates a Intern and he then creates all forms.. but one.
/// @note New in C++; (search in Intern::makeForm)
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
/// @see {nullptr} is a null pointer constant that can be used in place of `NULL`.
int main(void)
{
	Intern someRandomIntern;
	AForm* form[4] = {nullptr};

	try
	{
		form[0] = someRandomIntern.makeForm("shrubbery creation", "Garden");
		form[1] = someRandomIntern.makeForm("robotomy request", "Bender");
		form[2] = someRandomIntern.makeForm("presidential pardon", "Zaphod");

		for (int i = 0; i < 3; i++)
		{
			std::cout << "  - " << form[i]->getName() << " created!\n";
		}

		form[3] = someRandomIntern.makeForm("unknown form", "Nope");
		std::cout << "  - " << form[3]->getName() << "never created!\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < 4; i++)
	{
		if (form[i])
			delete form[i];
	}

	return (0);
}
