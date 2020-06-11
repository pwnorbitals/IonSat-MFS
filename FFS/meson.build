project('FFS', 'cpp')
source_files = []
header_files = []
subdir('src')
incdir = include_directories('src')
library('MFS', source_files, 
    include_directories : incdir,  
    default_options : ['cpp_std=c++17']
)