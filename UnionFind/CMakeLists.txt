cmake_minimum_required(VERSION 3.9.0)
project(UnionFind)

set(SOURCE ./tests.cpp ./QuickFind.cpp ./QuickUnion.cpp ./QuickUnionWPC.cpp)

add_executable(UnionFind ${SOURCE})
