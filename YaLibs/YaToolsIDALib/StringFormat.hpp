//  Copyright (C) 2017 The YaCo Authors
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "BinHex.hpp"

namespace
{
    template<uint32_t flags = 0, typename T>
    void append_uint64(T& dst, uint64_t x)
    {
        char buf[sizeof x * 2];
        const auto str = to_hex<flags>(buf, x);
        dst.append(str.value, str.size);
    }

    // duplicate hex function behavior from python
    template<typename T, typename U>
    void to_py_hex(T& dst, U value)
    {
        dst = "0x";
        append_uint64<LowerCase | RemovePadding>(dst, value);
        dst += 'L';
    }
}