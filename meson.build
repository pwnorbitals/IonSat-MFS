project('FSW', ['c', 'cpp'], default_options : ['cpp_std=c++17', 'c_std=c11'])
source_files = []
incdir = []
deps = []

RFF = subproject('IonSat-RFF')
deps += RFF.get_variable('rff_dep')

cmake = import('cmake')
sub_proj = cmake.subproject('SGP4')
deps += sub_proj.dependency('sgp4')

libopencm3 = subproject('libopencm3')
deps += libopencm3.get_variable('libopencm3_dep')

subdir('src')



