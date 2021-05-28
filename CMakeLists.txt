cmake_minimum_required(VERSION 3.1)

project(Task_1_sem_4)

include_directories(${PROJECT_SOURCE_DIR})

set (Task_1_sem_4_SRC  main.cpp autotests.cpp CComplNumb.cpp CComplVect.cpp CComplVectVert.cpp
CComplVectHori.cpp CFactoryComplVectHori.cpp CFactoryComplVectVert.cpp)
set (Task_1_sem_4_HDR  autotests.h CComplNumb.h CComplVect.h CComplVectVert.h
CComplVectHori.h CFactoryComplVectHori.h CFactoryComplVectVert.h CFactoryComplVect.h)

add_executable (${PROJECT_NAME} ${Task_1_sem_4_SRC} ${Task_1_sem_4_HDR})