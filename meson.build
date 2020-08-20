project('FSW', ['c', 'cpp'], default_options : ['cpp_std=c++17', 'c_std=c11'])
source_files = []
incdir = []
deps = []

RFF = subproject('IonSat-RFF')
deps += RFF.get_variable('rff_dep')

cmake = import('cmake')
sub_proj = cmake.subproject('SGP4')
deps += sub_proj.dependency('sgp4')

if meson.is_cross_build()
    add_global_arguments('-DSTM32F4', language : ['c', 'cpp'])
    cc = meson.get_compiler('c')
    libopencm3 = cc.find_library('opencm3_stm32f4', dirs:[meson.source_root()+'/subprojects/libopencm3/lib'])
    deps += libopencm3
endif

subdir('src')



