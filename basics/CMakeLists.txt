# Get a list of all .cpp files in this directory
file(GLOB SOURCES "*.cpp")

# Loop through each .cpp file and create an executable with the same name
foreach(SOURCE_FILE ${SOURCES})
    # Extract the filename without the extension
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    # Create an executable with the extracted name
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()
