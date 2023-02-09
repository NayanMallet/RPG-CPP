cmake_minimum_required(VERSION 3.24)
project(RPG-POO)

set(CMAKE_CXX_STANDARD 11)

add_executable(RPG-POO main.cpp Armor.cpp Item.cpp Player.cpp Seller.cpp Talisman.cpp Weapon.cpp)
