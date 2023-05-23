#ifndef SEMESTRALWORK_EXCEPTIONS_H
#define SEMESTRALWORK_EXCEPTIONS_H

#include <exception>

class CannotOpenTheFileException: public std::exception {};

class FileIsNotOpenedException: public std::exception {};

class CannotCreateTheFileException: public std::exception {};

class FileAlreadyOpenedException: public std::exception {};

class BadConfigFormatException: public std::exception {};

class IncorrectCalculationException: public std::exception {};
#endif //SEMESTRALWORK_EXCEPTIONS_H
