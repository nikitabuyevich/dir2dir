add_executable(dir2dir src/main.cpp)

# Add precompiled headers
target_precompile_headers(dir2dir PRIVATE src/pch.h)

target_compile_features(dir2dir PRIVATE cxx_std_17)

target_link_libraries(dir2dir PRIVATE
        cmd::cmd
        cp::cp)


