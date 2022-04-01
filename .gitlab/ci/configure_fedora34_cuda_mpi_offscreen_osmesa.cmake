# Currently Fides does not support VTK-m+CUDA
# issue: https://gitlab.kitware.com/vtk/fides/-/issues/13
set(VTK_MODULE_ENABLE_VTK_fides NO CACHE STRING "")

# Lowest-common denominator. Pascal = 60
set(CMAKE_CUDA_ARCHITECTURES 60 CACHE STRING "")

include("${CMAKE_CURRENT_LIST_DIR}/configure_fedora34.cmake")
