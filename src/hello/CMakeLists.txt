set(TARGET hello)

#include_directories()
aux_source_directory(. SRCS_DIR)

add_executable(
    ${TARGET}
    ${SRCS_DIR}
)

# target_link_libraries(
#     ${TARGET}

# )
target_link_options(${TARGET} PRIVATE
                    ${libc++}
)

install(
    TARGETS ${TARGET}
    # ARCHIVE DESTINATION ${CMAKE_INSTALL_ARCDIR}
    # LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    # INCLUDES DESTINATION ${CMAKE_INSTALL_INCDIR}
)
