#ifndef XW2000_ALL_DIRS_H
#define XW2000_ALL_DIRS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    XW_DIR_KIND_DRIVE_ROOT  = 0,
    XW_DIR_KIND_SYSTEM      = 1,
    XW_DIR_KIND_USER_DATA   = 2,
    XW_DIR_KIND_CACHE       = 3,
    XW_DIR_KIND_MOUNT       = 4,
    XW_DIR_KIND_MOD_XDK     = 5,
    XW_DIR_KIND_NT_KERNEL   = 6,
    XW_DIR_KIND_HW_DEVICE   = 7
} XW_AllDirKind;

typedef enum {
    XW_DIR_PERM_SAFE_WRITE   = 0,
    XW_DIR_PERM_CACHE_ONLY   = 1,
    XW_DIR_PERM_PRIV_WARN    = 2,
    XW_DIR_PERM_READ_ONLY    = 3,
    XW_DIR_PERM_BRICK_DANGER = 4
} XW_AllDirPerm;

typedef struct {
    const char    *dir_path;
    const char    *nt_or_mount;
    XW_AllDirKind  kind;
    XW_AllDirPerm  perm;
    uint32_t       max_mb;
    int            requires_privilege;
    int            enforce_42_game_sub;
    const char    *summary;
} XW_AllDirEntry;

size_t              xw2000_all_dirs_count(void);
const XW_AllDirEntry *xw2000_all_dirs_at(size_t index);
const XW_AllDirEntry *xw2000_all_dirs_find(const char *path);
int                 xw2000_all_dirs_check_op(const char *path,
                                             int is_write_or_mkdir,
                                             uint32_t req_bytes,
                                             int has_privilege);
void                xw2000_all_dirs_print_all(void);

#ifdef __cplusplus
}
#endif

#endif
