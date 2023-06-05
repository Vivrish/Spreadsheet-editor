#ifndef SEMESTRALWORK_EXCEPTIONS_H
#define SEMESTRALWORK_EXCEPTIONS_H

#include <exception>

class CannotOpenTheFileException: public std::exception {};

class FileIsNotOpenedException: public std::exception {};

class CannotCreateTheFileException: public std::exception {};

class FileAlreadyOpenedException: public std::exception {};

class BadConfigFormatException: public std::exception {};

class IncorrectCalculationException: public std::exception {};

class CellOutOfBoundsException: public std::exception {};

class IndexOutOfBoundsException: public std::exception {};

class IncorrectAmountOfArgumentsException: public std::exception {};

class InvalidOperationException: public std::exception {};

class LoopException: public std::exception {};

class MismatchedParenthesisException: public std::exception {};

class InvalidArgumentException: public std::exception {};

class FormatDoesNotExistException: public std::exception {};

class TypeDoesNotExistException: public std::exception {};

class InvalidDateException: public std::exception {};

class ReferenceMismatchException: public std::exception {};

class BadSyntaxException: public std::exception {};

class EvaluationOfEmptyCellException: public std::exception {};

class InvalidCommandException: public std::exception {};

#endif //SEMESTRALWORK_EXCEPTIONS_H
