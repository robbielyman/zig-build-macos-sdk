/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
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
/* machine independent WIMG bits */

#ifndef _VM_MEMORY_TYPES_H_
#define _VM_MEMORY_TYPES_H_

#include <machine/memory_types.h>

#define VM_MEM_GUARDED          0x1             /* (G) Guarded Storage */
#define VM_MEM_COHERENT         0x2             /* (M) Memory Coherency */
#define VM_MEM_NOT_CACHEABLE    0x4             /* (I) Cache Inhibit */
#define VM_MEM_WRITE_THROUGH    0x8             /* (W) Write-Through */

#define VM_WIMG_USE_DEFAULT     0x80
#define VM_WIMG_MASK            0xFF

#if HAS_MTE
/*
 * Specifies default cacheability.
 */
#define HAS_DEFAULT_CACHEABILITY(attr)                                  \
	                        (                                       \
	                        ((attr) == VM_WIMG_MTE) ||              \
	                        ((attr) == VM_WIMG_USE_DEFAULT) ||      \
	                        ((attr) == VM_WIMG_DEFAULT)             \
	                        )
#else /* !HAS_MTE */
#define HAS_DEFAULT_CACHEABILITY(attr)                                  \
	                        (                                       \
	                        ((attr) == VM_WIMG_USE_DEFAULT) ||      \
	                        ((attr) == VM_WIMG_DEFAULT)             \
	                        )
#endif /* HAS_MTE */

#endif /* _VM_MEMORY_TYPES_H_ */
