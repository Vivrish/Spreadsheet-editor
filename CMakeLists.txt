cmake_minimum_required(VERSION 3.25)
project(SemestralWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(SemestralWork main.cpp Backend/CellDataType.h Backend/StringParser.h Backend/Spreadsheet.h Backend/Cell.h UI/Button.h UI/Save.h UI/Clear.h "Backend/Formulas/Formula.h" Backend/Operators/Operator.h Backend/StoredData.h "Backend/File Manipulations/FileHandler.h")
