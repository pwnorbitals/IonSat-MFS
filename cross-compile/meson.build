
linker_script = meson.get_cross_property('linker_script', '')
linker_depend = meson.get_cross_property('linker_depend', [])
startup_code = meson.get_cross_property('startup_code', '')
cross_folder = meson.get_cross_property('cross_folder', '')
has_meson_build = meson.get_cross_property('has_meson_build', '')

cross_source_files = []
cross_deps = []
cross_includes = []


if cross_folder != ''
    
    add_global_link_arguments('-Lcross-compile/'+cross_folder+'/', language: ['c', 'cpp'])
    cross_includes += include_directories(cross_folder)   
    
    
    if linker_script != ''
        add_global_link_arguments('-T'+meson.source_root()+'/cross-compile/'+cross_folder+'/'+linker_script, language: ['c', 'cpp'])
        foreach ld : linker_depend
            add_global_link_arguments('-L'+meson.source_root()+'/cross-compile/'+cross_folder, language: ['c', 'cpp'])
        endforeach
    endif

    if startup_code != ''
        cross_source_files += files(cross_folder+'/'+startup_code)
    endif
    
    foreach ld : linker_depend
        linker_deps += meson.source_root()+'/cross-compile/'+cross_folder+'/'+ld
    endforeach
    
    if has_meson_build == true
        subdir(cross_folder)
    endif

endif
