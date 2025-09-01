#include <stdlib.h>
#include "type.h"

fat32_t* new_fat32() {
    return malloc(sizeof(fat32_t));
};

ext4_t* new_ext4() {
    return malloc(sizeof(ext4_t));
}

ntfs_t* new_ntfs() {
    return malloc(sizeof(ntfs_t));
}

fat32_t* copy_fat32(fat32_t* file) {
    fat32_t* new_file = malloc(sizeof(fat32_t));
    *new_file = *file;

    return new_file;
}

ext4_t* copy_ext4(ext4_t* file) {
    ext4_t* new_file = malloc(sizeof(ext4_t));
    *new_file = *file;

    return new_file;
}

ntfs_t* copy_ntfs(ntfs_t* file) {
    ntfs_t* new_file = malloc(sizeof(ntfs_t));
    *new_file = *file;

    return new_file;
}

void rm_fat32(fat32_t* file) {
    free(file);
}

void rm_ext4(ext4_t* file) {
    free(file);
}

void rm_ntfs(ntfs_t* file) {
    free(file);
}
