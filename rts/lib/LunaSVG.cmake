# Keep LunaSVG and its active renderer on explicit, immutable submodule sources.
# CMake >= 3.27 is already required by the engine. Its supported find-package
# redirect lets upstream LunaSVG consume our PlutoVG without patching upstream.
include(FetchContent)
set(PLUTOVG_BUILD_EXAMPLES OFF)
FetchContent_Declare(plutovg
	SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/plutovg"
	OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(plutovg)
set(USE_SYSTEM_PLUTOVG ON)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lunasvg" "${CMAKE_CURRENT_BINARY_DIR}/lunasvg")
