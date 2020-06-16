incdir = [include_directories('src')]
source_files = []
header_files = []

subdir('src')
subdir('ext')

thread_dep = dependency('threads')
FFS = library('FFS', source_files, include_directories : incdir, dependencies : thread_dep)
