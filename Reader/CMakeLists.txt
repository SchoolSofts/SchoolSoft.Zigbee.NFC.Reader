cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(Reader)
include_directories(SDK/v2.5.99-dev1/nrfxlib/zboss/production/include)
# include_directories(SDK/v2.5.99-dev1)
target_sources(app PRIVATE src/main.c)
