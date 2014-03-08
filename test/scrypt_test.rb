
require 'minitest/autorun'

require 'scrypt'

class ScryptTest < MiniTest::Unit::TestCase
  def test_1
    input_hex = "02000000b73417169f9055d2a9e143faa078e0cf97a13c40a5fc117a6b85a2240e5a7d1adc39618a259aa142f2c01e3640f19a68848a7494e75f22a4f068e24ae5a4d8b1b1e518530eb6101b003a269b"
    input_bin = [input_hex].pack("H*")
    output_hex = "000000000003f406a8163444623935c2c4320a7d5508773b3c2de8fee4b14068"
    output_bin = [output_hex].pack("H*")

    assert_equal output_bin, Scrypt.hash_bin(input_bin)
    assert_equal output_hex, Scrypt.hash_hex(input_hex)
    
    assert_raises ArgumentError do
      Scrypt.hash_bin("toto")
    end
    assert_raises ArgumentError do
      Scrypt.hash_hex("toto")
    end
  end
end
