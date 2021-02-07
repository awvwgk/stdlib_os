#if defined(_WIN32) || defined(_WIN64)
#  if defined(__CYGWIN__) || defined(__CYGWIN32__)
#    if defined(__MSYS__)
#      define OS_NAME "Msys"
#      define OS_ID OS_MSYS
#    else
#      define OS_NAME "Cygwin"
#      define OS_ID OS_CYGWIN
#    endif
#  else
#    if defined(__MINGW32__)
#      define OS_NAME "MinGW"
#      define OS_ID OS_MINGW
#    else
#      define OS_NAME "WINDOWS"
#      define OS_ID OS_WINDOWS
#    endif
#  endif
#elif defined(__linux__)
#  define OS_NAME "Linux"
#  define OS_ID OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#  define OS_NAME "Darwin"
#  define OS_ID OS_DARWIN
#elif defined(unix) || defined(__unix__) || defined(__unix)
#  define OS_NAME "Unix"
#  define OS_ID OS_UNIX
#else
#  define OS_NAME "Undefined"
#  define OS_ID OS_UNDEFINED
#endif

module stdlib_os_type
  implicit none

  enum, bind(c); enumerator :: &
    OS_UNDEFINED, &
    OS_UNIX, &
    OS_LINUX, &
    OS_DARWIN, &  ! Canonical name for MacOSX
    OS_CYGWIN, &
    OS_WINDOWS, &
    OS_MINGW, &
    OS_MSYS
  end enum

  public :: &
    OS_UNDEFINED, &
    OS_UNIX, &
    OS_LINUX, &
    OS_DARWIN, &  ! Canonical name for MacOSX
    OS_CYGWIN, &
    OS_WINDOWS, &
    OS_MINGW, &
    OS_MSYS

  character(len=*), parameter, public :: os_name = OS_NAME
  integer(kind(OS_UNDEFINED)), parameter, public :: os_id = OS_ID

end module stdlib_os_type
