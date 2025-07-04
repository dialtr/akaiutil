#ifndef AKAIUTIL_ALL_H
#define AKAIUTIL_ALL_H

/*
* Copyright (C) 2008-2022 Klaus Michael Indlekofer. All rights reserved.
*
* m.indlekofer@gmx.de
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifdef _MSC_VER
#include <windows.h>
#include <winioctl.h>
#else
#include <sys/types.h>
#endif

// =================================================================================================
//
// commoninclude.h
//
// =================================================================================================

#ifdef _VISUALCPP

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef unsigned char u_char;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef int ssize_t;
#ifndef SSIZE_MAX
#define SSIZE_MAX INT_MAX
#endif /* !SSIZE_MAX */

#define INT64 __int64
#define U_INT64 unsigned __int64
#define OFF_T __int64
#define OFF64_T __int64

#define OPEN _open
#define CLOSE _close
#define READ _read
#define WRITE _write
/* default lseek and off_t cannot handle offsets>=2GB! */
#define LSEEK _lseeki64
#define LSEEK64 _lseeki64

#define SNPRINTF(x,y,...)	_snprintf_s((x),(y),_TRUNCATE,__VA_ARGS__)

#else /* !_VISUALCPP */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define INT64 __int64_t
#define U_INT64 __uint64_t
#define OFF_T off_t
#define OFF64_T int64_t

#ifndef NOT_MYLSEEK64
/* own 64bit version of lseek */
#define LSEEK64	mylseek64
#endif

#define SNPRINTF(x,y,...)	snprintf((x),(y),__VA_ARGS__)

#endif /* !_VISUALCPP */

#include <math.h>

/* O_BINARY important for Windows-based systems (esp. cygwin or VC++) */
#ifndef O_BINARY
#define O_BINARY 0
#endif /* !O_BINARY */

// =================================================================================================
//
// fdrawcmd.h
//
// =================================================================================================

#define FDRAWCMD_VERSION                0x0100010b

#define FD_CTL_CODE(i,m)                CTL_CODE(FILE_DEVICE_UNKNOWN, i, m, FILE_READ_DATA|FILE_WRITE_DATA)

#define IOCTL_FDRAWCMD_GET_VERSION      FD_CTL_CODE(0x888, METHOD_BUFFERED)
#define IOCTL_FDCMD_READ_TRACK          FD_CTL_CODE(0x802, METHOD_OUT_DIRECT)
#define IOCTL_FDCMD_SPECIFY             FD_CTL_CODE(0x803, METHOD_BUFFERED)
#define IOCTL_FDCMD_SENSE_DRIVE_STATUS  FD_CTL_CODE(0x804, METHOD_BUFFERED)
#define IOCTL_FDCMD_WRITE_DATA          FD_CTL_CODE(0x805, METHOD_IN_DIRECT)
#define IOCTL_FDCMD_READ_DATA           FD_CTL_CODE(0x806, METHOD_OUT_DIRECT)
#define IOCTL_FDCMD_RECALIBRATE         FD_CTL_CODE(0x807, METHOD_BUFFERED)
#define IOCTL_FDCMD_SENSE_INT_STATUS    FD_CTL_CODE(0x808, METHOD_BUFFERED)
#define IOCTL_FDCMD_WRITE_DELETED_DATA  FD_CTL_CODE(0x809, METHOD_IN_DIRECT)
#define IOCTL_FDCMD_READ_ID             FD_CTL_CODE(0x80a, METHOD_BUFFERED)
#define IOCTL_FDCMD_READ_DELETED_DATA   FD_CTL_CODE(0x80c, METHOD_OUT_DIRECT)
#define IOCTL_FDCMD_FORMAT_TRACK        FD_CTL_CODE(0x80d, METHOD_BUFFERED)
#define IOCTL_FDCMD_DUMPREG             FD_CTL_CODE(0x80e, METHOD_BUFFERED)
#define IOCTL_FDCMD_SEEK                FD_CTL_CODE(0x80f, METHOD_BUFFERED)
#define IOCTL_FDCMD_VERSION             FD_CTL_CODE(0x810, METHOD_BUFFERED)
#define IOCTL_FDCMD_SCAN_EQUAL          FD_CTL_CODE(0x811, METHOD_IN_DIRECT)
#define IOCTL_FDCMD_PERPENDICULAR_MODE  FD_CTL_CODE(0x812, METHOD_BUFFERED)
#define IOCTL_FDCMD_CONFIGURE           FD_CTL_CODE(0x813, METHOD_BUFFERED)
#define IOCTL_FDCMD_LOCK                FD_CTL_CODE(0x814, METHOD_BUFFERED)
#define IOCTL_FDCMD_VERIFY              FD_CTL_CODE(0x816, METHOD_BUFFERED)
#define IOCTL_FDCMD_POWERDOWN_MODE      FD_CTL_CODE(0x817, METHOD_BUFFERED)
#define IOCTL_FDCMD_PART_ID             FD_CTL_CODE(0x818, METHOD_BUFFERED)
#define IOCTL_FDCMD_SCAN_LOW_OR_EQUAL   FD_CTL_CODE(0x819, METHOD_IN_DIRECT)
#define IOCTL_FDCMD_SCAN_HIGH_OR_EQUAL  FD_CTL_CODE(0x81d, METHOD_IN_DIRECT)
#define IOCTL_FDCMD_SAVE                FD_CTL_CODE(0x82e, METHOD_BUFFERED)
#define IOCTL_FDCMD_OPTION              FD_CTL_CODE(0x833, METHOD_BUFFERED)
#define IOCTL_FDCMD_RESTORE             FD_CTL_CODE(0x84e, METHOD_BUFFERED)
#define IOCTL_FDCMD_DRIVE_SPEC_CMD      FD_CTL_CODE(0x88e, METHOD_BUFFERED)
#define IOCTL_FDCMD_RELATIVE_SEEK       FD_CTL_CODE(0x88f, METHOD_BUFFERED)
#define IOCTL_FDCMD_FORMAT_AND_WRITE    FD_CTL_CODE(0x8ef, METHOD_BUFFERED)

