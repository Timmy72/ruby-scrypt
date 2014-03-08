ruby-scrypt
===========

Litecoin Scrypt hashing function for Ruby.

Usage :

	require 'scrypt'

	# Litecoin block #526291
	block_header_hex = "02000000" + "b73417169f9055d2a9e143faa078e0cf97a13c40a5fc117a6b85a2240e5a7d1a" + "dc39618a259aa142f2c01e3640f19a68848a7494e75f22a4f068e24ae5a4d8b1" + "b1e51853" + "0eb6101b" + "003a269b"
	Scrypt.hash_hex( block_header_hex )
	# => "000000000003f406a8163444623935c2c4320a7d5508773b3c2de8fee4b14068"
    
	block_header_bin = [block_header_hex].pack("H*")
	Scrypt.hash_bin( block_header_bin )
	# => "\x00\x00\x00\x00\x00\x03\xF4\x06\xA8\x164Db95\xC2\xC42\n}U\bw;<-\xE8\xFE\xE4\xB1@h"
