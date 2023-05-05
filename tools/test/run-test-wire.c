#include "config.h"
#include "test_gen.h"
#include "print_gen.h"

#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <stdio.h>
#include <wire/wire.h>


/* AUTOGENERATED MOCKS START */
/* Generated stub for fromwire_amount_msat */
struct amount_msat fromwire_amount_msat(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_amount_msat called!\n"); abort(); }
/* Generated stub for fromwire_tlv */
bool fromwire_tlv(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
		  const struct tlv_record_type *types UNNEEDED, size_t num_types UNNEEDED,
		  void *record UNNEEDED, struct tlv_field **fields UNNEEDED,
		  const u64 *extra_types UNNEEDED, size_t *err_off UNNEEDED, u64 *err_type UNNEEDED)
{ fprintf(stderr, "fromwire_tlv called!\n"); abort(); }
/* Generated stub for printwire_amount_msat */
bool printwire_amount_msat(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_amount_msat called!\n"); abort(); }
/* Generated stub for printwire_s16 */
bool printwire_s16(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_s16 called!\n"); abort(); }
/* Generated stub for printwire_s32 */
bool printwire_s32(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_s32 called!\n"); abort(); }
/* Generated stub for printwire_s64 */
bool printwire_s64(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_s64 called!\n"); abort(); }
/* Generated stub for printwire_s8 */
bool printwire_s8(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_s8 called!\n"); abort(); }
/* Generated stub for printwire_tlvs */
bool printwire_tlvs(const char *tlv_name UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED,
		    const struct tlv_print_record_type types[] UNNEEDED, size_t num_types UNNEEDED)
{ fprintf(stderr, "printwire_tlvs called!\n"); abort(); }
/* Generated stub for printwire_tu32 */
bool printwire_tu32(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_tu32 called!\n"); abort(); }
/* Generated stub for printwire_tu64 */
bool printwire_tu64(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_tu64 called!\n"); abort(); }
/* Generated stub for printwire_u16 */
bool printwire_u16(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_u16 called!\n"); abort(); }
/* Generated stub for printwire_u32 */
bool printwire_u32(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_u32 called!\n"); abort(); }
/* Generated stub for printwire_u64 */
bool printwire_u64(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED)
{ fprintf(stderr, "printwire_u64 called!\n"); abort(); }
/* Generated stub for printwire_u8_array */
bool printwire_u8_array(const char *fieldname UNNEEDED, const u8 **cursor UNNEEDED, size_t *plen UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "printwire_u8_array called!\n"); abort(); }
/* Generated stub for towire_amount_msat */
void towire_amount_msat(u8 **pptr UNNEEDED, const struct amount_msat msat UNNEEDED)
{ fprintf(stderr, "towire_amount_msat called!\n"); abort(); }
/* Generated stub for towire_tlv */
void towire_tlv(u8 **pptr UNNEEDED,
		const struct tlv_record_type *types UNNEEDED, size_t num_types UNNEEDED,
		const void *record UNNEEDED)
{ fprintf(stderr, "towire_tlv called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

#define COMPARE_VALS(type, len)					\
	for (size_t i = 0; i < ARRAY_SIZE(type##s); i++) {	\
		const u8 *ptr, *data = 				\
			tal_hexdata(ctx, type##s[i].hexstr,	\
				    strlen(type##s[i].hexstr)); \
		size_t max, size = tal_bytelen(data);		\
		assert(size == (len));				\
		max = size;					\
		ptr = data;					\
		type val = fromwire_##type(&ptr, &max);		\
		assert(max == 0);				\
		assert(val == type##s[i].val);			\
								\
		/* Check towire */				\
		u8 *wired = tal_arr(ctx, u8, 0);		\
		towire_##type(&wired, (type)type##s[i].val);	\
		assert(memeq(data, size, wired, tal_bytelen(wired)));	\
	}

static void test_signed_ints(void)
{
	/* Let's test some serializations */
	void *ctx = tal(NULL, char);
	struct test_case {
		s64 val;
		char *hexstr;
	} s8s[] = {
		{ .val = 0, .hexstr = "00" },
		{ .val = 42, .hexstr = "2a" },
		{ .val = -42, .hexstr = "d6" },
		{ .val = 127, .hexstr = "7f" },
		{ .val = -128, .hexstr = "80" },
	}, s16s[] = {
		{ .val = 128, .hexstr = "0080" },
		{ .val = -129, .hexstr = "ff7f" },
		{ .val = 15000, .hexstr = "3a98" },
		{ .val = -15000, .hexstr = "c568" },
		{ .val = 32767, .hexstr = "7fff" },
		{ .val = -32768, .hexstr = "8000" },
	}, s32s[] = {
		{ .val = 32768, .hexstr = "00008000" },
		{ .val = -32769, .hexstr = "ffff7fff" },
		{ .val = 21000000, .hexstr = "01406f40" },
		{ .val = -21000000, .hexstr = "febf90c0" },
		{ .val = 2147483647, .hexstr = "7fffffff" },
		{ .val = -2147483648, .hexstr = "80000000" },
	}, s64s[] = {
		{ .val = 2147483648, .hexstr = "0000000080000000" },
		{ .val = -2147483649, .hexstr = "ffffffff7fffffff" },
		{ .val = 500000000000, .hexstr = "000000746a528800" },
		{ .val = -500000000000, .hexstr = "ffffff8b95ad7800" },
		{ .val = 9223372036854775807, .hexstr = "7fffffffffffffff" },
		{ .val = -9223372036854775808ULL, .hexstr = "8000000000000000" },
	};

	COMPARE_VALS(s8, 1);
	COMPARE_VALS(s16, 2);
	COMPARE_VALS(s32, 4);
	COMPARE_VALS(s64, 8);

	tal_free(ctx);
}

int main(void)
{
	setup_locale();
	void *ctx = tal(NULL, char);

	struct tlv_test_n1 *n1 = tlv_test_n1_new(ctx);
	struct tlv_test_n2 *n2 = tlv_test_n2_new(ctx);
	struct tlv_test_n3 *n3 = tlv_test_n3_new(ctx);

	assert(n1);
	assert(n2);
	assert(n3);

	test_signed_ints();

	tal_free(ctx);
}
