#include <stdio.h>
#include <mntent.h>
#include <sys/statvfs.h>
#include <stdlib.h>


int main()
{
    FILE* f;
    struct mntent* record;
    struct statvfs fsinfo;
    f = setmntent("/etc/mtab", "r");

    if(f == NULL)
    {
        printf("Error can't open /etc/mtab");
        exit(1);
    }

    while((record = getmntent(f)) != NULL)
    {
        if(statvfs(record->mnt_dir, &fsinfo) == -1)
        {
            printf("error");
            exit(1);
        }
        printf("Device: %s\n", record->mnt_fsname);
        printf("Mount point: %s\n", record->mnt_dir);
        printf("Total blocks: %ld\n", (unsigned long int)fsinfo.f_blocks);
        printf("Free blocks: %ld\n", (unsigned long int)fsinfo.f_bfree);
        printf("Block size: %ld\n", (unsigned long int)fsinfo.f_bsize);

    }


    endmntent(f);
    return 0;
}
