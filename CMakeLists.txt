cmake_minimum_required(VERSION 3.5)
project(algorithm_in_c++)

set(CMAKE_CXX_STANDARD 11)

#add_executable(algorithm_in_c++ src/dp/steel_cut.cpp)


file( GLOB APP_SOURCES src/*/*.cpp )
foreach( appsourcefile ${APP_SOURCES} )
	get_filename_component( file_name ${appsourcefile} NAME_WE)
	add_executable(algorithm_in_c++ ${appsourcefile} )
endforeach( appsourcefile ${APP_SOURCES} )
