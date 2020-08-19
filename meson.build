project('FSW', ['c', 'cpp'], default_options : ['cpp_std=c++17', 'c_std=c11'])
source_files = []
incdir = []
deps = []
RFF = subproject('IonSat-RFF')
deps += RFF.get_variable('rff_dep')
subdir('src')



