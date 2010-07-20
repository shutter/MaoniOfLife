# This module defines
# Maoni_FOUND        - true if libMaoni was found
# Maoni_INCLUDE_DIRS - where to find Maoni.hpp
# Maoni_LIBRARIES    - the libraries to link against to use libMaoni

find_path(Maoni_INCLUDE_DIRS Maoni.hpp
  /usr/include
  /usr/local/include
  /opt/local/include
  )

find_library(Maoni_LIBRARY Maoni)
find_library(Maoni_MAIN_LIBRARY MaoniMain)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Maoni
  DEFAULT_MSG Maoni_LIBRARY Maoni_MAIN_LIBRARY Maoni_INCLUDE_DIRS)

mark_as_advanced(Maoni_LIBRARY Maoni_MAIN_LIBRARY Maoni_INCLUDE_DIRS)

set(Maoni_LIBRARIES ${Maoni_LIBRARY} ${Maoni_MAIN_LIBRARY})
