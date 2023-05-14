cmake_minimum_required(VERSION 3.25)
project(SemestralWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(SemestralWork main.cpp Backend/CellData/CellDataType.h Backend/Parcing/StringParser.h Backend/Spreadsheet/Spreadsheet.h Backend/CellData/Cell.h UI/Button.h UI/Save.h UI/Clear.h "Backend/Formulas/Formula.h" Backend/Operators/Operator.h Backend/CellData/StoredData.h "Backend/File Manipulations/FileHandler.h" Backend/CellData/FormatType.h Backend/Formulas/Formula.h)
