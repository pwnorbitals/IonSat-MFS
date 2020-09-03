source_files = files()

subdir('flightPlan')
subdir('housekeeping')
subdir('modes')
subdir('subsystems')
subdir('watchdog')


source_files += 'MFS.cpp'
includes = files()
includes += incdir

if meson.is_cross_build()
    source_files += cross_source_files
    includes += cross_includes
    deps += cross_deps
endif
executable('MFS', source_files, include_directories : incdir,  dependencies : deps)

