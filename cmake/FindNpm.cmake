find_program(NPM_EXECUTABLE
    NAMES npm
    DOC "npm command line executable"
)
mark_as_advanced(NPM_EXECUTABLE)

if(NPM_EXECUTABLE)
    execute_process(
        COMMAND ${NPM_EXECUTABLE} --version
        OUTPUT_VARIABLE NPM_VERSION_STRING
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Npm
    REQUIRED_VARS NPM_EXECUTABLE
    VERSION_VAR NPM_VERSION_STRING
)
