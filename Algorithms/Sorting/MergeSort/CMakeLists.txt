cmake_minimum_required(VERSION 3.17)

project(002_MergeSort)

ADD_SUBDIRECTORY(MergeSort)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

# compile all the DIR_SRCS to main
ADD_EXECUTABLE(main ${DIR_SRCS})

# linked library InsertionSort with main
TARGET_LINK_LIBRARIES(main MergeSort)

