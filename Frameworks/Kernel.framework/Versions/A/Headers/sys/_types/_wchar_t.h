/*
 * Copyright (c) 2012 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#define USE_CLANG_STDDEF 0

#if USE_CLANG_STDDEF

#ifndef __WCHAR_T
#define __WCHAR_T

#define __need_wchar_t
#include <stddef.h>
#undef __need_wchar_t

#endif /* __WCHAR_T */

#else

/* wchar_t is a built-in type in C++ */
#ifndef __cplusplus
#ifndef _WCHAR_T
#define _WCHAR_T
#include <machine/_types.h> /* __darwin_wchar_t */
typedef __darwin_wchar_t wchar_t;
#endif /* _WCHAR_T */
#endif /* __cplusplus */

#endif

#undef USE_CLANG_STDDEF
