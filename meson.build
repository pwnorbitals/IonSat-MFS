project('FSW', ['c', 'cpp'], default_options : ['cpp_std=gnu++17', 'c_std=gnu11'])
source_files = []
incdir = []
deps = []

if meson.is_cross_build()
    subdir('cross-compile')
endif

RFF = subproject('RFF')
deps += RFF.get_variable('rff_dep')

add_project_arguments('-DTHROW=', language: ['cpp']) # For SGP4 exception handling
SGP4 = subproject('SGP4')
deps += SGP4.get_variable('sgp4_dep')

#libcsp = subproject('libcsp')
#deps += libcsp.get_variable('libcsp_dep')

subdir('src')
# subdir('test')


