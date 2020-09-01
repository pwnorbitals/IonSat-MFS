source_files = []
source_files += 'mfs.cpp'
includes = []
includes += incdir

if meson.is_cross_build()
    source_files += cross_source_files
    includes += cross_includes
    deps += cross_deps
endif

if meson.is_cross_build()
    executable('print_test', [files('print_test.cpp'), cross_source_files], include_directories : incdir,  dependencies : deps)
    executable('blink_test', [files('blink_test.cpp'), cross_source_files], include_directories : incdir,  dependencies : deps)
endif