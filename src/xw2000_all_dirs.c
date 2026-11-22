#include "xw2000_all_dirs.h"
#include <stdio.h>
#include <string.h>

static const XW_AllDirEntry g_all_dirs[] = {
    /* ==================== KERNEL & HARDWARE DIRECTORIES ==================== */
    { "\\??\\",                        "NT DosDevices Object Dir", XW_DIR_KIND_NT_KERNEL, XW_DIR_PERM_READ_ONLY,    0,     1, 0, "DosDevices symbolic link root (\\??\\C:, \\??\\D:)" },
    { "\\BaseNamedObjects\\",           "NT Kernel Object Dir",     XW_DIR_KIND_NT_KERNEL, XW_DIR_PERM_READ_ONLY,    0,     1, 0, "Kernel Mutex/Event/Semaphore object directory" },
    { "\\Device\\Harddisk0\\Partition0","NT Raw Disk Sectors",     XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_BRICK_DANGER,0,     1, 0, "HARDWARE_BRICK_ERROR: Raw disk/MBR access; instant brick risk" },
    { "\\Device\\Harddisk0\\Partition8","NT CerBIOS/LBA48 P8",     XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 8 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition9","NT CerBIOS/LBA48 P9",     XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 9 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition10","NT CerBIOS/LBA48 P10",   XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 10 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition11","NT CerBIOS/LBA48 P11",   XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 11 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition12","NT CerBIOS/LBA48 P12",   XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 12 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition13","NT CerBIOS/LBA48 P13",   XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 13 (2TB+ LBA48)" },
    { "\\Device\\Harddisk0\\Partition14","NT CerBIOS/LBA48 P14",   XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   65536, 1, 0, "Extended partition 14 (2TB+ LBA48)" },
    { "\\Device\\CdRom0",               "NT DVD-ROM Device",        XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_READ_ONLY,    4700,  0, 0, "Optical DVD-ROM drive" },
    { "\\Device\\MemoryUnit",           "NT MemoryUnit00..31",    XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_SAFE_WRITE,   8,     0, 0, "Memory unit device directory (8 MB)" },
    { "\\Device\\EEPROM",               "NT Motherboard EEPROM",    XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_BRICK_DANGER,1,     1, 0, "HARDWARE_BRICK_ERROR: 256-byte EEPROM chip" },
    { "\\Device\\SMC",                  "NT System Mgmt Ctrl",      XW_DIR_KIND_HW_DEVICE, XW_DIR_PERM_PRIV_WARN,   1,     1, 0, "System Management Controller (fan/LED/power)" },
    { "\\Device\\",                     "NT Device Namespace",      XW_DIR_KIND_NT_KERNEL, XW_DIR_PERM_READ_ONLY,    0,     1, 0, "Kernel device object directory" },

    /* ==================== [C:\] SYSTEM & DASHBOARD DIRECTORIES ==================== */
    { "C:\\Audio\\AmbientAudio",        "Partition2\\Audio\\AmbientAudio", XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "System ambient audio directory" },
    { "C:\\Audio\\MainAudio",           "Partition2\\Audio\\MainAudio",    XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "System main menu audio directory" },
    { "C:\\Audio",                      "Partition2\\Audio",               XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 128, 1, 0, "System audio root directory" },
    { "C:\\fonts",                      "Partition2\\fonts",               XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 128, 1, 0, "System & softmod fonts (Xbox, XboxBook, ernie, bert)" },
    { "C:\\xodash\\audio",              "Partition2\\xodash\\audio",       XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "Original MS dashboard audio folder" },
    { "C:\\xodash\\media",              "Partition2\\xodash\\media",       XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "Original MS dashboard media folder" },
    { "C:\\xodash",                     "Partition2\\xodash",              XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 256, 1, 0, "Original MS dashboard UI folder" },
    { "C:\\xboxdashdata.",                "Partition2\\xboxdashdata.<hex>",  XW_DIR_KIND_SYSTEM, XW_DIR_PERM_PRIV_WARN, 256, 1, 0, "Versioned MS dashboard data directory" },
    { "C:\\nkpatcher\\configs",         "Partition2\\nkpatcher\\configs",  XW_DIR_KIND_MOD_XDK,XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "NKPatcher softmod configs folder" },
    { "C:\\nkpatcher\\rescue",          "Partition2\\nkpatcher\\rescue",   XW_DIR_KIND_MOD_XDK,XW_DIR_PERM_PRIV_WARN, 64,  1, 0, "NKPatcher softmod rescue folder" },
    { "C:\\nkpatcher",                  "Partition2\\nkpatcher",           XW_DIR_KIND_MOD_XDK,XW_DIR_PERM_PRIV_WARN, 128, 1, 0, "Softmod kernel patches directory" },
    { "C:\\shadowc",                    "Partition2\\shadowc",             XW_DIR_KIND_MOD_XDK,XW_DIR_PERM_PRIV_WARN, 500, 1, 0, "Softmod protected virtual C: directory" },
    { "C:\\bios",                       "Partition2\\bios",                XW_DIR_KIND_MOD_XDK,XW_DIR_PERM_BRICK_DANGER,64,1, 0, "HARDWARE_BRICK_ERROR: BIOS/BFM image folder on C:" },
    { "C:\\",                           "Partition2",                      XW_DIR_KIND_DRIVE_ROOT,XW_DIR_PERM_PRIV_WARN,500,1, 0, "System and dashboard root partition" },

    /* ==================== [D:\] ACTIVE APP OR DVD-ROM ==================== */
    { "D:\\",                           "CdRom0 / Active XBE Dir",         XW_DIR_KIND_DRIVE_ROOT,XW_DIR_PERM_SAFE_WRITE,4096,0,0, "Active .xbe directory or DVD-ROM" },

    /* ==================== [E:\] STANDARD USER & DATA (~4.8 GB) ==================== */
    { "E:\\UDATA\\fffe0000",            "Partition1\\UDATA\\fffe0000",     XW_DIR_KIND_USER_DATA,XW_DIR_PERM_SAFE_WRITE,256,0,0, "System & dashboard settings TitleID folder" },
    { "E:\\UDATA",                      "Partition1\\UDATA",               XW_DIR_KIND_USER_DATA,XW_DIR_PERM_SAFE_WRITE,2048,0,0, "Save data root (<TitleID>\\<SaveID>)" },
    { "E:\\TDATA\\fffe0000\\music",     "Partition1\\TDATA\\fffe0000\\music",XW_DIR_KIND_USER_DATA,XW_DIR_PERM_SAFE_WRITE,1024,0,0,"System soundtrack albums & .wma tracks" },
    { "E:\\TDATA\\fffe0000",            "Partition1\\TDATA\\fffe0000",     XW_DIR_KIND_USER_DATA,XW_DIR_PERM_SAFE_WRITE,1024,0,0,"System music/soundtrack TitleID folder" },
    { "E:\\TDATA",                      "Partition1\\TDATA",               XW_DIR_KIND_USER_DATA,XW_DIR_PERM_SAFE_WRITE,2048,0,0,"DLC ($c), Title Updates ($u), extras ($s)" },
    { "E:\\CACHE",                      "Partition1\\CACHE",               XW_DIR_KIND_CACHE,    XW_DIR_PERM_CACHE_ONLY,1024,0,0,"System/application cache directory" },
    { "E:\\DEVKIT",                     "Partition1\\DEVKIT",              XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 2048,1,0,"XDK developer kit directory" },
    { "E:\\Dashboard",                  "Partition1\\Dashboard",           XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 1024,1,0,"Modded system main dashboard folder" },
    { "E:\\Apps",                       "Partition1\\Apps",                XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 2048,1,0,"Modded system applications folder" },
    { "E:\\Games",                      "Partition1\\Games",               XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 4096,1,1,"Modded system games folder (max 42-char game dir)" },
    { "E:\\Homebrew",                   "Partition1\\Homebrew",            XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 4096,1,0,"Modded system standalone homebrew folder" },
    { "E:\\BIOS",                       "Partition1\\BIOS",                XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_BRICK_DANGER,16,1,0,"HARDWARE_BRICK_ERROR: Modchip/TSOP BIOS flash folder" },
    { "E:\\Backups\\EEPROM",            "Partition1\\Backups\\EEPROM",     XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 64,  1,0,"EEPROM backup directory (eeprom.bin)" },
    { "E:\\Backups",                    "Partition1\\Backups",             XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 128, 1,0,"System & EEPROM backups directory" },
    { "E:\\",                           "Partition1",                      XW_DIR_KIND_DRIVE_ROOT,XW_DIR_PERM_PRIV_WARN,4900,1,0,"Standard user & data partition (~4.8 GB)" },

    /* ==================== [F:\] EXTENDED PARTITION 1 ==================== */
    { "F:\\Games",                      "Partition6\\Games",               XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 65536,1,1,"Extended partition 1 games (max 42-char game dir)" },
    { "F:\\Apps",                       "Partition6\\Apps",                XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 65536,1,0,"Extended partition 1 apps" },
    { "F:\\Homebrew",                   "Partition6\\Homebrew",            XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 65536,1,0,"Extended partition 1 homebrew" },
    { "F:\\",                           "Partition6",                      XW_DIR_KIND_DRIVE_ROOT,XW_DIR_PERM_PRIV_WARN,65536,1,0,"Extended partition 1 (upgraded HDD)" },

    /* ==================== [G:\] EXTENDED PARTITION 2 ==================== */
    { "G:\\Games",                      "Partition7\\Games",               XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 65536,1,1,"Extended partition 2 games (max 42-char game dir)" },
    { "G:\\Apps",                       "Partition7\\Apps",                XW_DIR_KIND_MOD_XDK,  XW_DIR_PERM_PRIV_WARN, 65536,1,0,"Extended partition 2 apps" },
    { "G:\\",                           "Partition7",                      XW_DIR_KIND_DRIVE_ROOT,XW_DIR_PERM_PRIV_WARN,65536,1,0,"Extended partition 2 (250GB+/2TB HDD)" },

    /* ==================== [T:\], [U:\], [X:\], [Y:\], [Z:\], [MU:\ / H:\ - O:\] ==================== */
    { "T:\\",                           "Mount -> E:\\TDATA\\<TitleID>",   XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,1024,0,0,"Active app TDATA mount" },
    { "U:\\",                           "Mount -> E:\\UDATA\\<TitleID>",   XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,512, 0,0,"Active app UDATA mount" },
    { "X:\\",                           "Partition3",                      XW_DIR_KIND_CACHE,    XW_DIR_PERM_CACHE_ONLY,750, 0,0,"System cache partition 1 (~750 MB - temporary)" },
    { "Y:\\",                           "Partition4",                      XW_DIR_KIND_CACHE,    XW_DIR_PERM_CACHE_ONLY,750, 0,0,"System cache partition 2 (~750 MB - temporary)" },
    { "Z:\\",                           "Partition5",                      XW_DIR_KIND_CACHE,    XW_DIR_PERM_CACHE_ONLY,750, 0,0,"System cache partition 3 (~750 MB - temporary)" },

    { "MU:\\",                          "MemoryUnit00..31",                XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit (8 MB)" },
    { "H:\\",                           "MemoryUnit00..07",                XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot H:\\ (8 MB)" },
    { "I:\\",                           "MemoryUnit08..15",                XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot I:\\ (8 MB)" },
    { "J:\\",                           "MemoryUnit16..23",                XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot J:\\ (8 MB)" },
    { "K:\\",                           "MemoryUnit24..31",                XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot K:\\ (8 MB)" },
    { "L:\\",                           "MemoryUnitSlotL",                 XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot L:\\ (8 MB)" },
    { "M:\\",                           "MemoryUnitSlotM",                 XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot M:\\ (8 MB)" },
    { "N:\\",                           "MemoryUnitSlotN",                 XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot N:\\ (8 MB)" },
    { "O:\\",                           "MemoryUnitSlotO",                 XW_DIR_KIND_MOUNT,    XW_DIR_PERM_SAFE_WRITE,8,   0,0,"Memory Unit slot O:\\ (8 MB)" }
};

static const char *perm_name(XW_AllDirPerm p) {
    switch (p) {
        case XW_DIR_PERM_SAFE_WRITE:   return "SAFE_WRITE";
        case XW_DIR_PERM_CACHE_ONLY:   return "CACHE_ONLY";
        case XW_DIR_PERM_PRIV_WARN:    return "PRIV_WARN";
        case XW_DIR_PERM_READ_ONLY:    return "READ_ONLY";
        case XW_DIR_PERM_BRICK_DANGER: return "HARDWARE_BRICK_ERROR";
        default:                       return "UNKNOWN";
    }
}

static int verify_42_game_sub(const char *path, const char *prefix) {
    const char *sub = path + strlen(prefix);
    while (*sub == '\\' || *sub == '/') {
        sub++;
    }
    if (*sub == '\0') {
        return 0;
    }
    size_t len = 0;
    while (sub[len] != '\0' && sub[len] != '\\' && sub[len] != '/') {
        len++;
    }
    if (len > 42) {
        fprintf(stderr, "[ERROR] Game directory exceeds 42 chars (%zu): %s\n", len, path);
        return -1;
    }
    return 0;
}

size_t xw2000_all_dirs_count(void) {
    return sizeof(g_all_dirs) / sizeof(g_all_dirs[0]);
}

const XW_AllDirEntry *xw2000_all_dirs_at(size_t index) {
    if (index >= xw2000_all_dirs_count()) {
        return NULL;
    }
    return &g_all_dirs[index];
}

const XW_AllDirEntry *xw2000_all_dirs_find(const char *path) {
    if (!path || path[0] == '\0') {
        return NULL;
    }
    const XW_AllDirEntry *best = NULL;
    size_t best_len = 0;
    size_t n = xw2000_all_dirs_count();

    for (size_t i = 0; i < n; i++) {
        size_t len = strlen(g_all_dirs[i].dir_path);
        if (strncmp(path, g_all_dirs[i].dir_path, len) == 0 && len > best_len) {
            best = &g_all_dirs[i];
            best_len = len;
        }
    }
    return best;
}

int xw2000_all_dirs_check_op(const char *path,
                             int is_write_or_mkdir,
                             uint32_t req_bytes,
                             int has_privilege) {
    const XW_AllDirEntry *e = xw2000_all_dirs_find(path);
    if (!e) {
        fprintf(stderr, "[ERROR] Directory not found in catalog: %s\n", path ? path : "(null)");
        return -1;
    }

    if (e->perm == XW_DIR_PERM_BRICK_DANGER && is_write_or_mkdir) {
        fprintf(stderr, "[HARDWARE_BRICK_ERROR] '%s' -> %s\n", path, e->summary);
        fprintf(stderr, "[BLOCKED] Write/mkdir denied on critical hardware/BIOS path.\n");
        return -2;
    }

    if (e->requires_privilege && is_write_or_mkdir) {
        fprintf(stderr, "[PRIV_WARN] '%s' -> This path may require jailbreak/root/admin privileges (%s)\n",
                path, e->summary);
        if (!has_privilege) {
            fprintf(stderr, "[BLOCKED] Missing jailbreak/root/admin privilege.\n");
            return -3;
        }
    }

    if (e->enforce_42_game_sub && verify_42_game_sub(path, e->dir_path) != 0) {
        return -4;
    }

    if (e->perm == XW_DIR_PERM_READ_ONLY && is_write_or_mkdir) {
        fprintf(stderr, "[BLOCKED] Directory is read-only or virtual kernel object: %s\n", path);
        return -5;
    }

    uint32_t req_mb = (req_bytes + (1024u * 1024u) - 1u) / (1024u * 1024u);
    if (req_mb == 0 && req_bytes > 0) {
        req_mb = 1;
    }
    if (e->max_mb > 0 && req_mb > e->max_mb) {
        fprintf(stderr, "[ERROR] Requested size (%u MB) exceeds limit (%u MB) for %s\n",
                req_mb, e->max_mb, path);
        return -6;
    }

    printf("[OK] Directory check passed (%s): %s\n", perm_name(e->perm), path);
    return 0;
}

void xw2000_all_dirs_print_all(void) {
    size_t n = xw2000_all_dirs_count();
    for (size_t i = 0; i < n; i++) {
        const XW_AllDirEntry *e = &g_all_dirs[i];
        printf("%-36s | %-22s | %5u MB | %s\n",
               e->dir_path, perm_name(e->perm), e->max_mb, e->summary);
    }
}
