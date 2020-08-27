
libopencm3 = meson.get_compiler('c').find_library('opencm3_stm32f4', dirs:[meson.source_root()+'/subprojects/libopencm3/lib'])
cross_deps += libopencm3

# that's messed up, but meson refuses to let me use meson.source_root() to build include dirs
cross_includes += include_directories('../../subprojects/libopencm3/include') 

add_global_arguments('-DSTM32F4', language : ['c', 'cpp'])

cross_source_files = files('syscalls.c', 'sysmem.c')