#define IOCTL_FD_SCAN_TRACK             FD_CTL_CODE(0x900, METHOD_BUFFERED)
#define IOCTL_FD_GET_RESULT             FD_CTL_CODE(0x901, METHOD_BUFFERED)
#define IOCTL_FD_RESET                  FD_CTL_CODE(0x902, METHOD_BUFFERED)
#define IOCTL_FD_SET_MOTOR_TIMEOUT      FD_CTL_CODE(0x903, METHOD_BUFFERED)
#define IOCTL_FD_SET_DATA_RATE          FD_CTL_CODE(0x904, METHOD_BUFFERED)
#define IOCTL_FD_GET_FDC_INFO           FD_CTL_CODE(0x905, METHOD_BUFFERED)
#define IOCTL_FD_GET_REMAIN_COUNT       FD_CTL_CODE(0x906, METHOD_BUFFERED)
#define IOCTL_FD_SET_DISK_CHECK         FD_CTL_CODE(0x908, METHOD_BUFFERED)
#define IOCTL_FD_SET_SHORT_WRITE        FD_CTL_CODE(0x909, METHOD_BUFFERED)
#define IOCTL_FD_SET_SECTOR_OFFSET      FD_CTL_CODE(0x90a, METHOD_BUFFERED)
#define IOCTL_FD_SET_HEAD_SETTLE_TIME   FD_CTL_CODE(0x90b, METHOD_BUFFERED)
#define IOCTL_FD_LOCK_FDC               FD_CTL_CODE(0x910, METHOD_BUFFERED)
#define IOCTL_FD_UNLOCK_FDC             FD_CTL_CODE(0x911, METHOD_BUFFERED)
#define IOCTL_FD_MOTOR_ON               FD_CTL_CODE(0x912, METHOD_BUFFERED)
#define IOCTL_FD_MOTOR_OFF              FD_CTL_CODE(0x913, METHOD_BUFFERED)
#define IOCTL_FD_WAIT_INDEX             FD_CTL_CODE(0x914, METHOD_BUFFERED)
#define IOCTL_FD_TIMED_SCAN_TRACK       FD_CTL_CODE(0x915, METHOD_BUFFERED)
#define IOCTL_FD_RAW_READ_TRACK         FD_CTL_CODE(0x916, METHOD_OUT_DIRECT)
#define IOCTL_FD_CHECK_DISK             FD_CTL_CODE(0x917, METHOD_BUFFERED)
#define IOCTL_FD_GET_TRACK_TIME         FD_CTL_CODE(0x918, METHOD_BUFFERED)

#define FD_OPTION_MT        0x80
#define FD_OPTION_MFM       0x40
#define FD_OPTION_SK        0x20
#define FD_OPTION_DIR       0x40
#define FD_OPTION_EC        0x01
#define FD_OPTION_FM        0x00
#define FD_ENCODING_MASK    FD_OPTION_MFM

#define FD_RATE_MASK        3
#define FD_RATE_500K        0
#define FD_RATE_300K        1
#define FD_RATE_250K        2
#define FD_RATE_1M          3

#define FDC_TYPE_UNKNOWN    0
#define FDC_TYPE_UNKNOWN2   1
#define FDC_TYPE_NORMAL     2
#define FDC_TYPE_ENHANCED   3
#define FDC_TYPE_82077      4
#define FDC_TYPE_82077AA    5
#define FDC_TYPE_82078_44   6
#define FDC_TYPE_82078_64   7
#define FDC_TYPE_NATIONAL   8

#define FDC_SPEED_250K      0x01
#define FDC_SPEED_300K      0x02
#define FDC_SPEED_500K      0x04
#define FDC_SPEED_1M        0x08
#define FDC_SPEED_2M        0x10

#pragma pack(push,1)

typedef struct tagFD_ID_HEADER {
    BYTE cyl, head, sector, size;
} FD_ID_HEADER, *PFD_ID_HEADER;

typedef struct tagFD_SEEK_PARAMS {
    BYTE cyl;
    BYTE head;
} FD_SEEK_PARAMS, *PFD_SEEK_PARAMS;

typedef struct tagFD_RELATIVE_SEEK_PARAMS {
    BYTE flags;
    BYTE head;
    BYTE offset;
} FD_RELATIVE_SEEK_PARAMS, *PFD_RELATIVE_SEEK_PARAMS;

typedef struct tagFD_READ_WRITE_PARAMS {
    BYTE flags;
    BYTE phead;
    BYTE cyl, head, sector, size;
    BYTE eot, gap, datalen;
} FD_READ_WRITE_PARAMS, *PFD_READ_WRITE_PARAMS;

typedef struct tagFD_CMD_RESULT {
    BYTE st0, st1, st2;
    BYTE cyl, head, sector, size;
} FD_CMD_RESULT, *PFD_CMD_RESULT;

typedef struct tagFD_FORMAT_PARAMS {
    BYTE flags;
    BYTE phead;
    BYTE size, sectors, gap, fill;
    FD_ID_HEADER Header[];
} FD_FORMAT_PARAMS, *PFD_FORMAT_PARAMS;

typedef struct tagFD_READ_ID_PARAMS {
    BYTE flags;
    BYTE head;
} FD_READ_ID_PARAMS, *PFD_READ_ID_PARAMS;

typedef struct tagFD_CONFIGURE_PARAMS {
    BYTE eis_efifo_poll_fifothr;
    BYTE pretrk;
} FD_CONFIGURE_PARAMS, *PFD_CONFIGURE_PARAMS;

typedef struct tagFD_SPECIFY_PARAMS {
    BYTE srt_hut;
    BYTE hlt_nd;
} FD_SPECIFY_PARAMS, *PFD_SPECIFY_PARAMS;

typedef struct tagFD_SENSE_PARAMS {
    BYTE head;
} FD_SENSE_PARAMS, *PFD_SENSE_PARAMS;

typedef struct tagFD_DRIVE_STATUS {
    BYTE st3;
} FD_DRIVE_STATUS, *PFD_DRIVE_STATUS;

