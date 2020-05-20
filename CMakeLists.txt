cmake_minimum_required(VERSION 3.15)
project(OOP_Tema_3_2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_Tema_3_2_0 main.cpp headers/account.h sources/account.cpp headers/savings_account.h sources/savings_account.cpp headers/current_account.h sources/current_account.cpp headers/account_handler.h sources/account_handler.cpp headers/exceptions.h sources/exceptions.cpp headers/bank.h sources/bank.cpp)