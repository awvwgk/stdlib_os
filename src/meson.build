os_name = configure_file(
  input: files('os.fh.in'),
  output: 'os.fh',
  configuration: configuration_data({
    'OS_SYSTEM_NAME': host_machine.system(),
  }),
)

os = host_machine.system()
srcs = files(
  'internal.c',
  'internal_c.f90',
  'internal.f90',
  'os.c',
  'os_c.f90',
  'os.f90',
  'os_path.c',
  'os_path_c.f90',
  'os_path.F90',
  'stdlib_test.f90',
)

test('os',
executable(
  meson.project_name(),
  sources: srcs,
  link_language: 'fortran',
)
)
