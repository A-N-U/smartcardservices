/*
 *  PKCS#11 library for .Net smart cards
 *  Copyright (C) 2007-2009 Gemalto <support@gemalto.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef _include_digest_h
#define _include_digest_h

class CDigest
{
protected:
    CK_BYTE_PTR  _workingBuffer;
    CK_LONG      _workingOffset;
    CK_LONG      _workingLength;
    CK_LONG      _counter;
    CK_BYTE_PTR  _hashValue;
    CK_LONG      _hashLength;
    CK_LONG      _blockLength;

    virtual void TransformBlock(CK_BYTE_PTR data,CK_LONG counter,CK_BYTE_PTR result) = 0;
    virtual void TransformFinalBlock(CK_BYTE_PTR data,CK_LONG length,CK_LONG counter,CK_BYTE_PTR result) = 0;

public:
    CDigest();
    virtual ~CDigest();

    void HashCore(CK_BYTE_PTR data,CK_LONG offset,CK_LONG count);
    void HashFinal(CK_BYTE_PTR hash);
    CK_LONG HashLength(void);
};


#endif

