/*
 * Copyright (C) 2020 Waldemar Kozaczuk
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */
#ifndef _VIRTIOFS_H_
#define _VIRTIOFS_H_

//#include <memory>

//#include <vfscore/debug.h> // THIS MIGHT BE WRING
#include <vfscore/mount.h>
#include <vfscore/vnode.h>

//#include "drivers/virtio-fs.hh"
#include <virtiofs/fuse_kernel.h>
//#include "virtiofs_dax.hh"

#define VIRTIOFS_DEBUG_ENABLED 1

#if defined(VIRTIOFS_DEBUG_ENABLED)
#define virtiofs_debug(...) kprintf("[virtiofs] " __VA_ARGS__)
#else
#define virtiofs_debug(...)
#endif

struct virtiofs_mount_data {
    //virtio::fs* drv;
    //std::shared_ptr<virtiofs::dax_manager_impl> dax_mgr;
};

struct virtiofs_inode {
    uint64_t nodeid;
    struct fuse_attr attr;
};

struct virtiofs_file_data {
    uint64_t file_handle;
};

void virtiofs_set_vnode(struct vnode* vnode, struct virtiofs_inode* inode);

extern struct vfsops virtiofs_vfsops;
extern struct vnops virtiofs_vnops;

#endif