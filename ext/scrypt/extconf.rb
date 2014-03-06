require "mkmf"

# abort "missing openssl()" unless have_func "malloc"
# abort "missing Openssl::()"   unless have_func "free"

create_makefile "scrypt/scrypt"