typedef struct tagFD_INTERRUPT_STATUS {
    BYTE st0;
    BYTE pcn;
} FD_INTERRUPT_STATUS, *PFD_INTERRUPT_STATUS;

typedef struct tagFD_PERPENDICULAR_PARAMS {
    BYTE ow_ds_gap_wgate;
} FD_PERPENDICULAR_PARAMS, *PFD_PERPENDICULAR_PARAMS;

typedef struct tagFD_LOCK_PARAMS {
    BYTE lock;
} FD_LOCK_PARAMS, *PFD_LOCK_PARAMS;

typedef struct tagFD_LOCK_RESULT {
    BYTE lock;
} FD_LOCK_RESULT, *PFD_LOCK_RESULT;

typedef struct tagFD_DUMPREG_RESULT {
    BYTE pcn0, pcn1, pcn2, pcn3;
    BYTE srt_hut;
    BYTE hlt_nd;
    BYTE sceot;
    BYTE lock_d0123_gap_wgate;
    BYTE eis_efifo_poll_fifothr;
    BYTE pretrk;
} FD_DUMPREG_RESULT, *PFD_DUMPREG_RESULT;

typedef struct tagFD_SECTOR_OFFSET_PARAMS {
    BYTE sectors;
} FD_SECTOR_OFFSET_PARAMS, *PFD_SECTOR_OFFSET_PARAMS;

typedef struct tagFD_SHORT_WRITE_PARAMS {
    DWORD length;
    DWORD finetune;
} FD_SHORT_WRITE_PARAMS, *PFD_SHORT_WRITE_PARAMS;

typedef struct tagFD_SCAN_PARAMS {
    BYTE flags;
    BYTE head;
} FD_SCAN_PARAMS, *PFD_SCAN_PARAMS;

typedef struct tagFD_SCAN_RESULT {
    BYTE count;
    FD_ID_HEADER Header[];
} FD_SCAN_RESULT, *PFD_SCAN_RESULT;

typedef struct tagFD_TIMED_ID_HEADER {
    DWORD reltime;
    BYTE cyl, head, sector, size;
} FD_TIMED_ID_HEADER, *PFD_TIMED_ID_HEADER;

typedef struct tagFD_TIMED_SCAN_RESULT {
    BYTE count;
    BYTE firstseen;
    DWORD tracktime;
    FD_TIMED_ID_HEADER Header[];
} FD_TIMED_SCAN_RESULT, *PFD_TIMED_SCAN_RESULT;

typedef struct tagFD_FDC_INFO {
    BYTE ControllerType;
    BYTE SpeedsAvailable;
    BYTE BusType;
    DWORD BusNumber;
    DWORD ControllerNumber;
    DWORD PeripheralNumber;
} FD_FDC_INFO, *PFD_FDC_INFO;

typedef struct tagFD_RAW_READ_PARAMS {
    BYTE flags;
    BYTE head, size;
} FD_RAW_READ_PARAMS, *PFD_RAW_READ_PARAMS;

#pragma pack(pop)

// =================================================================================================
//
// akaiutil_io.h
//
// =================================================================================================

#ifdef _VISUALCPP

#define AKAI_FL_DISK_SIDES			2
#define AKAI_FL_DISK_TRACKS			80
#define AKAI_FLL_DISK_SECTORS		5
#define AKAI_FLH_DISK_SECTORS		10
#define AKAI_FLL_DISK_DATARATE		FD_RATE_250K
#define AKAI_FLH_DISK_DATARATE		FD_RATE_500K
#define AKAI_FL_SECTOR_SIZE_CODE	3
#define AKAI_FLL_SECTOR_GAP3		0x74
#define AKAI_FLH_SECTOR_GAP3		0x74
#define AKAI_FL_SECTOR_FILL			0x00
#define AKAI_FL_SECTOR_BASE			1
#define AKAI_FLL_SECTOR_OFFSET		3
#define AKAI_FLH_SECTOR_OFFSET		6
#define AKAI_FLL_TRACK_SKEW			2
#define AKAI_FLH_TRACK_SKEW			4

#define AKAI_FL_SECSIZE		0x0400

#if defined(AKAI_FL_BLOCKSIZE)&&(AKAI_FL_SECSIZE!=AKAI_FL_BLOCKSIZE)
#error "AKAI_FL_SECSIZE!=AKAI_FL_BLOCKSIZE"
#endif

#ifndef FLDRNUM
#define FLDRNUM		2
#endif

#define FLDR_TYPE_FLL		0
#define FLDR_TYPE_FLH		1

#ifndef FLDR_RETRYMAX
#define FLDR_RETRYMAX	5
#endif
#endif /* _VISUALCPP */

struct blk_cache_s {
    int valid;
    int modified;
    int fd;
#ifdef _VISUALCPP
    int fldrn;
#endif /* _VISUALCPP */
    OFF64_T startoff;
    u_int blk;
    u_int blksize;
#define BLK_CACHE_AGE_MAX		0xffffffff
    u_int age;
    u_char *buf;
};

#ifndef BLK_CACHE_NUM
#define BLK_CACHE_NUM	512
#endif

#define IO_BLKS_READ	0
#define IO_BLKS_WRITE	1

// =================================================================================================
//
// akaiutil.h
//
// =================================================================================================

/* floppy */
#define AKAI_FL_BLOCKSIZE		0x0400
#define AKAI_FLL_SIZE			0x0320
#define AKAI_FLH_SIZE			0x0640

/* harddisk */
#define AKAI_HD_BLOCKSIZE		0x2000
#define AKAI_HD9_MAXSIZE		0x1fff
#define AKAI_HD9_DEFSIZE		0x09c4
#define AKAI_HD9_SH205SIZE		0x0a29
#define AKAI_HD9_SUPRA20MSIZE	0x09c4
#define AKAI_HD9_SUPRA30MSIZE	0x0ee4
#define AKAI_HD9_SUPRA60MSIZE	0x1dc8
#define AKAI_HD_MAXSIZE			0xffff
#define AKAI_PART_MAXSIZE		0x1e00
#define AKAI_PART_NUM			18
#define AKAI_DDPART_CBLKS		0x20
#define AKAI_DDPART_NUM			18
#define AKAI_DISKSIZE_MAX		(AKAI_HD_MAXSIZE*AKAI_HD_BLOCKSIZE)

