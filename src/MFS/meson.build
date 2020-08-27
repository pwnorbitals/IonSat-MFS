thread_dep = dependency('threads')

source_files = []
source_files += 'mfs.cpp'
includes = []
includes += incdir

cross_source_files = []

if meson.is_cross_build()
    source_files += cross_source_files
    includes += cross_includes
    deps += cross_deps
endif
executable('MFS', source_files, include_directories : incdir,  dependencies : deps)
executable('print_test', [files('print_test.cpp'), cross_source_files], include_directories : incdir,  dependencies : deps)
