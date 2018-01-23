#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

private:
	std::string const 	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	const std::string & getName() const;
	int					getGrade() const;
	void				incGrade();
	void				decGrade();


	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException();
			GradeTooHighException(GradeTooHighException const &);
			~GradeTooHighException() throw();
			GradeTooHighException &	operator=(GradeTooHighException const &);

			virtual const char* what() const throw();
	};

	class GradeTooLowException
	{
		public:
			GradeTooLowException();
			GradeTooLowException(GradeTooLowException const &);
			~GradeTooLowException() throw();
			GradeTooLowException & operator=(GradeTooLowException const &);
			virtual const char* what() const throw();
	};

};

std::ostream & operator<<(std::ostream & stream, Bureaucrat const & rhs);

#endif