/* names */
#define AKAI_NAME_LEN_S900	10
#define AKAI_NAME_LEN		12

/* FAT */
#define AKAI_FAT_CODE_FREE			0x0000
#define AKAI_FAT_CODE_BAD			0x2000
#define AKAI_FAT_CODE_SYS900FL		0x0000
#define AKAI_FAT_CODE_SYS900HD		0xffff
#define AKAI_FAT_CODE_SYS			0x4000
#define AKAI_FAT_CODE_DIREND900HD	0x8000
#define AKAI_FAT_CODE_DIREND1000HD	0x4000
#define AKAI_FAT_CODE_DIREND3000	0x8000
#define AKAI_FAT_CODE_FILEEND900	0x8000
#define AKAI_FAT_CODE_FILEEND		0xc000

/* DD FAT */
#define AKAI_DDFAT_CODE_FREE		0x0000
#define AKAI_DDFAT_CODE_BAD			0x2000
#define AKAI_DDFAT_CODE_SYS			0x8000
#define AKAI_DDFAT_CODE_END			0xffff

/* OS versions */
#define AKAI_OSVER_S900VOL			0x0000
#define AKAI_OSVER_S1000MAX			0x0428
#define AKAI_OSVER_S1100MAX			0x091e
#define AKAI_OSVER_S3000MAX			0x1100

/* file */
#define AKAI_FILE_SIZEMAX	0xffffff

struct akai_voldir_entry_s {
    u_char name[AKAI_NAME_LEN];
#define AKAI_FILE_TAGNUM	0x04
#define AKAI_FILE_TAGFREE	0x00
#define AKAI_FILE_TAGS1000	0x20
    u_char tag[AKAI_FILE_TAGNUM];
#define AKAI_FTYPE_FREE		0x00
    u_char type;
    u_char size[3];
    u_char start[2];
    u_char osver[2];
};

struct akai_volparam_s {
    u_char progselmidich1;
    u_char progselomni;
    u_char progselenab;
    u_char prognr1;
    u_char playinominovrr;
    u_char sysexch1;
    u_char dummy1[42];
};

#define AKAI_VOLDIR_ENTRIES_S900HD		128
#define AKAI_VOLDIR_ENTRIES_S1000HD		126
#define AKAI_VOLDIR_ENTRIES_S3000HD		510
#define AKAI_VOLDIR_ENTRIES_1BLKHD		341

struct akai_voldir900hd_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S900HD];
    u_char dummy1[0x1400];
};
#define AKAI_VOLDIR900HD_BLKS		1

struct akai_voldir1000hd_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S1000HD];
    struct akai_volparam_s param;
    u_char dummy1[0x1400];
};
#define AKAI_VOLDIR1000HD_BLKS		1

struct akai_voldir3000hd_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S3000HD];
    struct akai_volparam_s param;
    u_char dummy1[0x1000];
};
#define AKAI_VOLDIR3000HD_BLKS		2

#define AKAI_VOLDIR_ENTRIES_S1000FL		64
#define AKAI_VOLDIR_ENTRIES_S3000FL		510

struct akai_flvol_label_s {
    u_char name[AKAI_NAME_LEN];
    u_char dummy1[2];
    u_char osver[2];
    struct akai_volparam_s param;
};

struct akai_fllhead_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S1000FL];
#define AKAI_FAT_ENTRIES_FLL	AKAI_FLL_SIZE
    u_char fatblk[AKAI_FAT_ENTRIES_FLL][2];
    struct akai_flvol_label_s label;
    u_char dummy1[0x0380];
};
#define AKAI_FLLHEAD_BLKS	4

struct akai_flhhead_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S1000FL];
#define AKAI_FAT_ENTRIES_FLH	AKAI_FLH_SIZE
    u_char fatblk[AKAI_FAT_ENTRIES_FLH][2];
    struct akai_flvol_label_s label;
    u_char dummy1[0x0140];
};
#define AKAI_FLHHEAD_BLKS	5

struct akai_voldir3000fl_s {
    struct akai_voldir_entry_s file[AKAI_VOLDIR_ENTRIES_S3000FL];
    u_char dummy1[0x0030];
};
#define AKAI_VOLDIR3000FL_BLKS		12
#define AKAI_VOLDIR3000FLL_BSTART	4
#define AKAI_VOLDIR3000FLH_BSTART	5
#define AKAI_VOLDIR3000FL_FTYPE		0xff

union akai_voldir_u {
    struct akai_voldir900hd_s s900hd;
    struct akai_voldir1000hd_s s1000hd;
    struct akai_voldir3000hd_s s3000hd;
    struct akai_voldir3000fl_s s3000fl;
};

struct akai_hd9rootdir_entry_s {
    u_char name[AKAI_NAME_LEN_S900];
#define AKAI_VOL_START_INACT		0x0000
    u_char start[2];
};

struct akai_hd9head_s {
#define AKAI_HD9ROOTDIR_ENTRIES		128
    struct akai_hd9rootdir_entry_s vol[AKAI_HD9ROOTDIR_ENTRIES];
    u_char size[2];
#define AKAI_HD9FLAG1_SIZEVALID		0xff
    u_char flag1;
    u_char flag2;
#define AKAI_HD9FAT0_ENTRIES	0x0cfe
    u_char fatblk0[AKAI_HD9FAT0_ENTRIES][2];
#define AKAI_HD9FAT_ENTRIES		AKAI_HD9_MAXSIZE
    u_char fatblk[AKAI_HD9FAT_ENTRIES][2];
    u_char dummy1[0x6000-AKAI_HD9FAT_ENTRIES*2];
};
#define AKAI_HD9HEAD_BLKS	4

struct akai_rootdir_entry_s {
    u_char name[AKAI_NAME_LEN];
#define AKAI_VOL_TYPE_INACT		0x00
#define AKAI_VOL_TYPE_S1000		0x01
#define AKAI_VOL_TYPE_S3000		0x03
#define AKAI_VOL_TYPE_CD3000	0x07
    u_char type;
#define AKAI_VOL_LNUM_OFF	0
#define AKAI_VOL_LNUM_MIN	1
#define AKAI_VOL_LNUM_MAX	128
    u_char lnum;
    u_char start[2];
};

