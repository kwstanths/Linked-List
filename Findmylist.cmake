# - Try to find mylist
# Once done this will define
#  mylist_FOUND - System has mylist
#  mylist_INCLUDE_DIRS - The mylist include directories
#  mylist_LIBRARIES - The libraries needed to use mylist

find_path(mylist_INCLUDE_DIR
	NAMES mylist.hpp
	HINTS ${mylist_ROOT}/include
	DOC "The mylist include directory"
)

find_library(mylist_LIBRARY
	NAMES mylist
	HINTS ${mylist_ROOT}/lib
	DOC "The mylist library"
)

if(mylist_INCLUDE_DIR AND mylist_LIBRARY)
	set(mylist_FOUND 1)
endif()

# Handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE if all mylisted variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mylist DEFAULT_MSG mylist_INCLUDE_DIR mylist_LIBRARY)

if(mylist_FOUND)
	set(mylist_LIBRARIES ${mylist_LIBRARY} )
	set(mylist_INCLUDE_DIRS ${mylist_INCLUDE_DIR} )
endif()

# Tell cmake mylists to ignore the "local" variables
mark_as_advanced(mylist_INCLUDE_DIR mylist_LIBRARY)
