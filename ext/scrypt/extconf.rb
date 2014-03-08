require "mkmf"

abort "missing stdint.h header" unless have_header("stdint.h")

create_makefile "scrypt/scrypt"
