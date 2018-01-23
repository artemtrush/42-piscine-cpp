#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

const std::string & Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

void				Bureaucrat::incGrade()
{
	if (_grade <= 1)
	{

		return;
	}
	_grade--;
}

void				Bureaucrat::decGrade()
{
	if (_grade >= 150)
	{

		return;
	}
	_grade++;
}

std::ostream & operator<<(std::ostream & stream, Bureaucrat const & rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return stream;
}



Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &) {}
virtual const char* Bureaucrat::GradeTooHighException::what() const throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &) {}
virtual const char* Bureaucrat::GradeTooLowException::what() const throw() {}
