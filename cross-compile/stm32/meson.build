
cross_source_files = []
cross_deps = []
cross_includes = []

libopencm3 = meson.get_compiler('c').find_library('opencm3_stm32f4', dirs:[meson.source_root()+'/subprojects/libopencm3/lib'])
cross_deps += libopencm3

add_global_arguments ('-DSTM32F4', '-mcpu=cortex-m4',  '-mthumb', '-mno-thumb-interwork', '-mfpu=fpv4-sp-d16', '-mfloat-abi=hard', '-ffreestanding', '-nostartfiles', '-fno-exceptions', '--specs=nano.specs', '-fstack-usage', language: ['c', 'cpp'])
add_global_arguments('-fno-use-cxa-atexit', language: 'cpp')
add_global_link_arguments('-mcpu=cortex-m4', '-mno-thumb-interwork', '-mfpu=fpv4-sp-d16', '-mfloat-abi=hard', language: ['c', 'cpp'])
add_global_link_arguments('-Lcross-compile/stm32/', language: ['c', 'cpp'])
add_global_link_arguments('-T'+meson.source_root()+'/cross-compile/stm32/stm32f429_2.ld', language: ['c', 'cpp'])
    

# that's messed up, but meson refuses to let me use meson.source_root() to build include dirs
cross_includes += include_directories('../../subprojects/libopencm3/include') 

cross_source_files = files('syscalls.c', 'sysmem.c')
