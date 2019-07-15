cmake_minimum_required(VERSION 3.14)
project(algorithm_class C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithm_class main.c "Assignments/Week 1/허정민/bubble.c")
add_executable(algorithm_class main.c "Assignments/Week 1/허정민/selection.c" "Assignments/Week 1/허정민/merge.c" "Assignments/Week 1/허정민/insertion.c" "Assignments/Week 1/허정민/quick.c")