struct akai_parttab_s {
#define AKAI_PARTTAB_MAGICNUM	128
#define AKAI_PARTTAB_MAGICVAL	9999
    u_char magic[AKAI_PARTTAB_MAGICNUM][2];
    u_char partnum;
    u_char ddpartnum;
    u_char part[AKAI_PART_NUM+1][2];
    u_char ddpart[AKAI_DDPART_NUM+1][2];
    u_char dummy1[0x0100-2-2*(AKAI_PART_NUM+1)-2*(AKAI_DDPART_NUM+1)];
};

struct akai_parthead_s {
    u_char size[2];
#define AKAI_PARTHEAD_MAGICNUM	98
#define AKAI_PARTHEAD_MAGICVAL	3333
    u_char magic[AKAI_PARTHEAD_MAGICNUM][2];
    u_char chksum[4];
#define AKAI_ROOTDIR_ENTRIES	100
    struct akai_rootdir_entry_s vol[AKAI_ROOTDIR_ENTRIES];
#define AKAI_FAT_ENTRIES	AKAI_PART_MAXSIZE
    u_char fatblk[AKAI_FAT_ENTRIES][2];
    u_char dummy1[0x00f6];
    struct akai_parttab_s parttab;
#define AKAI_PARTHEAD_TAGSMAGIC	"TAGS"
    u_char tagsmagic[4];
#define AKAI_PARTHEAD_TAGNUM	26
    u_char tag[AKAI_PARTHEAD_TAGNUM][AKAI_NAME_LEN];
    u_char dummy2[0x1a00-4-AKAI_PARTHEAD_TAGNUM*AKAI_NAME_LEN];
};
#define AKAI_PARTHEAD_BLKS	3

struct akai_ddtake_s {
    u_char name[AKAI_NAME_LEN];
    u_char cstarts[2];
    u_char cstarte[2];
    u_char wstart[4];
    u_char wend[4];
#define AKAI_DDTAKESTAT_FREE		0x00
#define AKAI_DDTAKESTAT_USED		0x01
    u_char stat;
#define AKAI_DDTAKESTYPE_MONO		0x00
#define AKAI_DDTAKESTYPE_STEREO		0x01
    u_char stype;
    u_char srate[2];
    u_char vspeed[2];
    u_char finerate[2];
    u_char wstartm[4];
    u_char wendm[4];
    u_char fadein[2];
    u_char fadeout[2];
    u_char stlvl;
    u_char pan;
    u_char stmix;
    u_char midich1;
    u_char midinote;
    u_char startm;
    u_char deemph;
    u_char dummy1[5];
    u_char predel[2];
    u_char outlvl;
    u_char outch;
    u_char fxbus;
    u_char sendlvl;
    u_char dummy2[2];
};

struct akai_ddparthead_s {
#define AKAI_DDFAT_ENTRIES	0x07ff
    u_char fatcl[AKAI_DDFAT_ENTRIES][2];
    u_char dummy1[0x2000-AKAI_DDFAT_ENTRIES*2];
#define AKAI_DDTAKE_MAXNUM	256
    struct akai_ddtake_s take[AKAI_DDTAKE_MAXNUM];
};
#define AKAI_DDPARTHEAD_BLKS	3
#define AKAI_DDTAKE_ENVBLKSIZW	128
#define AKAI_DDTAKE_ENVMAXVAL	0x20

union akai_head_u {
    struct akai_fllhead_s fll;
    struct akai_flhhead_s flh;
    struct akai_hd9head_s hd9;
    struct akai_parthead_s hd;
    struct akai_ddparthead_s dd;
};

struct akai_cdinfohead_s {
    u_char fnum[2];
    u_char volesiz[AKAI_ROOTDIR_ENTRIES][2];
    u_char cdlabel[AKAI_NAME_LEN];
};
#define AKAI_CDINFO_BLK			AKAI_PARTHEAD_BLKS
#define AKAI_CDINFO_MINSIZB		3
#define AKAI_CDINFO_DEFLABEL	"CDROM"

struct disk_s {
    u_int index;
    int fd;
#ifdef _VISUALCPP
    int fldrn;
#endif /* _VISUALCPP */
    int readonly;
    OFF64_T startoff;
    u_int totsize;
#define DISK_TYPE_FLL	1
#define DISK_TYPE_FLH	2
#define DISK_TYPE_HD9	9
#define DISK_TYPE_HD	3
    u_int type;
    u_int blksize;
    u_int bsize;
};

struct part_s {
    struct disk_s *diskp;
    int valid;
#define PART_TYPE_FLL	DISK_TYPE_FLL
#define PART_TYPE_FLH	DISK_TYPE_FLH
#define PART_TYPE_HD9	DISK_TYPE_HD9
#define PART_TYPE_HD	DISK_TYPE_HD
#define PART_TYPE_DD	4
    u_int type;
    u_int index;
    u_int blksize;
    u_int bstart;
    u_int bsize;
    u_int csize;
    u_int bsyssize;
    u_int bfree;
    u_int bbad;
    u_char (*fat)[2];
    union akai_head_u head;
    u_int volnummax;
    char letter;
};

struct vol_s {
    struct part_s *partp;
    u_int index;
#define AKAI_VOL_TYPE_S900		0xf9
    u_int type;
    u_int lnum;
    u_int osver;
#define VOL_DIRBLKS	AKAI_VOLDIR3000FL_BLKS
    u_int dirblk[VOL_DIRBLKS];
    u_int fimax;
    struct akai_voldir_entry_s *file;
    struct akai_volparam_s *param;
    union akai_voldir_u dir;
    char name[AKAI_NAME_LEN+1];
};

struct file_s {
    struct vol_s *volp;
    u_int index;
    u_int bstart;
    u_int size;
    u_int type;
    u_int osver;
    u_char tag[AKAI_FILE_TAGNUM];
    char name[AKAI_NAME_LEN+4+1];
};

