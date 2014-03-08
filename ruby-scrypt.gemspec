# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)

Gem::Specification.new do |s|
  s.name        = "ruby-scrypt"
  s.version     = "1.0.0.pre"
  s.authors     = ["Vincent Renaudineau"]
  s.email       = ["vincent.renaudineau@wanadoo.fr"]
  s.summary     = %q{Litecoin Scrypt hashing function for Ruby.}
  s.description = %q{Litecoin Scrypt hashing function for Ruby. Only allow 80 or 160 bytes payload.}
  s.homepage    = "https://github.com/Timmy72/ruby-scrypt"
  s.license     = 'MIT'

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.extensions    = %w[ext/scrypt/extconf.rb]
  s.require_paths = ["lib"]
end