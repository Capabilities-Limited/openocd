/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef OPENOCD_HELPER_CHERI_H
#define OPENOCD_HELPER_CHERI_H

#include <helper/align.h>
#include <helper/types.h>
#include <helper/system.h>

/* CHERI helper functions */
static inline size_t cheri_capability_size(unsigned int clen)
{
	return clen / 8;
}

static inline unsigned int cheri_capability_per_bytes(size_t byte_size, unsigned int clen)
{
	return byte_size / cheri_capability_size(clen);
}

/* For GDB CHERI capability buffer manipulation */
static inline size_t buf_cheri_capability_size(unsigned int clen)
{
	return DIV_ROUND_UP(clen + 1, 8);
}

static inline uint8_t *buf_alloc_cheri_capability(unsigned int count, unsigned int clen)
{
	return (uint8_t *)malloc(count * buf_cheri_capability_size(clen));
}

static inline void buf_set_cheri_capability_value(uint8_t *buffer,
	uint64_t value, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	if (clen == 128) {
		buffer[7] = (value >> 56) & 0xff;
		buffer[6] = (value >> 48) & 0xff;
		buffer[5] = (value >> 40) & 0xff;
		buffer[4] = (value >> 32) & 0xff;
		buffer[3] = (value >> 24) & 0xff;
		buffer[2] = (value >> 16) & 0xff;
		buffer[1] = (value >> 8) & 0xff;
		buffer[0] = (value >> 0) & 0xff;
	} else if (clen == 64) {
		buffer[3] = (value >> 24) & 0xff;
		buffer[2] = (value >> 16) & 0xff;
		buffer[1] = (value >> 8) & 0xff;
		buffer[0] = (value >> 0) & 0xff;
	}
}

static inline void buf_set_cheri_capability_meta(uint8_t *buffer,
	uint64_t meta, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	if (clen == 128) {
		buffer[15] = (meta >> 56) & 0xff;
		buffer[14] = (meta >> 48) & 0xff;
		buffer[13] = (meta >> 40) & 0xff;
		buffer[12] = (meta >> 32) & 0xff;
		buffer[11] = (meta >> 24) & 0xff;
		buffer[10] = (meta >> 16) & 0xff;
		buffer[9] = (meta >> 8) & 0xff;
		buffer[8] = (meta >> 0) & 0xff;
	} else if (clen == 64) {
		buffer[7] = (meta >> 24) & 0xff;
		buffer[6] = (meta >> 16) & 0xff;
		buffer[5] = (meta >> 8) & 0xff;
		buffer[4] = (meta >> 0) & 0xff;
	}
}

static inline void buf_set_cheri_capability_tag(uint8_t *buffer,
	bool tag, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	if (clen == 128)
		buffer[16] = (uint8_t)(tag ? 0x01 : 0x00);
	else
		buffer[8] = (uint8_t)(tag ? 0x01 : 0x00);
}

static inline uint64_t buf_get_cheri_capability_value(const uint8_t *buffer,
	unsigned int clen)
{
	assert(clen == 64 || clen == 128);
	uint64_t value = 0;

	if (clen == 128) {
		value = ((((uint64_t)buffer[7]) << 56) |
					(((uint64_t)buffer[6]) << 48) |
					(((uint64_t)buffer[5]) << 40) |
					(((uint64_t)buffer[4]) << 32) |
					(((uint64_t)buffer[3]) << 24) |
					(((uint64_t)buffer[2]) << 16) |
					(((uint64_t)buffer[1]) << 8)  |
					(((uint64_t)buffer[0]) << 0));
	} else if (clen == 64) {
		value = ((((uint32_t)buffer[3]) << 24) |
					(((uint32_t)buffer[2]) << 16) |
					(((uint32_t)buffer[1]) << 8)  |
					(((uint32_t)buffer[0]) << 0));
	}

	return value;
}

static inline uint64_t buf_get_cheri_capability_meta(const uint8_t *buffer,
	unsigned int clen)
{
	assert(clen == 64 || clen == 128);
	uint64_t meta = 0;

	if (clen == 128) {
		meta = ((((uint64_t)buffer[15]) << 56) |
				(((uint64_t)buffer[14]) << 48) |
				(((uint64_t)buffer[13]) << 40) |
				(((uint64_t)buffer[12]) << 32) |
				(((uint64_t)buffer[11]) << 24) |
				(((uint64_t)buffer[10]) << 16) |
				(((uint64_t)buffer[9]) << 8)  |
				(((uint64_t)buffer[8]) << 0));
	} else if (clen == 64) {
		meta = ((((uint32_t)buffer[7]) << 24) |
				(((uint32_t)buffer[6]) << 16) |
				(((uint32_t)buffer[5]) << 8)  |
				(((uint32_t)buffer[4]) << 0));
	}

	return meta;
}

static inline bool buf_get_cheri_capability_tag(const uint8_t *buffer, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	const unsigned int tag_pos = clen / 8;
	assert(buffer[tag_pos] == 0x0 || buffer[tag_pos] == 0x1);

	return buffer[tag_pos] != 0;
}

/**
 * Convert the bitwise layout of a CHERI capability:
 *   format for GDB --> internal OpenOCD representation
 *
 * Directly modifies the provided buffer.
 */
static inline void buf_cheri_capability_gdb_to_target(uint8_t *buffer, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	uint8_t tag = buffer[0];
	assert(tag == 0x0 || tag == 0x1);

	buffer[0] = buffer[1];
	buffer[1] = buffer[2];
	buffer[2] = buffer[3];
	buffer[3] = buffer[4];
	buffer[4] = buffer[5];
	buffer[5] = buffer[6];
	buffer[6] = buffer[7];
	buffer[7] = buffer[8];

	if (clen == 128) {
		buffer[8] = buffer[9];
		buffer[9] = buffer[10];
		buffer[10] = buffer[11];
		buffer[11] = buffer[12];
		buffer[12] = buffer[13];
		buffer[13] = buffer[14];
		buffer[14] = buffer[15];
		buffer[15] = buffer[16];
		buffer[16] = tag;
	} else {
		buffer[8] = tag;
	}
}

/**
 * Convert the bitwise layout of a CHERI capability:
 *   internal OpenOCD representation --> format for GDB
 *
 * Directly modifies the provided buffer.
 */
static inline void buf_cheri_capability_target_to_gdb(uint8_t *buffer, unsigned int clen)
{
	assert(clen == 64 || clen == 128);

	uint8_t tag;

	if (clen == 128) {
		tag = buffer[16];
		buffer[16] = buffer[15];
		buffer[15] = buffer[14];
		buffer[14] = buffer[13];
		buffer[13] = buffer[12];
		buffer[12] = buffer[11];
		buffer[11] = buffer[10];
		buffer[10] = buffer[9];
		buffer[9] = buffer[8];
	} else {
		tag = buffer[8];
	}

	assert(tag == 0x0 || tag == 0x1);
	buffer[8] = buffer[7];
	buffer[7] = buffer[6];
	buffer[6] = buffer[5];
	buffer[5] = buffer[4];
	buffer[4] = buffer[3];
	buffer[3] = buffer[2];
	buffer[2] = buffer[1];
	buffer[1] = buffer[0];
	buffer[0] = tag;
}

#endif /* OPENOCD_HELPER_CHERI_H */