#ifndef DISK_NUM_MAX
#define DISK_NUM_MAX	64
#endif
#ifndef PART_NUM_MAX
#define PART_NUM_MAX	512
#endif

#ifndef AKAI_DISKSIZE_GRAN
#define AKAI_DISKSIZE_GRAN		2048
#endif

// =================================================================================================
//
// akaiutil_file.h
//
// =================================================================================================

#define AKAI_S900_FTYPE_MIN		'A'
#define AKAI_S900_FTYPE_MAX		'Z'
#define AKAI_S1000_FTYPE_MIN	'a'
#define AKAI_S1000_FTYPE_MAX	'z'
#define AKAI_S3000_FTYPE_MIN	('a'+0x80)
#define AKAI_S3000_FTYPE_MAX	('z'+0x80)

struct akai_sample900_s {
    char name[AKAI_NAME_LEN_S900];
    u_char dummy1[6];
    u_char slen[4];
    u_char srate[2];
#define SAMPLE900_NPITCH_DEF		(60*16)
    u_char npitch[2];
    u_char loud[2];
#define SAMPLE900_PMODE_ONESHOT		'O'
#define SAMPLE900_PMODE_LOOP		'L'
#define SAMPLE900_PMODE_ALTLOOP		'A'
    u_char pmode;
    u_char dummy2;
    u_char end[4];
    u_char start[4];
    u_char llen[4];
    u_char dmadesa[2];
#define SAMPLE900_TYPE_NORM		0x00
#define SAMPLE900_TYPE_VELXF	0xff
    u_char type;
#define SAMPLE900_DIR_NORM		'N'
#define SAMPLE900_DIR_REV		'R'
    u_char dir;
    u_char dummy3[10];
    u_char locat[4];
    u_char dummy4[2];
};

#define SAMPLE900COMPR_GROUP_SAMPNUM		10
#define SAMPLE900COMPR_UPBITNUM_NEGCODE_OFF	16
#define SAMPLE900COMPR_UPBITNUM_MAX			12
#define SAMPLE900COMPR_INTERVALSIZ			(1<<SAMPLE900COMPR_UPBITNUM_MAX)
#define SAMPLE900COMPR_BITMASK				(SAMPLE900COMPR_INTERVALSIZ-1)
#define SAMPLE900COMPR_INTERVALSIZ2			(SAMPLE900COMPR_INTERVALSIZ>>1)
#define AKAI_SAMPLE900_FTYPE	'S'

struct akai_program900_s {
    char name[AKAI_NAME_LEN_S900];
    u_char dummy1[6];
    u_char dummy2[2];
#define PROGRAM900_KGA_NONE		0x0000
    u_char kg1a[2];
    u_char dummy3;
    u_char kgxf;
    u_char dummy4;
    u_char kgnum;
    u_char dummy5[14];
};

struct akai_program900kg_s {
    u_char keyhi;
    u_char keylo;
#define PROGRAM900KG_VELSWTH_NOSOFT	0
#define PROGRAM900KG_VELSWTH_NOLOUD	128
    u_char velswth;
    u_char dummy1[15];
#define PROGRAM900KG_FLAGS_PCONST	0x01
#define PROGRAM900KG_FLAGS_VELXF	0x02
#define PROGRAM900KG_FLAGS_ONESHOT	0x08
    u_char flags;
#define PROGRAM900KG_OUTCH1_LEFT	0x08
#define PROGRAM900KG_OUTCH1_RIGHT	0x09
#define PROGRAM900KG_OUTCH1_ANY		0xff
    u_char outch1;
    u_char midichoff;
    u_char dummy2[3];
    u_char sname1[AKAI_NAME_LEN_S900];
    u_char dummy3[4];
    u_char velxfv50;
    u_char dummy4;
#define PROGRAM900KG_SHDRA_NONE		0x0000
    u_char shdra1[2];
    u_char tune1[2];
    u_char filter1;
    u_char loud1;
    u_char sname2[AKAI_NAME_LEN_S900];
    u_char dummy5[6];
    u_char shdra2[2];
    u_char tune2[2];
    u_char filter2;
    u_char loud2;
    u_char kgnexta[2];
};

#define AKAI_PROGRAM900_FTYPE	'P'

struct akai_drum900des_s {
    u_char inpnr1;
    u_char midich1;
    u_char midinote;
    u_char gain;
    u_char ask90_trig;
    u_char dummy1[3];
#define DRUM900DES_ITYPE_ASK90		0x00
#define DRUM900DES_ITYPE_ME35T		0xff
    u_char itype;
    u_char me35t_trig;
    u_char me35t_vcurv1;
    u_char dummy2;
    u_char captt4[2];
    u_char ontime4[2];
    u_char recovt4[2];
    u_char dummy3[8];
    u_char ask90_resba[2];
    u_char ask90_adcla[2];
};

struct akai_drum900_s {
    u_char ask90enab;
    u_char ask90sens;
    u_char dummy1[20];
#define DRUM900_INPUTNUM		8
    struct akai_drum900des_s ddes[DRUM900_INPUTNUM];
};

#define AKAI_DRUM900_FTYPE		'D'
#define AKAI_DRUM900_FNAME		"DRUM SET  "

struct akai_ovs900_s {
    char progname[AKAI_NAME_LEN_S900];
    u_char dummy1[6];
    u_char dummy2[4];
    u_char testmidich[2];
    u_char testmidikey[2];
    u_char testmidivel[2];
    u_char dummy3;
#define OVS900_BMIDICH1MASK		0x7f
#define OVS900_OMNIMASK			0x80
    u_char bmidich1omni;
    u_char loudness;
#define OVS900_CTRLPORT_MIDI	0x01
#define OVS900_CTRLPORT_RS232	0x02
    u_char ctrlport;
    u_char progchange;
    u_char dummy4[4];
    u_char pwheelrange;
    u_char rs232brate10[2];
    u_char dummy5[2];
};

#define AKAI_OVS900_FTYPE		'O'
#define AKAI_OVS900_FNAME		"OVERALL SE"

