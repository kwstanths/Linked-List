# - Try to find myList
# Once done this will define
#  myList_FOUND - System has myList
#  myList_INCLUDE_DIRS - The myList include directories
#  myList_LIBRARIES - The libraries needed to use myList

find_path(myList_INCLUDE_DIR
	NAMES myList.hpp
	HINTS ${myList_ROOT}/include
	DOC "The myList include directory"
)

find_library(myList_LIBRARY
	NAMES myList
	HINTS ${myList_ROOT}/lib
	DOC "The myList library"
)

if(myList_INCLUDE_DIR AND myList_LIBRARY)
	set(myList_FOUND 1)
endif()

# Handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE if all myListed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(myList DEFAULT_MSG myList_INCLUDE_DIR myList_LIBRARY)

if(myList_FOUND)
	set(myList_LIBRARIES ${myList_LIBRARY} )
	set(myList_INCLUDE_DIRS ${myList_INCLUDE_DIR} )
endif()

# Tell cmake myLists to ignore the "local" variables
mark_as_advanced(myList_INCLUDE_DIR myList_LIBRARY)
