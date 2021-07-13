cmake_minimum_required(VERSION 3.16.3)

project(soci_dev)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Find SOCI and PostgreSQL
find_package(Soci REQUIRED postgresql)
find_package(PostgreSQL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOCI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE PostgreSQL::PostgreSQL ${SOCI_LIBRARY})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SOCI_postgresql_PLUGIN})