#define AKAI_FIXUP900_FTYPE		'F'
#define AKAI_MEMIMG900_FTYPE	'M'

#define AKAI_EMPTY1000_FNAME	"VVVVVVVVVVVV"

struct akai_genfilehdr_s {
    u_char blockid;
    u_char dummy1[2];
    u_char name[AKAI_NAME_LEN];
};

struct akai_sample1000loop_s {
    u_char at[4];
    u_char flen[2];
    u_char len[4];
#define SAMPLE1000LOOP_TIME_NOLOOP	0
#define SAMPLE1000LOOP_TIME_HOLD	9999
    u_char time[2];
};

struct akai_sample1000_s {
#define SAMPLE1000_BLOCKID		0x03
    u_char blockid;
#define SAMPLE1000_BANDW_10KHZ		0x00
#define SAMPLE1000_BANDW_20KHZ		0x01
    u_char bandw;
    u_char rkey;
    u_char name[AKAI_NAME_LEN];
    u_char dummy1;
    u_char lnum;
    u_char lfirst;
    u_char dummy2;
#define SAMPLE1000_PMODE_LOOP		0x00
#define SAMPLE1000_PMODE_LOOPNOTREL	0x01
#define SAMPLE1000_PMODE_NOLOOP		0x02
#define SAMPLE1000_PMODE_TOEND		0x03
    u_char pmode;
    u_char ctune;
    u_char stune;
    u_char locat[4];
    u_char slen[4];
    u_char start[4];
    u_char end[4];
#define AKAI_SAMPLE1000_LOOPNUM	8
    struct akai_sample1000loop_s loop[AKAI_SAMPLE1000_LOOPNUM];
    u_char dummy3[2];
#define AKAI_SAMPLE1000_STPAIRA_NONE	0xffff
    u_char stpaira[2];
    u_char srate[2];
    u_char hltoff;
    u_char dummy4[9];
};

#define AKAI_SAMPLE1000_FTYPE	's'

struct akai_sample3000_s {
#define SAMPLE3000_BLOCKID		SAMPLE1000_BLOCKID
    struct akai_sample1000_s s1000;
    u_char dummy1[42];
};

#define SAMPLE3000_STPAIRA_MULT	0x10
#define AKAI_SAMPLE3000_FTYPE	('s'+0x80)

#define AKAI_CDSAMPLE3000_FTYPE	('h'+0x80)

struct akai_program1000_s {
#define PROGRAM1000_BLOCKID		0x01
    u_char blockid;
#define PROGRAM1000_KGA_NONE	0x0000
    u_char kg1a[2];
    u_char name[AKAI_NAME_LEN];
    u_char dummy1;
#define PROGRAM1000_MIDICH1_OMNI	0xff
    u_char midich1;
    u_char dummy2[2];
    u_char keylo;
    u_char keyhi;
    u_char oct;
#define PROGRAM1000_AUXCH1_OFF		0xff
    u_char auxch1;
    u_char dummy3[18];
    u_char kgxf;
    u_char kgnum;
    u_char dummy4[107];
};

struct akai_program1000kgvelzone_s {
    u_char sname[AKAI_NAME_LEN];
    u_char vello;
    u_char velhi;
    u_char ctune;
    u_char stune;
    u_char loud;
    u_char filter;
    u_char pan;
#define PROGRAM1000_PMODE_SAMPLE		0x00
#define PROGRAM1000_PMODE_LOOP			0x01
#define PROGRAM1000_PMODE_LOOPNOTREL	0x02
#define PROGRAM1000_PMODE_NOLOOP		0x03
#define PROGRAM1000_PMODE_TOEND			0x04
    u_char pmode;
    u_char dummy1[2];
#define PROGRAM1000KG_SHDRA_NONE		0xffff
    u_char shdra[2];
};

struct akai_program1000kg_s {
#define PROGRAM1000KG_BLOCKID	0x02
    u_char blockid;
    u_char kgnexta[2];
    u_char keylo;
    u_char keyhi;
    u_char ctune;
    u_char stune;
    u_char filter;
    u_char dummy1[22];
    u_char velxf;
    u_char dummy2[3];
#define PROGRAM1000KG_VELZONENUM	4
    struct akai_program1000kgvelzone_s velzone[PROGRAM1000KG_VELZONENUM];
    u_char dummy3[2];
    u_char pconst[PROGRAM1000KG_VELZONENUM];
    u_char auxchoff[PROGRAM1000KG_VELZONENUM];
    u_char dummy4[10];
};

#define AKAI_PROGRAM1000_FTYPE	'p'

struct akai_program3000_s {
#define PROGRAM3000_BLOCKID		PROGRAM1000_BLOCKID
    struct akai_program1000_s s1000;
    u_char dummy1[42];
};

struct akai_program3000kg_s {
#define PROGRAM3000KG_BLOCKID	PROGRAM1000KG_BLOCKID
    struct akai_program1000kg_s s1000;
    u_char dummy1[42];
};

#define PROGRAM3000_KGA_MULT	0x10
#define PROGRAM3000_SHDRA_MULT	0x10
#define AKAI_PROGRAM3000_FTYPE	('p'+0x80)

struct akai_drum1000des_s {
    u_char midich1;
    u_char midinote;
    u_char sens;
    u_char trig;
    u_char vcurv1;
    u_char captt;
    u_char recovt;
    u_char ontime;
    u_char dummy1;
};

struct akai_drum1000_s {
#define DRUM1000_BLOCKID		0x01
    u_char blockid;
    u_char dummy1[2];
    u_char name[AKAI_NAME_LEN];
#define DRUM1000_UNITNUM		2
#define DRUM1000_INPUTNUM		8
    struct akai_drum1000des_s ddes1[DRUM1000_INPUTNUM];
    u_char dummy2[3];
    struct akai_drum1000des_s ddes2[DRUM1000_INPUTNUM];
};

#define AKAI_DRUM1000_FTYPE		'd'
#define AKAI_DRUM1000_FNAME		"DRUM INPUTS "

