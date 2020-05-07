#ifndef __GPT_STRUCT__
#define __GPT_STRUCT__

/* Signature - “EFI PART” */
#define GPT_HEADER_SIGNATURE 0x5452415020494645ULL
#define GPT_HEADER_SIGNATURE_STR "EFI PART"
#define EFI_NAME_LEN 72
#define EFI_MAGIC_LEN 8
#define EFI_ENTRIES 32 
#define EFI_DISK_GUID_LEN 16
/* basic types */
typedef  unsigned char BYTE;
typedef unsigned short   U_INT16;
typedef unsigned int   U_INT32;
typedef unsigned long long U_INT64;
typedef unsigned short U_16;

struct EFI_header {
	BYTE magic[EFI_MAGIC_LEN];
	U_INT32 version;
	U_INT32 header_sz;
	U_INT32 crc32;
	U_INT32 reserved;
	U_INT64 header_lba;
	U_INT64 backup_lba;
	U_INT64 first_lba;
	U_INT64 last_lba;
	BYTE volume_uuid[EFI_DISK_GUID_LEN];
	U_INT64 entries_lba;
	U_INT32 entries_count;
	U_INT32 entries_size;
	U_INT32 entries_crc32;
} __attribute__((packed));


typedef struct __EFI_entry {
	BYTE type_uuid[16];
	BYTE uniq_uuid[16];
	U_INT64 first_lba;
	U_INT64 last_lba;
	U_INT64 attr;
	BYTE name[EFI_NAME_LEN];
}   __attribute__((packed)) EFI_entry;



struct __PTABLE_GPT {
	BYTE mbr[512];
	struct EFI_header header;
} __attribute__((packed));

typedef  struct __PTABLE_GPT PTABLE_GPT;


#endif
