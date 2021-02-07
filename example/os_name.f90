program demo_os_name
  use, intrinsic :: iso_fortran_env, only : output_unit
  use stdlib_os, only : os_name
  implicit none

  write(output_unit, '(*(a, 1x))') &
    "Operating system is", os_name

end program demo_os_name
