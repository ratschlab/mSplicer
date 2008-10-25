%warnfilter(509) CArray;
%{
 #include "lib/Array.h" 
%}

%include "lib/Array.h"

%template(CharArray) CArray<char>;
%template(ByteArray) CArray<uint8_t>;
%template(ShortArray) CArray<SHORT>;
%template(WordArray) CArray<uint16_t>;
%template(IntArray) CArray<INT>;
%template(UIntArray) CArray<uint32_t>;
%template(LongArray) CArray<LONG>;
%template(ULongArray) CArray<ULONG>;
%template(ShortRealArray) CArray<SHORTREAL>;
%template(RealArray) CArray<DREAL>;
