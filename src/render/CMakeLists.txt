#######################
#### CONFIGURATION ####
#######################

#settings.h header file
#configure_file(
#"settings.h.in"
#"settings.h"
#)

########################
#### Subdirectories ####
########################

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/resources")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/structures")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/figures")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/renderer")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lights")

#################
#### SOURCES ####
#################

#Add the appropriate source directories
set(APPLICATION_SOURCE_DIRS
${APPLICATION_SOURCE_DIRS}
"${CMAKE_CURRENT_SOURCE_DIR}"
PARENT_SCOPE
)

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/rendercontext.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/bufferable.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/renderable.cpp"
PARENT_SCOPE
)
