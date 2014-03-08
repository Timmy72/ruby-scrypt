// The MIT License (MIT)
//
// Copyright (c) 2014 Timmy72
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <ruby.h>
#include "percival_scrypt.h"

// The business logic -- this is the function we're exposing to Ruby. It returns
// a Ruby VALUE, and takes two VALUE arguments: the receiver object, and the
// method parameter. Notes on APIs used here:
// * rb_str_new(char * str, int len) creates a new Ruby string with the given length
// * StringValuePtr converts a Ruby String object to a C char *
static VALUE method_scrypt_hash_bin(VALUE mod, VALUE payload) {
  char output[32];
  Check_Type(payload, T_STRING);
  if (RSTRING_LEN(payload) != 80)
    rb_raise(rb_eArgError, "Invalid argument : wait a 80 length binary string. %ld", RSTRING_LEN(payload));

  scrypt_1024_1_1_256(StringValuePtr(payload), output);
  return rb_str_new(output, 32);
}

// Initial setup function, takes no arguments and returns nothing. Some API
// notes:
// * rb_define_module() creates and returns a top-level module by name
// * rb_define_singleton_method() take a module, the method name, a reference to
//   a C function, and the method's arity, and exposes the C function as a
//   single method on the given module
void Init_scrypt() {
  VALUE Scrypt = rb_define_module("Scrypt");
  rb_define_singleton_method(Scrypt, "hash_bin", method_scrypt_hash_bin, 1);
}
