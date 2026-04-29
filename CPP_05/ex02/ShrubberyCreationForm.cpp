#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), _target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	plantTrees(std::ofstream& file) {
	file << "	              \\_/\n";
	file << "                --(_)--\n";
	file << "            .'.   / \\\n";
	file << "           / . \\\n";
	file << "          |  |. | ,-'-.\n";
	file << "     ,-'-.\\ \\|  /(  .  )\n";
	file << "    /  .  \\  |, (  \\|   )\n";
	file << "   |  .|/  |_|_(    |/   )\n";
	file << "    \\._|,_/  |  '--.|..-'\n";
	file << " ______|_____|______|______\n";
}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (canExecute(executor))
	{
		std::ofstream	outfile(_target + "_shrubbery");
		plantTrees(outfile);
	}
}