#define AKAI_FXFILE_FTYPE		'x'
#define AKAI_FXFILE_FNAME		"EFFECTS FILE"
#define AKAI_FXFILE_FSIZE		0x1c90
#define FXFILE1100_BLOCKID		0x00
#define FXFILE3000_BLOCKID		0x00
#define FXFILE3000XL_BLOCKID	0x02

struct akai_cuelist_s {
#define CUELIST_BLOCKID		0x00
    u_char blockid;
    u_char dummy1[2];
    u_char name[AKAI_NAME_LEN];
    u_char dummy2[7];
    u_char cuenum;
    u_char dummy3[105];
};

struct akai_cue_s {
    u_char name[AKAI_NAME_LEN];
    u_char time[5];
#define AKAI_CUETYPE_MOFF	0x00
#define AKAI_CUETYPE_MON	0x01
#define AKAI_CUETYPE_TOFF	0x02
#define AKAI_CUETYPE_TON	0x03
    u_char type;
    u_char midinote;
    u_char midivel;
    u_char pan;
    u_char stlvl;
    u_char midich1;
    u_char repeat1;
    u_char fadein[2];
    u_char fadeout[2];
    u_char dummy1[4];
};

#define AKAI_QLFILE_FTYPE		'q'
#define AKAI_QLFILE_FNAME		"QL1         "

#define AKAI_TLFILE_FTYPE		't'
#define AKAI_TLFILE_FNAME		"TL1         "

#define AKAI_MULTI3000_FTYPE	('m'+0x80)
#define AKAI_MULTI3000_FNAME	"MULTI FILE  "
#define MULTI3000_BLOCKID		0x00

#define AKAI_SYS1000_FTYPE	'c'
#define AKAI_SYS3000_FTYPE	('c'+0x80)

struct akai_cdsetup3000_s {
    u_char name[AKAI_NAME_LEN];
    u_char dummy1[3];
    u_char cdlabel[AKAI_NAME_LEN];
};

struct akai_cdsetup3000_entry_s {
    u_char parti;
    u_char voli;
    u_char filei[2];
};

#define AKAI_CDSETUP3000_FTYPE	'T'
#define AKAI_CDSETUP3000_FNAME	"NEW CD SETUP"

// =================================================================================================
//
// akaiutil_take.h
//
// =================================================================================================

#define AKAI_DDTAKE_FNAMEEND	".TK"

#define TAKE2WAV_CHECK		1
#define TAKE2WAV_EXPORT		2
#define TAKE2WAV_CREATE		4
#define TAKE2WAV_ALL		0xff

#define WAV2TAKE_OPEN		1

// =================================================================================================
//
// akaiutil_tar.h
//
// =================================================================================================

struct tar_head_s {
#define TAR_NAMELEN 100
    char name[TAR_NAMELEN];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[7];
    char space;
    char type;
    char linkname[TAR_NAMELEN];
#define TAR_USTAR "ustar\00000"
    char ustar[8];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
#define TAR_PREFIXLEN 155
    char prefix[TAR_PREFIXLEN];
    char zero[12];
};
#define TAR_BLOCKSIZE 512

#define TAR_TYPE_REG  '0'
#define TAR_TYPE_REG0 '\0'
#define TAR_TYPE_DIR  '5'

#define TAR_TAILZERO_BLOCKS	6

#define TAR_EXPORT_DISK				0x0001
#define TAR_EXPORT_PART				0x0002
#define TAR_EXPORT_VOL				0x0004
#define TAR_EXPORT_FILE				0x0008
#define TAR_EXPORT_DDFILE			0x0010
#define TAR_EXPORT_TAGSFILE			0x0020
#define TAR_EXPORT_VOLPARAMFILE		0x0040
#define TAR_EXPORT_ANYFILE			(TAR_EXPORT_FILE|TAR_EXPORT_DDFILE|TAR_EXPORT_TAGSFILE|TAR_EXPORT_VOLPARAMFILE)
#define TAR_EXPORT_WAV				0x1000
#define TAR_IMPORT_WAV				0x0100
#define TAR_IMPORT_WAVS9			0x1000
#define TAR_IMPORT_WAVS9C			0x2000
#define TAR_IMPORT_WAVS1			0x4000
#define TAR_IMPORT_WAVS3			0x8000

// =================================================================================================
//
// akaiutil_wav.h
//
// =================================================================================================

struct wav_riffhead_s {
#define WAV_RIFFHEAD_RIFFSTR "RIFF"
    char riffstr[4];
    u_char fsize[4];
#define WAV_RIFFHEAD_WAVESTR "WAVE"
    char wavestr[4];
};

struct wav_chunkhead_s {
    char typestr[4];
    u_char csize[4];
};
#define WAV_CHUNKHEAD_FMTSTR	"fmt "
#define WAV_CHUNKHEAD_DATASTR	"data"

struct wav_fmthead_s {
#define WAV_HEAD_FTAG_PCM 0x0001
    u_char ftag[2];
    u_char chnr[2];
    u_char srate[4];
    u_char drate[4];
    u_char balign[2];
    u_char bitnr[2];
};

#define WAV_HEAD_SIZE	(sizeof(struct wav_riffhead_s)+sizeof(struct wav_chunkhead_s)+sizeof(struct wav_fmthead_s)+sizeof(struct wav_chunkhead_s))

#ifndef WAV_AKAIHEAD_DISABLE
#define WAV_CHUNKHEAD_AKAIS900SAMPLEHEADSTR		"S9H "
#define WAV_CHUNKHEAD_AKAIS1000SAMPLEHEADSTR	"S1H "
#define WAV_CHUNKHEAD_AKAIS3000SAMPLEHEADSTR	"S3H "
#define WAV_CHUNKHEAD_AKAIDDTAKEHEADSTR			"TKH "

#define WAV_AKAIHEADTYPE_NONE			0x00
#define WAV_AKAIHEADTYPE_SAMPLE900		0x09
#define WAV_AKAIHEADTYPE_SAMPLE1000		0x01
#define WAV_AKAIHEADTYPE_SAMPLE3000		0x03
#define WAV_AKAIHEADTYPE_DDTAKE			0xdd
#endif

#endif // AKAIUTIL_ALL_H
