/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        fixed_pool_old.h
 * @ingroup     memory
 *
 */
#ifndef TB_MEMORY_FIXED_POOL_OLD_H
#define TB_MEMORY_FIXED_POOL_OLD_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#define TB_FIXED_POOL_OLD_GROW_MICRO                (128)
#define TB_FIXED_POOL_OLD_GROW_SMALL                (1024)
#define TB_FIXED_POOL_OLD_GROW_LARGE                (4096)

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the fixed pool ref type
typedef struct{}*   tb_fixed_pool_old_ref_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init fixed pool
 *
 * @param grow      the grow, using the default grow if be zero
 * @param step      the step
 * @param align     the align
 *
 * @return          the pool 
 */
tb_fixed_pool_old_ref_t tb_fixed_pool_old_init(tb_size_t grow, tb_size_t step, tb_size_t align);

/*! exit fixed pool
 *
 * @param pool      the pool 
 */
tb_void_t           tb_fixed_pool_old_exit(tb_fixed_pool_old_ref_t pool);

/*! the fixed pool item count
 *
 * @param pool      the pool 
 *
 * @return          the item count
 */
tb_size_t           tb_fixed_pool_old_size(tb_fixed_pool_old_ref_t pool);

/*! clear fixed pool
 *
 * @param pool      the pool 
 */
tb_void_t           tb_fixed_pool_old_clear(tb_fixed_pool_old_ref_t pool);

/*! malloc fixed pool data
 *
 * @param pool      the pool 
 * 
 * @return          the data pointer
 */
tb_pointer_t        tb_fixed_pool_old_malloc(tb_fixed_pool_old_ref_t pool);

/*! malloc fixed pool data and clear it
 *
 * @param pool      the pool 
 *
 * @return          the data pointer
 */
tb_pointer_t        tb_fixed_pool_old_malloc0(tb_fixed_pool_old_ref_t pool);

/*! duplicate fixed pool data 
 *
 * @param pool      the pool 
 * @param data      the data pointer
 *
 * @return          the duplicated data pointer
 */
tb_pointer_t        tb_fixed_pool_old_memdup(tb_fixed_pool_old_ref_t pool, tb_cpointer_t data);

/*! free fixed pool data
 *
 * @param pool      the pool 
 * @param data      the pool item data
 *
 * @return          tb_true or tb_false
 */
tb_bool_t           tb_fixed_pool_old_free(tb_fixed_pool_old_ref_t pool, tb_pointer_t data);

/*! walk fixed pool item
 *
 * @code
    tb_bool_t tb_fixed_pool_old_item_func(tb_pointer_t item, tb_cpointer_t priv)
    {
       // ok or break
       return tb_true;
    }
 * @endcode
 *
 * @param pool      the pool 
 * @param func      the walk func
 * @param priv      the walk data
 *
 */
tb_void_t           tb_fixed_pool_old_walk(tb_fixed_pool_old_ref_t pool, tb_bool_t (*func)(tb_pointer_t item, tb_cpointer_t data), tb_cpointer_t priv);

#ifdef __tb_debug__
/*! dump fixed pool
 *
 * @param pool      the pool 
 */
tb_void_t           tb_fixed_pool_old_dump(tb_fixed_pool_old_ref_t pool);
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif
