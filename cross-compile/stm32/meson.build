
cross_source_files = []
cross_deps = []
cross_includes = []

#libopencm3 = meson.get_compiler('c').find_library('opencm3_stm32f4', dirs:[meson.source_root()+'/subprojects/libopencm3/lib'])
#cross_deps += libopencm3
# that's messed up, but meson refuses to let me use meson.source_root() to build include dirs
#cross_includes += include_directories('../../subprojects/libopencm3/include') 

add_global_link_arguments(
    '-mcpu=cortex-m4', '-mno-thumb-interwork', '-mfpu=fpv4-sp-d16', '-mfloat-abi=hard',
    '-Lcross-compile/stm32/', '-T'+meson.current_source_dir()+'/stm32f429_2.ld', 
    language: ['c', 'cpp'])

libopencm3 = subproject('libopencm3')
cross_deps += libopencm3.get_variable('libopencm3_stm32f4_dep')


cross_source_files = files('syscalls.c', 'sysmem.c')
