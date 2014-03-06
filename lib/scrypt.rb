require "scrypt/scrypt"

module Scrypt
  def self.hash_hex( input )
    raise ArgumentError, 'input must be a 160 byte hexa string.' if input.size != 160
    hash_bin( [input].pack("H*") ).reverse.unpack("H*")[0]
  end
end
