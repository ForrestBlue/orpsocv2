# Copyright 2010 Thomas Conneely
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

from bitstring import *

mask = BitString('0xFF')

def intelhex_cksum(bits):
    '''Calculates the Intel Hex checksum of a BitString object'''
    # Sum each byte
    s = 0
    for b in bits.cut(8):
        s += b.uint
    # Calculate two's complement and return
    s = BitString(uintle=s, length=16)
    s = s[0:8] ^ mask
    return BitString(uintle=(s.uint + 1) & 255, length=8)


def bin2intelhex(binfile, hexfile, max_frames):
    # open binfile as a string of bits
    binary_data = BitString(filename=binfile)

    #open file to write intel hex formatted data
    hexf = open(hexfile, 'w')

    nbytes = 4
    nbyte_hex = BitString(uintle=nbytes, length=8)
    data_type = BitString(uintle=0, length=8)

    addr = 0
    for frame in binary_data.cut(32):
        frame.reverse()
        if addr == max_frames:
            break
        cksum = intelhex_cksum(
                nbyte_hex +
                BitString(uintle=addr, length=16) +
                data_type +
                frame)

        l = ':%0.2x%0.4x00%0.8x%0.2x' \
            % (nbytes, addr, frame.uint, cksum.uint)
        hexf.write(l.upper() + '\n')

        addr += 1
    hexf.write(':00000001FF')
    hexf.close()

if __name__ == '__main__':
    import sys

    bin2intelhex(sys.argv[1], sys.argv[2], int(sys.argv[3]))
